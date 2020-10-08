from math import pi
import time

import odrive
from odrive.enums import *
from odrive.utils import dump_errors

from control.trayectory import *
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


def loop_trayectory(odrv, pos1=0, pos2=pi, t1=.3, t2=.4):

    odrv.axis0.requested_state = AXIS_STATE_STARTUP_SEQUENCE
    odrv.axis1.requested_state = AXIS_STATE_STARTUP_SEQUENCE
    cpr = odrv.axis0.encoder.config.cpr

    T_periodo = .001
    tray_outbound = pol_trayectory(t1, [pos1,pos2,0,0], T_periodo)
    tray_return = pol_trayectory(t2, [pos2,pos1,0,0] , T_periodo)

    tray_outbound_turns = [p/(2*pi) for p in tray_outbound]
    tray_return_turns = [p/(2*pi) for p in tray_return]

    odrv.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
    odrv.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
    odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
    odrv.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

    #start_liveplotter(lambda:[odrv0.axis0.encoder.pos_estimate, odrv0.axis0.controller.input_pos])

    try:
        while True:
            for p in tray_outbound_cprs:
                odrv.axis0.controller.input_pos = p
                odrv.axis1.controller.input_pos = p
                time.sleep(T_periodo)
            for p in tray_return_cprs:
                odrv.axis0.controller.input_pos = p
                odrv.axis1.controller.input_pos = p
                time.sleep(T_periodo)

    except KeyboardInterrupt:
        print("EXIT loop_trayectoria")
    return

def loop_two_setpoints(odrv, pos1=0, pos2=.5, t=.3):
    odrv.axis0.requested_state = AXIS_STATE_STARTUP_SEQUENCE
    odrv.axis1.requested_state = AXIS_STATE_STARTUP_SEQUENCE
    odrv.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
    odrv.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
    odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
    odrv.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

    try:
        while True:
            odrv.axis0.controller.input_pos = pos1
            odrv.axis1.controller.input_pos = pos1
            time.sleep(t)
            odrv.axis0.controller.input_pos = pos2
            odrv.axis1.controller.input_pos = pos2
            time.sleep(t)
    except KeyboardInterrupt:
        print("EXIT loop_two_setpoints")
    return

def idle(odrv):
    odrv.axis0.requested_state = 1
    odrv.axis1.requested_state = 1
    return "Setting both motors to idle"
