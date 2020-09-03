"""
Calibracion de motores del Odrive
"""

import time

robo_drive = odrive.findany()

"""
Note: the rotor must be allowed to rotate without any biased load during startup. That means mass and weak friction loads are fine, but gravity or spring loads are not okay.
"""

robo_drive.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
robo_drive.axis1.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE


robo_drive.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
robo_drive.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

time.sleep(2)

robo_drive.axis0.controller.pos_setpoint = 8192/4
robo_drive.axis1.controller.pos_setpoint = 8192/4

time.sleep(2.5)

robo_drive.axis0.controller.pos_setpoint = 0
robo_drive.axis1.controller.pos_setpoint = 0
