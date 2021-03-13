from math import pi
import time
from random import uniform as r_uni
from random import triangular as r_tri
from random import choice as r_choice
import pandas as pd
import numpy as np

import odrive
from odrive.enums import *

import robo
import configure
import plots
import ML
### EXECUTION TIME TOLERANCES
exec_tolerance = 12/100
reset_delays = 6
samples_error_test = 50
tolerance_fails = 0

### SAMPLING AND TRAJECTORY
T_input = .02 #seconds
traj = []

### VIBRATION TEST TOLERANCES ++ = MORE FLEXIBILITY
static_test_time = .25
static_num_points = 3
static_histeresis_tol = .025
static_fail_penalty = 1.5

### EVOLUTONARY PARAMETERS
max_generations = 10
inf_cycle = False

population = []
plot_group = []
pop_size = 10
elites = 2
survivors = 4
mutts = 6
mutt_rate = .15

### SAFETY LIMITS
k_range = ((20, 80), (.05, .25), (0, .5))
kp_frontier = [lambda kp: kp, lambda kp: max(-.0011*kp+k_range[1][1]-.05,k_range[1][0]+.00020*kp), lambda kp: 1.2]
def check_gains(proposed):
    approved = [20, .25, .4]
    for i,prop_g in enumerate(proposed):
        approved[i] = min( min( max(prop_g, k_range[i][0]), k_range[i][1]), kp_frontier[i](proposed[0]))
    return approved

def save_ML_data(gen_list, winner, traj_array, filename):
    with open(filename, 'r+') as master_file:
        oldData = json.load(json_file)
        now = time.localtime()
        newData = {
            "runID" : int(str(now.tm_year)+str(now.tm_mon)+str(now.tm_mday)
                         +str(now.tm_hour)+str(now.tm_min))
            "winner": winner,
            "traj": traj_array,
            "runs_data": gen_list
        }
        data = oldData.append(newData)
        json.dump(data, master_file, indent=4)
        
def evo_gains_ML(odrv, traj_array, save_file="master.json"):

    ML.start(odrv)
    global traj
    traj = traj_array


    class Individual:
        def __init__(self, generation, gains):
            self.generation = generation
            self.gains = {
                "Kp_pos": gains[0],
                "Kp_vel": gains[1],
                "Ki_vel": gains[2]
                }
            configure.gains(odrv, *gains)
            te0,te1,se0,se1,t_dat,s_dat = get_exec_errors_data(odrv, traj)
            self.errors = {
                "traj_error_a0" : te0,
                "traj_error_a1" : te2,
                "stat_error_a0" : se0,
                "stat_error_a1" : se1
                }
            self.score = te0+te2+se0+se1
            self.traj_data = t_dat
            self.stat_data = s_dat

    global population
    population = []
    global plot_group
    plot_group = []

    #Initiate population randomly
    print("*** Creating 0 generation ***")
    generation = 0
    for n in range(0, pop_size):
        kp = r_uni(k_range[0][0], k_range[0][1])
        kv = r_uni(k_range[1][0], k_range[1][1])+r_tri(0,.8,0.01)
        kvi = r_uni(k_range[2][0], k_range[2][1])
        population.append(Individual(0, check_gains([kp, kv, kvi])))

    plot_group.append(population[0])
    population.sort(key=lambda p: p.score)
    print_results(population)
    historic = [[p.__dict__ for p in population]]

    improvs = 0
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
        historic.append([p.__dict__ for p in population])

        if (population[0] != win):
            win = population[0]
            improvs +=1
            if improvs == 2:
                plot_group.append(win)

    population.sort(key=lambda p: p.score)
    plot_group.append(population[0])
    plots.print_group_trajs(plot_group)

    save_ML_data(historic, population[0].__dict__, traj_array, 'master.json')
    return (population, plot_group)

