import robo
from data import robo_pandas

from math import pi
import time

import odrive
from odrive.enums import *
from control.trajectory import *
from setup import calibrate
from setup import configure

def loop_data(odrv, kp_min=10, kp_max=40, iters=4, samples=10):
    robo.home(odrv)
    pos1=0
    pos2=pi
    t1=.3
    t2=.4
    T_periodo = .001
    tray_outbound = pol_trajectory(t1, [pos1,pos2,0,0], T_periodo)
    tray_return = pol_trajectory(t2, [pos2,pos1,0,0] , T_periodo)
    tray_outbound_turns = [p/(2*pi) for p in tray_outbound]
    tray_return_turns = [p/(2*pi) for p in tray_return]

    configure.set_position_control(odrv)
    odrv.axis0.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    odrv.axis1.controller.config.input_mode = INPUT_MODE_PASSTHROUGH
    time.sleep(.5)

    raw = robo_pandas.build_raw(samples)
    sample_interval = (len(tray_outbound)+len(tray_return))//samples

    for it in range(0,iters):
        configure.gains(odrv, gan_pos = kp_min + it*(kp_max-kp_min)/(iters), gan_vel = 160/1000, gan_int_vel = 0/1000)

        estimates = []
        inputs = []
        currents = []
        vels = []
        n=0
        for i, p in enumerate(tray_outbound_turns):
            odrv.axis0.controller.input_pos = p
            odrv.axis1.controller.input_pos = p
            time.sleep(T_periodo)

            if ((i-1)%sample_interval == sample_interval-1):
                inputs.append(p)
                estimates.append(odrv.axis0.encoder.pos_estimate)
                currents.append(odrv.axis0.motor.current_control.Iq_measured)
                vels.append(odrv.axis0.encoder.vel_estimate)

        for i, p in enumerate(tray_return_turns):
            odrv.axis0.controller.input_pos = p
            odrv.axis1.controller.input_pos = p
            time.sleep(T_periodo)

            if ((i+len(tray_outbound)-1)%sample_interval == sample_interval-1):
                inputs.append(p)
                estimates.append(odrv.axis0.encoder.pos_estimate)
                currents.append(odrv.axis0.motor.current_control.Iq_measured)
                vels.append(odrv.axis0.encoder.vel_estimate)

        raw = robo_pandas.add_raw(raw, it, odrv.axis0.controller.config.pos_gain, odrv.axis0.controller.config.vel_gain, odrv.axis0.controller.config.vel_integrator_gain,
        estimates, inputs, currents, vels)

    robo_pandas.csv_export(raw)
    clean = robo_pandas.clean_data(raw)
    robo_pandas.csv_export(clean)
    return "FIN trayectoria"
