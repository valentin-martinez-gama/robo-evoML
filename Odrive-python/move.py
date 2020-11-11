from math import sqrt
import time

import odrive
from odrive.enums import *

import configure
import trajectory
import robo
sleep_error = .00086
input_delay = .00124
data_delay = .0021
input_sleep_adjust = sleep_error+input_delay

def sleep_adjust():
    global sleep_error, input_delay, data_delay, input_sleep_adjust
    sleep_error = robo.sleep_error
    input_delay = robo.input_delay
    data_delay = robo.data_delay
    input_sleep_adjust = robo.input_sleep_adjust

def home(odrv):
    odrv.axis0.controller.input_pos = 0
    odrv.axis1.controller.input_pos = 0
    return "HOME"

def trajectory(odrv, loop = False, trajectory=trajectory.build_trajectory()):

    configure.set_position_control(odrv)

    for p in trajectory["OUTBOUND"]:
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(-input_sleep_adjust+trajectory["OUT_PERIOD"])
    for p in trajectory["RETURN"]:
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(-input_sleep_adjust+trajectory["RET_PERIOD"])

    if loop == True:
        try:
            while True:
                for p in trajectory["OUTBOUND"]:
                    odrv.axis0.controller.input_pos = p
                    odrv.axis1.controller.input_pos = p
                    time.sleep(-input_sleep_adjust+trajectory["OUT_PERIOD"])
                for p in trajectory["RETURN"]:
                    odrv.axis0.controller.input_pos = p
                    odrv.axis1.controller.input_pos = p
                    time.sleep(-input_sleep_adjust+trajectory["RET_PERIOD"])
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
    time_midpos_acc = sqrt((pos2-pos1)/2*2/a)

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
    odrv.axis0.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    odrv.axis1.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    return"FIN Trapezoide"

def hard(odrv, loop=False, pos1=0, pos2=.5, time_switch=.1):
    configure.set_position_control(odrv)

    odrv.axis0.controller.input_pos = pos1
    odrv.axis1.controller.input_pos = pos1
    time.sleep(-input_sleep_adjust+time_switch)
    odrv.axis0.controller.input_pos = pos2
    odrv.axis1.controller.input_pos = pos2
    time.sleep(-input_sleep_adjust+time_switch)
    odrv.axis0.controller.input_pos = pos1
    odrv.axis1.controller.input_pos = pos1
    time.sleep(-input_sleep_adjust+time_switch)

    if loop == True:
        try:
            while True:
                odrv.axis0.controller.input_pos = pos2
                odrv.axis1.controller.input_pos = pos2
                time.sleep(-input_sleep_adjust+time_switch)
                odrv.axis0.controller.input_pos = pos1
                odrv.axis1.controller.input_pos = pos1
                time.sleep(-input_sleep_adjust+time_switch)
        except KeyboardInterrupt:
            odrv.axis0.controller.input_pos = pos1
            odrv.axis1.controller.input_pos = pos1

            print("EXIT loop_two_setpoints")
    return"FIN Hard Setpoints"
