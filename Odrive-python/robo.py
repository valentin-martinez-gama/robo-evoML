from math import pi
import time
import odrive
from odrive.enums import *

from control.trayectoria import *
from setup import calibrar as cal
from setup import configurar as conf


def loop_trayectoria(odrv, pos1=0, pos2=pi, t1=.2, t2=.2):

    odrv.axis0.requested_state = AXIS_STATE_STARTUP_SEQUENCE
    cpr = odrv.axis0.encoder.config.cpr

    T_periodo = .001
    tray_ida = trayectoria(t1, [pos1,pos2,0,0], T_periodo)
    tray_vuelta = trayectoria(t2, [pos2,pos1,0,0] , T_periodo)

    tray_ida_cprs = [p/(2*pi) * cpr for p in tray_ida]
    tray_vuelta_cprs = [p/(2*pi) * cpr for p in tray_vuelta]

    odrv.axis0.controller.config.control_mode = CTRL_MODE_POSITION_CONTROL
    odrv.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

    #start_liveplotter(lambda:[odrv0.axis0.encoder.pos_estimate, odrv0.axis0.controller.pos_setpoint])

    while(true):
        for p in tray_ida_cprs:
            odrv.axis0.controller.pos_setpoint = p
            time.sleep(T_periodo)
        for p in tray_vuelta_cprs:
            odrv.axis0.controller.pos_setpoint = p
            time.sleep(T_periodo)

    return
