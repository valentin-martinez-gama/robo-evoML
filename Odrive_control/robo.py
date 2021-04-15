import time

import odrive
from odrive.enums import *
from odrive.utils import dump_errors

from . import calibrate
from . import configure
from . import move
from . import plots
from . import trajectory
from . import timetest
sleep_error = .0007
input_delay = .00124
data_delay = .0021
input_sleep_adjust = sleep_error+input_delay

def start(odrv):
    print("--------------------------------------")
    dump_errors(odrv,True)
    if (odrv.axis0.encoder.config.pre_calibrated and odrv.axis1.encoder.config.pre_calibrated) != 1:
        print("System not calibrated - proceeding to calibration based on index search")
        calibrate.first_time_calibration(odrv)

    configure.currents(odrv)
    configure.velocity_limit(odrv)
    configure.gains(odrv)
    configure.trap_traj(odrv, vel_lim = 1, accel_lim = 8)

    calibrate.set_encoder_zero(odrv)
    time.sleep(.2)
    update_time_errors(odrv)

    print("DONE start robo")
    print("--------------------------------------")
    print()

def update_time_errors(odrv, samples=100):
    time.sleep(.1)
    print("Adjusting update time errors")
    global sleep_error, input_delay, data_delay, input_sleep_adjust
    sleep_error = timetest.get_time_sleep_error()
    input_delay = timetest.get_input_pos_delay(odrv, samples)
    data_delay = timetest.get_info_read_delay(odrv, samples)
    input_sleep_adjust = sleep_error+input_delay
    return input_sleep_adjust

def idle(odrv):
    odrv.axis0.requested_state = 1
    odrv.axis1.requested_state = 1
    return "Setting both motors to idle"
