"""
Este programa se debe de correr cuando se conecta a una instancia nueva del Odrive o es necesario reconfigurarlo.
"""

breakResistance = 1
polePairs = 16
encoderCPR = 8192

limiteCorriente = 10
limiteVelocidad = encoderCPR/4
watchdogTimeout = .2 #s acepta floats?

robo_drive = odrive.findany()

robo_drive.config.brake_resistance = breakResistance

robo_drive.axis0.motor.config.pole_pairs = polePairs
robo_drive.axis1.motor.config.pole_pairs = polePairs

robo_drive.axis0.encoder.config.cpr = encoderCPR
robo_drive.axis1.encoder.config.cpr = encoderCPR

robo_drive.axis0.motor.config.motor_type = MOTOR_TYPE_HIGH_CURRENT
robo_drive.axis1.motor.config.motor_type = MOTOR_TYPE_HIGH_CURRENT


if limiteCorriente <= 60:
    robo_drive.axis0.motor.config.current_lim = limiteCorriente
    robo_drive.axis1.motor.config.current_lim = limiteCorriente

else:
    robo_drive.axis0.motor.config.request_current_range = limiteCorriente
    robo_drive.axis1.motor.config.request_current_range = limiteCorriente

robo_drive.axis0.motor.config.vel_limit = limiteVelocidad
robo_drive.axis1.motor.config.vel_limit = limiteVelocidad

robo_drive.axiso.config.watchdog_timeout = watchdogTimeout
robo_drive.axiso.config.watchdog_timeout = watchdogTimeout

robo_drive.save_configuration()
robo_drive.reboot() #No se ve a necesitar con el siguiente firmware release





"""
Otras funciones

odrivetool restore-config robo_config.json
"""
