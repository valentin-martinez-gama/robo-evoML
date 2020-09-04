"""
Calibracion de motores del Odrive
"""

import time

robo_drive = odrive.findany()

"""
Note: the rotor must be allowed to rotate without any biased load during startup. That means mass and weak friction loads are fine, but gravity or spring loads are not okay.
"""
"""
limiteCorriente = 10
robo_drive.axis0.motor.config.current_lim = limiteCorriente
robo_drive.axis1.motor.config.current_lim = limiteCorriente
"""
defEncoder = robo_drive.axis0.encoder.config.cpr
gradosSequencia = 90/360*defEncoder

time.sleep(.2)

robo_drive.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
robo_drive.axis1.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE

time.sleep(.1)

robo_drive.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
robo_drive.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

robo_drive.axis0.controller.pos_setpoint = 0
robo_drive.axis1.controller.pos_setpoint = 0

time.sleep(.3)

opcion = "n"

while opcion == ("y" or "n"):

    opcion = input("Quieres hacer sequencia de movimiento de prueba? y / exit")

    if opcion == "y":
        robo_drive.axis0.controller.pos_setpoint = gradosSequencia
        robo_drive.axis1.controller.pos_setpoint = gradosSequencia

        time.sleep(2.5)

        robo_drive.axis0.controller.pos_setpoint = 0
        robo_drive.axis1.controller.pos_setpoint = 0
