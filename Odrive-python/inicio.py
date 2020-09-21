import time

import odrive
from odrive.enums import *

from setup import calibrar
from setup import configurar

def inicilizar(odrv):

    configurar.hardware(odrv)
    configurar.corrientes(odrv)
    configurar.limite_velocidad(odrv)
    time.sleep(.5)

    calibrar.motor_encoder_inicial(odrv.axis0)
    time.sleep(1)
    calibrar.motor_encoder_inicial(odrv.axis1)
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
    time.sleep(.3)
    odrv.axis0.controller.pos_setpoint = 2000
    odrv.axis1.controller.pos_setpoint = 2000
    time.sleep(.7)
    odrv.axis0.controller.pos_setpoint = 0
    odrv.axis1.controller.pos_setpoint = 0

    configurar.export_config(odrv, "roboInicial.json")

    return "DONE incilizacion - Estado Actual - Control Pos 0"
