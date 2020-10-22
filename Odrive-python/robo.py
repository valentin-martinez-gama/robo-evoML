import math
import time

import odrive
from odrive.enums import *
from odrive.utils import dump_errors
from odrive.utils import start_liveplotter

import control.trajectory as tj
from setup import calibrate
from setup import configure
from setup.calibrate import wait_for_idle

def start(odrv):

    if (odrv.axis0.encoder.config.pre_calibrated and odrv.axis1.encoder.config.pre_calibrated) != 1:
        print("System not calibrated - proceeding to calibration based on index search")
        dump_errors(odrv, True)
        first_time_calibration(odrv)

    calibrate.set_encoder_zero(odrv)
    time.sleep(1)

    configure.currents(odrv)
    configure.velocity_limit(odrv)
    configure.gains(odrv, gan_pos=25, gan_vel= 250/1000.0, gan_int_vel = 400/1000.0)
    configure.trap_traj(odrv, vel_lim = 6, accel_lim = 48)

    return "DONE start robo"

def first_time_calibration(odrv):

    configure.hardware(odrv)
    configure.currents(odrv)
    configure.velocity_limit(odrv)
    configure.gains(odrv)
    time.sleep(.5)

    calibrate.motor_encoder_initial(odrv.axis0)
    time.sleep(2)
    calibrate.motor_encoder_initial(odrv.axis1)
    time.sleep(2)

    configure.export_config(odrv, "roboInicial.json")
    odrv.save_configuration()

    return print("DONE with initalization - Current State - Control Pos 3000")


def trajectory(odrv, loop = False, trajectory=tj.build_trajectory()):

    configure.set_position_control(odrv)
    odrv.axis0.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    odrv.axis1.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    time.sleep(.5)

    for p in trajectory["OUTBOUND"]:
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(trajectory["OUT_PERIOD"])
    for p in trajectory["RETURN"]:
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(trajectory["RET_PERIOD"])

    if loop == True:
        try:
            while True:
                for p in trajectory["OUTBOUND"]:
                    odrv.axis0.controller.input_pos = p
                    odrv.axis1.controller.input_pos = p
                    time.sleep(trajectory["OUT_PERIOD"])
                for p in trajectory["RETURN"]:
                    odrv.axis0.controller.input_pos = p
                    odrv.axis1.controller.input_pos = p
                    time.sleep(trajectory["RET_PERIOD"])
        except KeyboardInterrupt:
            print("EXIT loop_trajectory")

    return "FIN trayectoria"

def trapezoidal(odrv, loop=False, vel_lim=2, accel_lim=48, pos1=0, pos2=.5, t_inter=.1):

    configure.set_position_control(odrv)
    odrv.axis0.controller.config.input_mode = INPUT_MODE_TRAP_TRAJ
    odrv.axis1.controller.config.input_mode = INPUT_MODE_TRAP_TRAJ
    configure.trap_traj(odrv, vel_lim, accel_lim)

    a = odrv.axis0.trap_traj.config.accel_limit
    vel_lim = odrv.axis0.trap_traj.config.vel_limit

    time_acc = vel_lim/a
    time_midpos_acc = math.sqrt((pos2-pos1)/2*2/a)

    if time_acc > time_midpos_acc:
        transit_time = time_midpos_acc*2
        print("TIME Accelerating = " + str(transit_time))
    else: # time_acc < time_midpos_acc
        dist_acc = 1/2*a*(time_acc**2)
        dist_cru = (pos2-pos1)-dist_acc*2
        transit_time = 2*time_acc + dist_cru/vel_lim
        print("TIME Crusing = " + str(transit_time))

    tot_time = float(transit_time + t_inter)
    print(tot_time)
    odrv.axis0.controller.input_pos = pos1
    odrv.axis1.controller.input_pos = pos1
    time.sleep(tot_time)
    odrv.axis0.controller.input_pos = pos2
    odrv.axis1.controller.input_pos = pos2
    time.sleep(tot_time)

    if loop == True:
        try:
            while True:
                odrv.axis0.controller.input_pos = pos1
                odrv.axis1.controller.input_pos = pos1
                time.sleep(tot_time)
                odrv.axis0.controller.input_pos = pos2
                odrv.axis1.controller.input_pos = pos2
                time.sleep(tot_time)
        except KeyboardInterrupt:
            print("EXIT loop_trapezoidal")

    odrv.axis0.controller.input_pos = pos1
    odrv.axis1.controller.input_pos = pos1
    time.sleep(.5)
    odrv.axis0.controller.config.input_mode = 1
    odrv.axis1.controller.config.input_mode = 1
    return"FIN Trapezoide"

def hard(odrv, loop=False, pos1=0, pos2=.5, time_switch=.1):
    configure.set_position_control(odrv)
    odrv.axis0.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    odrv.axis1.controller.config.input_mode = INPUT_MODE_PASSTHROUGH

    odrv.axis0.controller.input_pos = pos1
    odrv.axis1.controller.input_pos = pos1
    time.sleep(time_switch)
    odrv.axis0.controller.input_pos = pos2
    odrv.axis1.controller.input_pos = pos2
    time.sleep(time_switch)
    odrv.axis0.controller.input_pos = pos1
    odrv.axis1.controller.input_pos = pos1
    time.sleep(time_switch)

    if loop == True:
        try:
            while True:
                odrv.axis0.controller.input_pos = pos2
                odrv.axis1.controller.input_pos = pos2
                time.sleep(time_switch)
                odrv.axis0.controller.input_pos = pos1
                odrv.axis1.controller.input_pos = pos1
                time.sleep(time_switch)
        except KeyboardInterrupt:
            odrv.axis0.controller.input_pos = pos1
            odrv.axis1.controller.input_pos = pos1

            print("EXIT loop_two_setpoints")
    return"FIN Hard Setpoints"

def idle(odrv):
    odrv.axis0.requested_state = 1
    odrv.axis1.requested_state = 1
    return "Setting both motors to idle"

def home(odrv):
    odrv.axis0.controller.input_pos = 0
    odrv.axis1.controller.input_pos = 0
    return "HOME"
