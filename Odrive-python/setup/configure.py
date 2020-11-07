import sys
import odrive
from odrive.enums import *
from odrive.configuration import backup_config
import logging

#odrv.axiso.config.watchdog_timeout = watchdogTimeout
breakResistance = .5
polePairs = 7
encoderCPR = 8192

def export_config(odrv, jsonName = "roboBase.json"):
    #logging.basicConfig(file="roboLogs.log",format='%(levelname)s:%(asctime)s:%(message)s',level=logging.DEBUG)
    theLog = logging.getLogger(__name__)
    backup_config(odrv, jsonName, theLog)


def hardware(odrv):
    odrv.config.brake_resistance = breakResistance
    odrv.axis0.motor.config.pole_pairs = polePairs
    odrv.axis1.motor.config.pole_pairs = polePairs
    odrv.axis0.encoder.config.cpr = encoderCPR
    odrv.axis1.encoder.config.cpr = encoderCPR
    odrv.axis0.encoder.config.use_index = True
    odrv.axis1.encoder.config.use_index = True
    odrv.axis0.motor.config.motor_type = MOTOR_TYPE_HIGH_CURRENT
    odrv.axis1.motor.config.motor_type = MOTOR_TYPE_HIGH_CURRENT
    odrv.axis0.motor.config.torque_constant = 8.27/270
    odrv.axis1.motor.config.torque_constant = 8.27/270
    return "DONE hardware"

def currents(odrv, limiteCorriente = 25, calibracion = 10):
    odrv.axis0.motor.config.calibration_current = calibracion
    odrv.axis1.motor.config.calibration_current = calibracion

    if limiteCorriente <= 60:
        odrv.axis0.motor.config.current_lim = limiteCorriente
        odrv.axis1.motor.config.current_lim = limiteCorriente
    else:
        odrv.axis0.motor.config.request_current_range = limiteCorriente
        odrv.axis1.motor.config.request_current_range = limiteCorriente
        odrv.save_configuration()
        print("Rebooting to set MOSFET currents >60")
        return odrv.reboot()
    return print("NEW current limits set")

def gains(odrv, gan_pos=25, gan_vel= 250/1000.0, gan_int_vel = 400/1000.0):
    odrv.axis0.controller.config.pos_gain = gan_pos #[(turns/s) / turns]
    odrv.axis0.controller.config.vel_gain = gan_vel #[Nm/(turns/s)]
    odrv.axis0.controller.config.vel_integrator_gain = gan_int_vel #[Nm/((turns/s) * s)]
    odrv.axis1.controller.config.pos_gain = gan_pos #[(turns/s) / turns]
    odrv.axis1.controller.config.vel_gain = gan_vel #[Nm/(turns/s)]
    odrv.axis1.controller.config.vel_integrator_gain = gan_int_vel #[Nm/((turns/s) * s)]
    return print("NEW gains set --> Kp: {} Kpv: {} Kiv: {}".format(gan_pos,gan_vel,gan_int_vel))

def trap_traj(odrv, vel_lim = 1, accel_lim = .5):
        odrv.axis0.trap_traj.config.vel_limit = vel_lim
        odrv.axis0.trap_traj.config.accel_limit = accel_lim
        odrv.axis0.trap_traj.config.decel_limit = accel_lim
        odrv.axis1.trap_traj.config.vel_limit = vel_lim
        odrv.axis1.trap_traj.config.accel_limit = accel_lim
        odrv.axis1.trap_traj.config.decel_limit = accel_lim
        return print("NEW trap_traj set")


def velocity_limit(odrv, limiteVelocidad = 14):
    odrv.axis0.controller.config.vel_limit = limiteVelocidad
    odrv.axis1.controller.config.vel_limit = limiteVelocidad
    return print("New velocity limits set")

def set_startup_procedure(odrv_axis, index_search = False, closed_control = False):
    odrv_axis.config.startup_encoder_index_search = index_search
    odrv_axis.config.startup_closed_loop_control = closed_control

def set_position_control(odrv):
        odrv.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
        odrv.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
        odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        odrv.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        return "SET set_position_control"
