import time

import odrive
from odrive.enums import *

from setup import calibrate
from setup import configure

def initialize(odrv):

    configure.hardware(odrv)
    configure.currents(odrv)
    configure.velocity_limit(odrv)
    configure.gains(odrv)
    time.sleep(.5)

    calibrate.motor_encoder_initial(odrv.axis0)
    time.sleep(1)
    calibrate.motor_encoder_initial(odrv.axis1)
    time.sleep(1)

    odrv.axis0.requested_state = AXIS_STATE_STARTUP_SEQUENCE
    odrv.axis1.requested_state = AXIS_STATE_STARTUP_SEQUENCE
    time.sleep(.3)

    odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
    odrv.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

    odrv.axis0.controller.config.control_mode = 3
    odrv.axis1.controller.config.control_mode = 3

    odrv.axis0.controller.pos_setpoint = 0
    odrv.axis1.controller.pos_setpoint = 0
    time.sleep(.4)
    odrv.axis0.controller.pos_setpoint = 2000
    odrv.axis1.controller.pos_setpoint = 2000
    time.sleep(.6)
    odrv.axis0.controller.pos_setpoint = 0
    odrv.axis1.controller.pos_setpoint = 0

    configure.export_config(odrv, "roboInicial.json")

    return "DONE with initalization - Current State - Control Pos 0"
