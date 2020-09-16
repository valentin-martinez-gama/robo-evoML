import sys
import odrive
from odrive.enums import *
from odrive.configuration import backup_config

#odrv.axiso.config.watchdog_timeout = watchdogTimeout
breakResistance = .5
polePairs = 7
encoderCPR = 8192

def export_config(odrv, jsonName = "roboBase.json"):
    logging.basicConfig(file="roboLogs.log",format='%(levelname)s:%(asctime)s:%(message)s',level=logging.DEBUG)
    theLog = logging.getLogger(__name__)
    backup_config(odrv, jsonName, theLog)


def hardware(odrv):
    odrv.config.brake_resistance = breakResistance
    odrv.axis0.motor.config.pole_pairs = polePairs
    odrv.axis1.motor.config.pole_pairs = polePairs
    odrv.axis0.encoder.config.cpr = encoderCPR
    odrv.axis1.encoder.config.cpr = encoderCPR
    odrv.axis0.motor.config.motor_type = MOTOR_TYPE_HIGH_CURRENT
    odrv.axis1.motor.config.motor_type = MOTOR_TYPE_HIGH_CURRENT
    return "DONE hardware"

def corrientes(odrv, limiteCorriente = 20, calibracion = 15):
    odrv.axis0.motor.config.calibration_current = calibracion
    odrv.axis1.motor.config.calibration_current = calibracion

    if limiteCorriente <= 60:
        odrv.axis0.motor.config.current_lim = limiteCorriente
        odrv.axis1.motor.config.current_lim = limiteCorriente
    else:
        odrv.axis0.motor.config.request_current_range = limiteCorriente
        odrv.axis1.motor.config.request_current_range = limiteCorriente
        odrv.save_configuration()
        print("Reiniciando para fijar corriente MOSFET >60")
        return odrv.reboot()
    return"Nuevas corrientes fijadas exitosamente"

def limite_velocidad(odrv, limiteVelocidad = encoderCPR*8):
    odrv.axis0.controller.config.vel_limit = limiteVelocidad
    odrv.axis1.controller.config.vel_limit = limiteVelocidad
