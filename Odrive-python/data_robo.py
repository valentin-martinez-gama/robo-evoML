import robo
from data import robo_pandas
from control import trajectory

from math import pi
import time
import pandas as pd

import odrive
from odrive.enums import *
from control.trajectory import *
from setup import calibrate
from setup import configure

def gains_iterator(odrv, kp_min=5, kp_max=100, kv_min=100/1000, kv_max=400/1000, ki_min=0, ki_max=1500/1000, iters=5):
    opt_data = pd.DataFrame()
    # Make sure samples < trj(res)
    traj = trajectory.build_trajectory(pos1=0, pos2=pi, t1=.2, t2=.2, res=24)

    for i1 in range(0,iters):
        kp = kp_min + i1*(kp_max-kp_min)/(iters)

        for i2 in range(0,iters):
            kv = kv_min + i2*(kv_max-kv_min)/(iters)

            for i3 in range(0,iters):
                ki = ki_min + i3*(ki_max-ki_min)/(iters)

                configure.gains(odrv, gan_pos=kp, gan_vel=kv, gan_int_vel=ki)
                time.sleep(.1)

                traj_df = data_traj(odrv, traj, 1, 10)
                opt_data = opt_data.append(traj_df, ignore_index=True)
                #Hard_Step_DF?
                #Idle_DF?

    robo_pandas.csv_export(opt_data)


def data_traj(odrv, traj, iters=1, samples=40):
    robo.home(odrv)

    configure.set_position_control(odrv)
    odrv.axis0.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    odrv.axis1.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    time.sleep(.5)

    raw = robo_pandas.build_raw(samples)
    sample_interval = (len(traj["OUTBOUND"])+len(traj["RETURN"]))//samples

    for it in range(0,iters):
        estimates = []
        inputs = []
        currents = []
        vels = []

        for i, p in enumerate(traj["OUTBOUND"]):
            odrv.axis0.controller.input_pos = p
            odrv.axis1.controller.input_pos = p
            time.sleep(traj["OUT_PERIOD"])
            if ((i-1)%sample_interval == sample_interval-1):
                inputs.append(p)
                estimates.append(odrv.axis0.encoder.pos_estimate)
                currents.append(odrv.axis0.motor.current_control.Iq_measured)
                vels.append(odrv.axis0.encoder.vel_estimate)

        for i, p in enumerate(traj["RETURN"]):
            odrv.axis0.controller.input_pos = p
            odrv.axis1.controller.input_pos = p
            time.sleep(traj["RET_PERIOD"])
            if ((i-1+len(traj["OUTBOUND"]))%sample_interval == sample_interval-1):
                inputs.append(p)
                estimates.append(odrv.axis0.encoder.pos_estimate)
                currents.append(odrv.axis0.motor.current_control.Iq_measured)
                vels.append(odrv.axis0.encoder.vel_estimate)

        raw = robo_pandas.add_raw(raw, it, odrv.axis0.controller.config.pos_gain, odrv.axis0.controller.config.vel_gain, odrv.axis0.controller.config.vel_integrator_gain,
        estimates, inputs, currents, vels)

    clean = robo_pandas.clean_data(raw)
    #robo_pandas.csv_export(clean)
    return clean
