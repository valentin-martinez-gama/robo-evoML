from math import pi
import time
from random import uniform as r_uni
from random import triangular as r_tri
from random import choice as r_choice
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

import odrive
from odrive.enums import *

import robo
import calibrate
import configure
import trajectory
### EXECUTION TIME TOLERANCES
exec_tolerance = 7.5/100
reset_delays = 6
samples_error_test = 50
tolerance_fails = 0

### SAMPLING AND TRAJECTORY
samples_x_traj = 130
traj = 0
runs = 2

### VIBRATION TEST TOLERANCES ++ = MORE FLEXIBILITY
static_test_time = .4
static_num_points = 3
static_histeresis_tol = .025
static_fail_penalty = 1.5

### EVOLUTONARY PARAMETERS
max_generations = 10
inf_cycle = False

population = []
winners = []
pop_size = 10
elites = 2
survivors = 5
mutts = 2
mutt_rate = .1

### SAFETY LIMITS
k_range = ((10, 150), (.05, .25), (0, 1.2))
kp_frontier = [lambda kp: kp, lambda kp: -.001*kp+k_range[1][1]-.02, lambda kp: max(80,kp)/140]
def check_gains(proposed):
    approved = [20, .25, .4]
    for i,prop_g in enumerate(proposed):
        approved[i] = min( min( max(prop_g, k_range[i][0]), k_range[i][1]), kp_frontier[i](proposed[0]))
    return approved


def evo_gains(odrv):
    robo.start(odrv)
    global traj
    traj = trajectory.build_trajectory(pos1=0, pos2=pi, t1=0.75, t2=0.75, res=samples_x_traj)

    class Individual:
        def __init__(self, generation, gains):
            self.generation = generation
            self.gains = gains
            configure.gains(odrv, *gains)
            traj_err, stat_err, data = get_exec_errors_data(odrv, runs, traj, samples_x_traj)
            self.traj_error = traj_err
            self.stat_error = stat_err
            self.score = traj_err+stat_err
            self.data = data

    global population
    population = []
    global winners
    winners = []
    #Initiate population randomly
    print("*** Creating 0 generation ***")
    generation = 0
    for n in range(0, pop_size):
        kp = r_uni(20,140)
        #ASEGURAR QUE NO SE PASE LA FRONTERA DE PARETO DE VIBRACIONES VIOLENTAS
        kv = r_uni(.06,.2)+r_tri(0,.8,0.01)
        kvi = r_tri(0,1.4,.3)
        population.append(Individual(0, check_gains([kp, kv, kvi])))
    population.sort(key=lambda p: p.score)
    print_results(population)
    win = population[0]
    winners.append(win)

    while (generation < max_generations) or inf_cycle:
        generation += 1
        print('\n'+"*** Creating "+str(generation)+ " generation ***")
        parents = population[:survivors]
        del population[elites:]

        n = 0
        while len(population) < (pop_size - mutts):
            p1 = parents[n%survivors]
            p2 = r_choice(parents)
            population.append(Individual(generation, cross_parents(p1, p2)))
            n +=1
        for m in range(mutts):
            mutt = population[m]
            population.append(Individual(generation, create_mutt(mutt)))

        population.sort(key=lambda p: p.score)
        print_results(population)
        if (population[0] != win):
            win = population[0]
            winners.append(win)

    population.sort(key=lambda p: p.score)
    print_winners()
    return population

def cross_parents(p1, p2):

    cross_rate = r_uni(0,(1+mutt_rate))
    ch_gains = np.add([g1*cross_rate for g1 in p1.gains],[g2*(1-cross_rate) for g2 in p2.gains])

    return check_gains(ch_gains)

def create_mutt(origin):

    mutt_gains = [g*(1+r_uni(-mutt_rate,mutt_rate)) for g in origin.gains]

    return check_gains(mutt_gains)

