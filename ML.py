'''
Plataforma de entrenamiento para red neuronal a partir de evolución diferencial

    3.- La data que debe de recoger el robot:
        5 points - Err pos(respecto a Setpoint pasado)
        5 points - Err corriente

        x2 motores.
'''

'''
    Otros TO DOs:

    * Definir trajectoria independiente para cada motor

    PREGUNTAS

    Que cada motor evolucione sus propias gancias? Con scores (y papas) separados o con score suma?

    Cuanta importancia para el estatico vs Trayectoria?

'''

import time
from math import pi
import numpy as np
import matplotlib.pyplot as plt

import odrive
from odrive.enums import *
from odrive.utils import dump_errors

def ML_get_info_read_delay(odrv, iters=100):
    outbound = [i*(-.25)/(iters//2) for i in range(0, iters//2)]
    ret = list(outbound)
    ret.reverse()
    points = (outbound+ret)
    pos_set_a0 = []
    pos_set_a1 = []
    pos_estimates_a0 = []
    pos_estimates_a1 = []
    current_set_a0 = []
    current_set_a1 = []
    current_estimate_a0 = []
    current_estimate_a1 = []
    delays = []
    for p in points:
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(.01)
        start = time.perf_counter()
        pos_set_a0.append(p)
        pos_set_a1.append(p)
        pos_estimates_a0.append(odrv.axis0.encoder.pos_estimate)
        pos_estimates_a1.append(odrv.axis1.encoder.pos_estimate)
        current_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
        current_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
        current_estimate_a0.append(odrv.axis0.motor.current_control.Iq_measured)
        current_estimate_a1.append(odrv.axis1.motor.current_control.Iq_measured)
        end = time.perf_counter()
        delays.append(end-start)
    odrv.axis0.controller.input_pos = 0
    odrv.axis1.controller.input_pos = 0
    read_delay = sum(delays)/len(delays)
    print("ML read_info execution time is %0.5fms" % (read_delay*1000))
    return read_delay

from Odrive_control import timetest
timetest.get_info_read_delay = ML_get_info_read_delay

def ML_update_time_errors(odrv, samples=100):
    time.sleep(.1)
    print("Adjusting update time errors")
    global ML_input_delay, ML_data_delay
    ML_input_delay = timetest.get_input_pos_delay(odrv, samples)
    ML_data_delay = timetst.get_info_read_delay(odrv, samples)
    return (ML_input_delay+ML_data_delay)*1000

from Odrive_control import robo
robo.update_time_errors = ML_update_time_errors

ML_input_delay = .0015
ML_data_delay = .0035
T = .02 #seconds

def ML_sleep(duration, get_now=time.perf_counter):
    now = get_now()
    end = now + duration
    while now < end:
        now = get_now()


def ML_trajectory(pos1=0, pos2=pi, t=.5):
    traj_data = robo.trajectory.build_trajectory(pos1, pos2, t1=t, t2=t, res = 2*t/.02)
    ML_traj = [[traj_data["OUTBOUND"][i], traj_data["OUTBOUND"][i]] for i in range(len(traj_data["OUTBOUND"]))] + [[traj_data["RETURN"][i], traj_data["RETURN"][i]] for i in range(len(traj_data["RETURN"]))]
    return ML_traj

def ML_print_group_trajs(chosen):
    time_axis = []
    accumulated_time = 0
    estimatess = []
    inputss = []
    errorss = []
    for indiv in chosen:
        time_axis.extend([t+accumulated_time for t in range(0,len(indiv.traj_data['pos_estimate_a1']+indiv.stat_data['pos_estimate_a1']))])
        accumulated_time = time_axis[-1]
        e = indiv.traj_data['pos_estimate_a1']+indiv.stat_data['pos_estimate_a1']
        estimatess.extend(e)
        i = indiv.traj_data['pos_set_a1']+indiv.stat_data['pos_set_a1']
        inputss.extend(i)
        errorss.extend(list(np.multiply(25,np.square(np.subtract(np.array(i),np.array(e))))))
    plt.plot(time_axis, estimatess)
    plt.plot(time_axis, inputss)
    plt.plot(time_axis, errorss)
    plt.xlabel("Muestreo")
    plt.ylabel("Posición")
    plt.legend(["Posición Actual", "Referencia", "Error"])
    plt.show()
