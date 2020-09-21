import sys
import time

import odrive
from odrive.enums import *
from odrive.utils import dump_errors


def check_error(odrv_axis, message):
    if(odrv_axis.error != 0):
        print(dump_errors(odrv_axis))
        sys.exit(message)

def wait_for_idle(odrv_axis):
    while odrv_axis.current_state != AXIS_STATE_IDLE:
        time.sleep(0.1)
    return

def motor_encoder_inicial(odrv_axis):

    check_error(odrv_axis, "ERROR: error encontrado previo a inicilizar pre_calibracion.")

    #Calibracion del Motor
    if(odrv_axis.motor.config.pre_calibrated):
        print("Este motor ya esta precalibrado con phase_resistance y phase_inductance de:")
        print(odrv_axis.motor.config.phase_resistance)
        print(odrv_axis.motor.config.phase_inductance)

    else:
        print("Ejecutando AXIS_STATE_MOTOR_CALIBRATION")
        odrv_axis.requested_state = AXIS_STATE_MOTOR_CALIBRATION

        wait_for_idle(odrv_axis)
        check_error(odrv_axis,"ERROR: en AXIS_STATE_MOTOR_CALIBRATION")
        if(odrv_axis.motor.is_calibrated):
            odrv_axis.motor.config.pre_calibrated = True

            print("Motor calibrado exitosamente con phase_resistance y phase_inductance de:")
            print(odrv_axis.motor.config.phase_resistance)
            print(odrv_axis.motor.config.phase_inductance)
            print("Flag D1")
        else: return "WARNING .motor.is_calibrated = False"

    print("Calibracion del motor OK")


    #Calibracion del encoder
    if(odrv_axis.encoder.config.pre_calibrated):
        print("Encoder ya precalibrado con offset:")
        print(odrv_axis.encoder.config.offset)

    else:
        odrv_axis.encoder.config.use_index = True
        print("Buscando index AXIS_STATE_ENCODER_INDEX_SEARCH")
        odrv_axis.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH
        wait_for_idle(odrv_axis)
        check_error(odrv_axis,"ERROR: en AXIS_STATE_ENCODER_INDEX_SEARCH")

        print("Index encontrado")
        time.sleep(.5)

        print("Ejecutando AXIS_STATE_ENCODER_OFFSET_CALIBRATION")
        odrv_axis.requested_state = AXIS_STATE_ENCODER_OFFSET_CALIBRATION
        wait_for_idle(odrv_axis)
        check_error(odrv_axis,"ERROR: en AXIS_STATE_ENCODER_OFFSET_CALIBRATION")

        if(odrv_axis.encoder.is_ready):
            odrv_axis.encoder.config.pre_calibrated = True
            odrv_axis.config.startup_encoder_index_search = True

            print("Encoder calibrado exitosamente con offset")
            print(odrv_axis.encoder.config.offset)
        else: return "WARNING .encoder.is_ready = False"

    print("Calibracion del Encoder OK")

    print("Pruebas en funcionamiento")
    odrv_axis.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
    odrv_axis.controller.set_vel_setpoint(4000,0)
    time.sleep(3.5)
    odrv_axis.requested_state = AXIS_STATE_IDLE

    if(odrv_axis.error != 0):
        odrv_axis.encoder.config.pre_calibrated = False
        odrv_axis.config.startup_encoder_index_search = False
        odrv_axis.motor.config.pre_calibrated = False
    check_error(odrv_axis, "ERROR: en pruebas de set_vel_setpoint")

    return "DONE calibracion_motor_encoder"

    """
    A partir de ahora correr
    requested_State = AXIS_STATE_STARTUP_SEQUENCE
    para cada iniciacion
    """

def set_encoder_zero(odrv, axis0_offset=615, axis1_offset=420):
    

def test_posicion(odrv_axis, gradosSequencia = 30, odrv = 0):

    check_error(odrv_axis,"ERROR antes de inicilizar test_posicion")
    opcion = "n"
    while opcion == ("y" or "n"):

        odrv_axis.controller.config.control_mode = CTRL_MODE_POSITION_CONTROL
        odrv_axis.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

        opcion = input("Quieres hacer sequencia de movimiento de prueba? y / exit")
    #Probar en que type se almacena el input
        if opcion == "y":
            odrv_axis.controller.pos_setpoint = gradosSequencia/360*8192
            time.sleep(1.2)
            odrv_axis.controller.pos_setpoint = 0

    odrv_axis.requested_state = AXIS_STATE_IDLE

    return