def get_exec_errors_data(odrv, runs, traj, samples_x_traj):
    traj_errors = []
    stat_errors = []
    #vibs = []
    for _ in range(runs):
        data = test_trajectory(odrv, traj, static_test_time, samples_x_traj)
        t_data = {}
        s_data = {}
        for d in data:
            t_data[d] = data[d][:samples_x_traj]
            s_data[d] = data[d][samples_x_traj:]
        t_error = sum(np.square(np.subtract(t_data["input_pos"],t_data["pos_estimate_a0"]))) + sum(np.square(np.subtract(s_data["input_pos"],s_data["pos_estimate_a1"])))
        s_error = sum(np.square(np.subtract(data["input_pos"][samples_x_traj:],data["pos_estimate_a0"][samples_x_traj:]))) + sum(np.square(np.subtract(data["input_pos"][samples_x_traj:],data["pos_estimate_a1"][samples_x_traj:])))
        traj_errors.append(t_error)
        stat_errors.append(s_error)
        time.sleep(.5-static_test_time)
        #vibs.append(vibration_error(odrv))
    return (np.mean(traj_errors), np.mean(stat_errors), data)


def test_trajectory(odrv, traj, static_test_time=.25, samples_x_traj=0):
    if samples_x_traj == 0:
        sample_interval = 1
    else:
        sample_interval = (len(traj["OUTBOUND"])+len(traj["RETURN"]))//samples_x_traj

    tot_time = traj["OUT_PERIOD"]*len(traj["OUTBOUND"]) + traj["RET_PERIOD"]*len(traj["RETURN"])
    sample_diff = len(traj["OUTBOUND"])%sample_interval

    success = False
    while not success:
        inputs = []
        estimates_a0 = []
        estimates_a1 = []
        currents_a0 = []
        currents_a1 = []

        start = time.perf_counter()
        directions = (traj["OUTBOUND"], traj["RETURN"])
        for d_traj in directions:
            if d_traj== traj["OUTBOUND"]:
                T_time = traj["OUT_PERIOD"]
            else:
                T_time = traj["RET_PERIOD"]

            for i, p in enumerate(d_traj):
                odrv.axis0.controller.input_pos = p
                odrv.axis1.controller.input_pos = p
                if ((i-1)%sample_interval == sample_interval-1):
                    inputs.append(p)
                    estimates_a0.append(odrv.axis0.encoder.pos_estimate)
                    currents_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                    estimates_a1.append(odrv.axis1.encoder.pos_estimate)
                    currents_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                    time.sleep(float(T_time-robo.input_sleep_adjust-robo.data_delay))
                else:
                    time.sleep(float(T_time-robo.input_sleep_adjust))
        end = time.perf_counter()
        exec_time = end-start
        #print("TRAYECTORY TIME = " + str(exec_time))
        if abs(exec_time-tot_time) < tot_time*exec_tolerance:
            success = True
        else:
            global tolerance_fails
            tolerance_fails += 1
            if tolerance_fails >= reset_delays:
                robo.update_time_errors(odrv, samples_error_test)
                tolerance_fails = 0
    #End While not Succes loop
    for _ in range(round(static_test_time/T_time)):
        inputs.append(0)
        estimates_a0.append(odrv.axis0.encoder.pos_estimate)
        currents_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
        estimates_a1.append(odrv.axis1.encoder.pos_estimate)
        currents_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
        time.sleep(float(T_time-robo.data_delay))

    return {"input_pos":inputs,
    "pos_estimate_a0":estimates_a0,
    "pos_estimate_a1":estimates_a1,
    "Iq_setpoint_a0":currents_a0,
    "Iq_setpoint_a1":currents_a1}

""""
def vibration_error(odrv, vib_tol=vib_histeresis_tol, vib_test_time=test_time, rate=100):

    vibs = []
    tests = vib_num_points
    for i in range(0, round(rate*vib_test_time)):
        vibs.append(odrv.axis0.encoder.pos_estimate)
        vibs.append(odrv.axis1.encoder.pos_estimate)
        time.sleep(float(1/rate-robo.input_sleep_adjust))
    vibs.sort()
    histeresis = abs(np.mean(vibs[:tests]))+abs(np.mean(vibs[-tests:]))
    if histeresis > vib_tol:
        return histeresis*vib_fail_penalty
    else:
        return histeresis
"""
def print_results(pop):
    for i in pop:
        print(i.generation,round(i.score,5),[round(g,3) for g in i.gains], sep="   ")
        print(round(i.traj_error,5),round(i.stat_error,5), sep=" + ")
