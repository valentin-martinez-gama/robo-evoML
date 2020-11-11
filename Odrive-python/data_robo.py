from math import pi
import time

import pandas as pd
import odrive
from odrive.enums import *

import robo
import setup.calibrate as calibrate
import setup.configure as configure
import data.timetest as timetest

### DESCONTAR EL TIMEPO X OPERACION EN CADA UNA

def evo_gains(odrv):

    robo.start(odrv0)

    traj = trajectory.build_trajectory(pos1=0, pos2=pi, t1=0.5, t2=0.5, res=100)

    evo_raw = robo_pandas.build_raw()

    performance_traj(odrv, traj, evo_raw, individual)

def performance_traj(odrv, traj, samples=0, raw):
    if samples == 0:
        sample_interval = 1
    else:
        sample_interval = (len(traj["OUTBOUND"])+len(traj["RETURN"]))//samples
    out_time = traj["OUT_PERIOD"]
    ret_time = traj["RET_PERIOD"]
    sample_diff = len(traj["OUTBOUND"])%sample_interval

    directions = (traj["OUTBOUND"], traj["RETURN"])
    for dtraj in directions:
        if d == traj["OUTBOUND"]:
            T_time = traj["OUT_PERIOD"]
        else:
            T_time = traj["RET_PERIOD"]

        inputs = []
        estimates_a0 = []
        estimates_a1 = []
        currents_a0 = []
        currents_a1 = []

        for i, p in enumerate(dtraj):
            odrv.axis0.controller.input_pos = p
            odrv.axis1.controller.input_pos = p
            if ((i-1)%sample_interval == sample_interval-1):
                inputs.append(p)
                estimates_a0.append(odrv.axis0.encoder.pos_estimate)
                currents_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                estimates_a1.append(odrv.axis1.encoder.pos_estimate)
                currents_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                time.sleep(T_time-robo.input_sleep_adjust-robo.data_delay)
            else:
                time.sleep(T_time-robo.input_sleep_adjust)

        raw = robo_pandas.add_raw(raw, id, odrv.axis0.controller.config.pos_gain, odrv.axis0.controller.config.vel_gain, odrv.axis0.controller.config.vel_integrator_gain,
        estimates, inputs, currents, vels)
        return raw

def gains_iterator(odrv, kp_min=80, kp_max=85, kv_min=100/1000, kv_max=400/1000, ki_min=0, ki_max=1500/1000, iters=2, samples=10):

    #Make sure samples < trj(res)
    data_traj_setup(odrv)
    raw = robo_pandas.build_raw()
    traj = trajectory.build_trajectory(pos1=0, pos2=pi, t1=0.5, t2=0.5, res=60)
    iteration =1

    for i1 in range(0,iters):
        kp = kp_min + i1*(kp_max-kp_min)/(iters)

        for i2 in range(0,iters):
            kv = kv_min + i2*(kv_max-kv_min)/(iters)

            for i3 in range(0,iters):
                ki = ki_min + i3*(ki_max-ki_min)/(iters)

                configure.gains(odrv, gan_pos=kp, gan_vel=kv, gan_int_vel=ki)
                time.sleep(.05)

                raw = data_traj(odrv, traj, samples, raw, iteration)
                #Hard_Step_DF?
                #Idle_DF?
                iteration += 1

    clean = robo_pandas.clean_data(raw)
    robo_pandas.csv_export(clean)
    top = robo_pandas.get_results(clean)
    print(top)
    return(clean, top)

def data_traj(odrv, traj, samples, raw, id=1):

    sample_interval = (len(traj["OUTBOUND"])+len(traj["RETURN"]))//samples
    out_time = traj["OUT_PERIOD"]
    ret_time = traj["RET_PERIOD"]
    sample_diff = len(traj["OUTBOUND"])%sample_interval

    estimates = []
    inputs = []
    currents = []
    vels = []

    for i, p in enumerate(traj["OUTBOUND"]):
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(out_time)
        if ((i-1)%sample_interval == sample_interval-1):
            inputs.append(p)
            estimates.append(odrv.axis0.encoder.pos_estimate)
            currents.append(odrv.axis0.motor.current_control.Iq_measured)
            vels.append(odrv.axis0.encoder.vel_estimate)

    for i, p in enumerate(traj["RETURN"]):
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(ret_time)
        if ((i-1+sample_diff)%sample_interval == sample_interval-1):
            inputs.append(p)
            estimates.append(odrv.axis0.encoder.pos_estimate)
            currents.append(odrv.axis0.motor.current_control.Iq_measured)
            vels.append(odrv.axis0.encoder.vel_estimate)

    raw = robo_pandas.add_raw(raw, id, odrv.axis0.controller.config.pos_gain, odrv.axis0.controller.config.vel_gain, odrv.axis0.controller.config.vel_integrator_gain,
    estimates, inputs, currents, vels)
    return raw

def data_traj_setup(odrv):
    robo.home(odrv)
    configure.set_position_control(odrv)
    time.sleep(.5)
