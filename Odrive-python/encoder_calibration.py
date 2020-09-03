"""
Hacer esta calibracion antes de montar y fijar motores y encoder
"""
import time
import sys
robo_drive = odrive.findany()

robo_drive.axis0.motor.config.calibration_current = 10 #Amps
robo_drive.axis1.motor.config.calibration_current = 10 #Amps

#El motor va a buscar el index del encoder
robo_drive.axis0.encoder.config.use_index = True
robo_drive.axis0.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH

#Calibracion de offset? Supongo que debe de salir 0 para todo
robo_drive.axis0.requested_state = AXIS_STATE_ENCODER_OFFSET_CALIBRATION

print(robo_drive.axis0.error)
print(robo_drive.axis0.encoder.config.offset)
print(robo_drive.axis0.motor.config.direction)

time.sleep(1)
#Motor en el axis 1
robo_drive.axis1.encoder.config.use_index = True
robo_drive.axis1.requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH

#Calibracion de offset? Supongo que debe de salir 0 para todo
robo_drive.axis1.requested_state = AXIS_STATE_ENCODER_OFFSET_CALIBRATION
print(robo_drive.axis1.error)
print(robo_drive.axis1.encoder.config.offset)
print(robo_drive.axis1.motor.config.direction)

if (robo_drive.axis0.error == 0) && (robo_drive.axis1.error == 0):

    robo_drive.axis0.encoder.config.pre_calibrated = True
    robo_drive.axis1.encoder.config.pre_calibrated = True
    #Para que siempre busque el index al arrancar
    robo_drive.axis0.config.startup_encoder_index_search = True
    robo_drive.axis1.config.startup_encoder_index_search = True

    robo_drive.save_configuration()
    robo_drive.reboot()

else:
    print("Error en al calibracion del encoder, volver a intentarlo")
    sys.exit()


robo_drive.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
robo_drive.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

robo_drive.axis0.controller.set_vel_setpoint(3000,0)
robo_drive.axis1.controller.set_vel_setpoint(3000,0)

time.sleep(3)

robo_drive.axis0.requested_state = AXIS_STATE_IDLE
robo_drive.axis1.requested_state = AXIS_STATE_IDLE

if (robo_drive.axis0.error == 0) && (robo_drive.axis1.error == 0):

    robo_drive.axis0.encoder.config.pre_calibrated = True
    robo_drive.axis1.encoder.config.pre_calibrated = True
    robo_drive.axis0.motor.config.pre_calibrated = True
    robo_drive.axis1.motor.config.pre_calibrated = True
    #Para que siempre busque el index al arrancar
    robo_drive.axis0.config.startup_encoder_index_search = True
    robo_drive.axis1.config.startup_encoder_index_search = True

    if (robo_drive.axis0.encoder.config.pre_calibrated && robo_drive.encoder.config.pre_calibrated) == 1:

        robo_drive.save_configuration()
        robo_drive.reboot()

        print("Encoders calibrados exitosamente y confiurados para ir a posicion de index siempre en el inicio")


"""
axis0Dir = -1
axis1Dir = -1

Reversing index search
Sometimes you would like the index search to only happen in a particular direction (the reverse of the default). Instead of swapping the motor leads, you can ensure that the following three values are negative:
try:
    robo_drive.axis0.config.calibration_lockin.vel *= axis0Dir
    robo_drive.axis0.config.calibration_lockin.accel *= axis0Dir
    robo_drive.axis0.config.calibration_lockin.ramp_distance *= axis0Dir

    robo_drive.axis1.config.calibration_lockin.vel *= axis1Dir
    robo_drive.axis1.config.calibration_lockin.accel *= axis1Dir
    robo_drive.axis1.config.calibration_lockin.ramp_distance *= axis1Dir
except:
    print("No se pudo modificar la direccion de los motores al inicio")
"""

"""
<axis>.motor.config.resistance_calib_max_voltage = 12.0 Max motor voltage used for measuring motor resistance. For motor calibration, it must be possible for the motor current to reach the calibration current without the applied voltage exceeding this config setting.

<axis>.controller.config.vel_limit = 50000 low values result in the spinning motor stopping abruptly during calibration
"""
