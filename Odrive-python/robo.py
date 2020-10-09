from math import pi
import time

import odrive
from odrive.enums import *
from odrive.utils import dump_errors
from odrive.utils import start_liveplotter

from control.trajectory import *
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


def loop_trajectory(odrv, loop = False, pos1=0, pos2=pi, t1=.3, t2=.4):

    T_periodo = .001
    tray_outbound = pol_trajectory(t1, [pos1,pos2,0,0], T_periodo)
    tray_return = pol_trajectory(t2, [pos2,pos1,0,0] , T_periodo)

    tray_outbound_turns = [p/(2*pi) for p in tray_outbound]
    tray_return_turns = [p/(2*pi) for p in tray_return]

    configure.set_position_control(odrv)
    odrv.axis0.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    odrv.axis1.controller.config.input_mode = INPUT_MODE_PASSTHROUGH

    time.sleep(.5)
    start_liveplotter(lambda:[odrv.axis0.encoder.pos_estimate, odrv.axis0.controller.input_pos])

    for p in tray_outbound_turns:
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(T_periodo)
    for p in tray_return_turns:
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(T_periodo)
    '''
    try:
        while True:
            for p in tray_outbound_turns:
                odrv.axis0.controller.input_pos = p
                odrv.axis1.controller.input_pos = p
                time.sleep(T_periodo)
            for p in tray_return_turns:
                odrv.axis0.controller.input_pos = p
                odrv.axis1.controller.input_pos = p
                time.sleep(T_periodo)
            if !loop:
                break
    except KeyboardInterrupt:
        print("EXIT loop_trayectoria")
    '''
    return "FIN trayectoria"

def loop_two_setpoints(odrv, vel_lim=2, accel_lim=48, pos1=0, pos2=.5, t_inter=.15):

    configure.set_position_control(odrv)
    odrv.axis0.controller.config.input_mode = INPUT_MODE_TRAP_TRAJ
    odrv.axis1.controller.config.input_mode = INPUT_MODE_TRAP_TRAJ

    configure.trap_traj(odrv, vel_lim, accel_lim)

    a = odrv.axis0.trap_traj.config.accel_limit
    vel_lim = odrv.axis0.trap_traj.config.vel_limit

    time_acc = vel_lim/a
    print("time_acc = " + str(time_acc))
    time_midpos_acc = sqrt((pos2-pos1)/2*2/a)
    print("time_midpos_acc = " + str(time_midpos_acc))
    dist_acc = 1/2*a*(time_acc**2)
    dist_cru = (pos2-pos1)-dist_acc*2

    if time_midpos_acc < time_acc:
        total_time = 2*time_midpos_acc
        print("TIME Acc")
    if time_midpos_acc > time_acc:
        total_time = 2*time_acc + dist_cru/vel_lim
        print("TIME Cru")

    #total_time = max(time_midpos_acc*2, 2*time_acc + dist_cru/vel_lim)
    print("TIME Accelerating = " + str(time_midpos_acc*2))
    print("TIME Crusing = " + str(2*time_acc + abs(dist_cru)/vel_lim))
    '''
    if time_acc > time_midpos_acc:
        total_time = time_midpos_acc*2
        print("TIME Accelerating = " + str(total_time))
    else: # time_acc < time_midpos_acc
        dist_acc = 1/2*a*(time_acc**2)
        dist_cru = (pos2-pos1)-dist_acc*2
        total_time = 2*time_acc + dist_cru/vel_lim
        print("TIME Crusing = " + str(total_time))
    '''
    try:
        while True:
            print("INPUT pos 1")
            odrv.axis0.controller.input_pos = pos1
            odrv.axis1.controller.input_pos = pos1
            time.sleep(total_time+t_inter)
            odrv.axis0.controller.input_pos = pos2
            odrv.axis1.controller.input_pos = pos2
            time.sleep(total_time+t_inter)
    except KeyboardInterrupt:
        odrv.axis0.controller.config.input_mode = 1
        odrv.axis1.controller.config.input_mode = 1
        print("EXIT loop_two_setpoints")
    return

def idle(odrv):
    odrv.axis0.requested_state = 1
    odrv.axis1.requested_state = 1
    return "Setting both motors to idle"
