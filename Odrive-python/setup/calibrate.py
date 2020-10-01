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


def motor_encoder_initial(odrv_axis):

    check_error(odrv_axis, "ERROR: error found before starting initial calibration.")

    # Motor Calibration
    if(odrv_axis.motor.config.pre_calibrated):
        print("This motor is precalibrated with phase_resistance = " + str(odrv_axis.motor.config.phase_resistance) + " and phase_inductance = " + str(odrv_axis.motor.config.phase_inductance))

    else:
        print("Executing AXIS_STATE_MOTOR_CALIBRATION")
        odrv_axis.requested_state = AXIS_STATE_MOTOR_CALIBRATION

        wait_for_idle(odrv_axis)
        check_error(odrv_axis,"ERROR: in AXIS_STATE_MOTOR_CALIBRATION")

        if(odrv_axis.motor.is_calibrated):
            odrv_axis.motor.config.pre_calibrated = True
            print("Motor calibrated succesfully with phase_resistance= " + str(odrv_axis.motor.config.phase_resistance) + " and phase_inductance = " + str(odrv_axis.motor.config.phase_inductance))
        else: return "WARNING .motor.is_calibrated = False."

    print("Motor calibration OK")


    # Encoder Calibration
    if(odrv_axis.encoder.config.pre_calibrated):
        print("Precalibrated encoder with offset = " + str(odrv_axis.encoder.config.offset))

    else:
        odrv_axis.encoder.config.use_index = True
        print("Searching for index AXIS_STATE_ENCODER_INDEX_SEARCH")
        odrv_axis.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH
        wait_for_idle(odrv_axis)
        check_error(odrv_axis,"ERROR: in AXIS_STATE_ENCODER_INDEX_SEARCH")

        print("Index found")
        time.sleep(.5)

        print("Executing AXIS_STATE_ENCODER_OFFSET_CALIBRATION")
        odrv_axis.requested_state = AXIS_STATE_ENCODER_OFFSET_CALIBRATION
        wait_for_idle(odrv_axis)
        check_error(odrv_axis,"ERROR: in AXIS_STATE_ENCODER_OFFSET_CALIBRATION")

        if(odrv_axis.encoder.is_ready):
            odrv_axis.encoder.config.pre_calibrated = True
            print("Succesfully calibrated encoder with offset = " + str(odrv_axis.encoder.config.offset))
        else: return "WARNING .encoder.is_ready = False"

    print("Encoder calibration OK")

    print("Movment test ...")
    odrv_axis.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
    odrv_axis.controller.move_to_pos(3000)
    time.sleep(1)
    odrv_axis.requested_state = AXIS_STATE_IDLE

    if(odrv_axis.error != 0):
        odrv_axis.encoder.config.pre_calibrated = False
        odrv_axis.config.startup_encoder_index_search = False
        odrv_axis.motor.config.pre_calibrated = False
    else:
        odrv_axis.config.startup_encoder_index_search = True
        odrv_axis.config.startup_closed_loop_control = True
    check_error(odrv_axis, "ERROR: after running set_vel_setpoint and turning the motor")

    return print("DONE motor_encoder_initial calibration")

    """
    From now on it os only needed to run
    requested_State = AXIS_STATE_STARTUP_SEQUENCE
    to start using the motor
    """


def set_encoder_zero(odrv, axis0_offset=460, axis1_offset=690):

    odrv.axis0.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH
    odrv.axis1.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH
    wait_for_idle(odrv.axis0)
    wait_for_idle(odrv.axis1)

    odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
    odrv.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
    odrv.axis0.controller.config.control_mode = CTRL_MODE_POSITION_CONTROL
    odrv.axis1.controller.config.control_mode = CTRL_MODE_POSITION_CONTROL
    odrv.axis0.controller.pos_setpoint = axis0_offset
    odrv.axis1.controller.pos_setpoint = axis1_offset
    time.sleep(.5)
    odrv.axis0.encoder.set_linear_count(0)
    odrv.axis1.encoder.set_linear_count(0)
    time.sleep(.5)
    odrv.axis0.controller.pos_setpoint = 0
    odrv.axis1.controller.pos_setpoint = 0
    return "DONE set encoder zero"


def test_position(odrv_axis, degreesMovment=30, odrv=0):

    check_error(odrv_axis,"ERROR before starting test_posicion")
    opcion = "n"
    while opcion == ("y" or "n"):

        odrv_axis.controller.config.control_mode = CTRL_MODE_POSITION_CONTROL
        odrv_axis.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

        opcion = input("Quieres hacer sequencia de movimiento de prueba? y / exit")
        if opcion == "y":
            odrv_axis.controller.pos_setpoint = degreesMovment/360 * odrv_axis.encoder.config.cpr
            time.sleep(1)
            odrv_axis.controller.pos_setpoint = 0
            time.sleep(1)

    odrv_axis.requested_state = AXIS_STATE_IDLE
    return "DONE test_position"