def get_exec_errors_data(odrv, traj):
    time.sleep(.3-static_test_time)

    data = test_trajectory(odrv, traj, static_test_time)
    data["estado"] = ["Trayectoria"]*len(traj) + ["Estatico"]*len(data)-len(traj)
    t_data = {}
    s_data = {}
    for field in data:
        t_data[field] = data[field][:len(traj)]
        s_data[field] = data[field][len(traj):]
    traj_error_a0 = sum(np.square(np.subtract(t_data["input_pos"],t_data["pos_estimate_a0"])))
    traj_error_a1 = sum(np.square(np.subtract(t_data["input_pos"],t_data["pos_estimate_a1"])))
    stat_error_a0 = sum(np.square(np.subtract(s_data["input_pos"],s_data["pos_estimate_a0"])))
    stat_error_a1 = sum(np.square(np.subtract(s_data["input_pos"],s_data["pos_estimate_a1"])))

    return (traj_error_a0, traj_error_a1, stat_error_a0, stat_error_a1, t_data, s_data)


def test_trajectory(odrv, traj, static_test_time=.25):
    tot_time = T_input * len(traj)

    success = False
    while not success:
        pos_set_a0 = []
        pos_set_a1 = []
        pos_estimates_a0 = []
        pos_estimates_a1 = []
        Iq_set_a0 = []
        Iq_set_a1 = []
        Iq_measured_a0 = []
        Iq_measured_a1 = []

        odrv.axis0.controller.input_pos = traj[0][0]
        odrv.axis1.controller.input_pos = traj[0][1]
        pset_0 = traj[0][0]
        pset_1 = traj[0][1]
        time.sleep(T_input-ML.input_sleep_adjust)

        start = time.perf_counter()
        for p in traj:
            pos_set_a0.append(pset_0)
            pos_set_a1.append(pset_1)
            pos_estimates_a0.append(odrv.axis0.encoder.pos_estimate)
            pos_estimates_a1.append(odrv.axis1.encoder.pos_estimate)
            Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
            Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
            Iq_measured_a0.append(odrv.axis0.motor.current_control.Iq_measured)
            Iq_measured_a1.append(odrv.axis1.motor.current_control.Iq_measured)

            odrv.axis0.controller.input_pos = p[0]
            odrv.axis1.controller.input_pos = p[1]
            time.sleep(float(T_input-ML.input_sleep_adjust-ML.data_delay))

        end = time.perf_counter()
        exec_time = end-start
        #print("TRAYECTORY TIME = " + str(exec_time))
        if abs(exec_time-tot_time) < tot_time*exec_tolerance:
            success = True
        else:
            global tolerance_fails
            tolerance_fails += 1
            if tolerance_fails >= reset_delays:
                ML.update_time_errors(odrv, samples_error_test)
                tolerance_fails = 0
    #End While not Succes loop
    for _ in range(round(static_test_time/T_input)):
        pos_set_a0.append(pset_0)
        pos_set_a1.append(pset_1)
        pos_estimates_a0.append(odrv.axis0.encoder.pos_estimate)
        pos_estimates_a1.append(odrv.axis1.encoder.pos_estimate)
        Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
        Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
        Iq_measured_a0.append(odrv.axis0.motor.current_control.Iq_measured)
        Iq_measured_a1.append(odrv.axis1.motor.current_control.Iq_measured)
        time.sleep(float(T_input-ML.data_delay))

    return {
    "pos_set_a0":pos_set_a0,
    "pos_set_a1":pos_set_a1,
    "pos_estimates_a0":pos_estimate_a0,
    "pos_estimates_a1":pos_estimate_a1,
    "Iq_set_a0":Iq_set_a0,
    "Iq_set_a1":Iq_set_a1,
    "Iq_measured_a0":Iq_measured_a0,
    "Iq_measured_a1":Iq_measured_a1,
    }


def cross_parents(p1, p2):
    cross_rate = r_uni(0,(1+mutt_rate))
    ch_gains = np.add([g1*cross_rate for g1 in p1.gains],[g2*(1-cross_rate) for g2 in p2.gains])
    return check_gains(ch_gains)

def create_mutt(origin):
    mutt_gains = [g*(1+r_uni(-mutt_rate,mutt_rate)) for g in origin.gains]
    return check_gains(mutt_gains)

def print_results(pop):
    for i in pop:
        print(i.generation,round(i.score,5),[round(g,3) for g in i.gains], sep="   ")
        print(round(i.traj_error,5),round(i.stat_error,5), sep=" + ")
