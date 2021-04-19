import time
import json
from random import uniform as r_uni
from random import triangular as r_tri
from random import choice as r_choice
import numpy as np

import odrive
from odrive.enums import *

from Odrive_control import configure
from Odrive_control.timetest import robo_sleep
import ML

# EXECUTION TIME TOLERANCES
EXEC_TOLERANCE = 10/100
RESET_DELAYS = 6
SAMPLES_ERROR_TEST = 50
TOLERANCE_FAILS = 0

# SAMPLING AND TRAJECTORY
T_INPUT = .02  # SECONDSW
TRAJ = []

# VIBRATION TEST TOLERANCES ++ = MORE FLEXIBILITY
STATIC_TEST_TIME = .25

# EVOLUTONARY PARAMETERS
MAX_GENERATIONS = 5
INF_CYCLE = False

population = []
plot_group = []
POP_SIZE = 8
ELITES = 1
SURVIVORS = 3
MUTTS = 5
MUTT_RATE = .15

K_RANGE = (20, 60)
# SAFETY LIMITS
k_limits = ((K_RANGE[0], K_RANGE[1]),
            (lambda kp: .052+.00020*kp, lambda kp: .48-.005*kp),
            (0, lambda kp, kv: (8+(kv/.052+.00020*kp)*3)*kv))
# lambda kp:.48-.005*kp


def check_gains(proposed):
    prop_kp, prop_kv, prop_kv_int = proposed
    kp = min(max(prop_kp, k_limits[0][0]), k_limits[0][1])
    kv = min(max(prop_kv, k_limits[1][0](kp)), k_limits[1][1](kp))
    kv_int = min(max(prop_kv_int, k_limits[2][0]), k_limits[2][1](kp, kv))
    return kp, kv, kv_int

# revisar si puede definir el folde en el que guardar los archivos en el nombre


def save_ML_data(gen_list, winner, traj_array, filename):
    now = time.localtime()
    newData = {
        "runID": int(str(now.tm_year) + str(now.tm_mon) + str(now.tm_mday)
                     + str(now.tm_hour) + str(now.tm_min)),
        "winner": winner,
        "traj": traj_array,
        "runs_data": gen_list
    }
    with open('Datasets/' + filename, 'a') as lean_file:
        json.dump(newData, lean_file)
        lean_file.write('\n')


def evo_gains_ML(odrv, traj_array=ML.ML_trajectory(), save_file="eg_Tst.json"):

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
            te0, te1, se0, se1, t_dat, s_dat = get_exec_errors_data(odrv, traj)
            self.errors = {
                "traj_error_a0": te0,
                "traj_error_a1": te1,
                "stat_error_a0": se0,
                "stat_error_a1": se1
            }
            self.score = te0+te1+se0+se1
            self.traj_data = t_dat
            self.stat_data = s_dat

    global population
    population = []
    global plot_group
    plot_group = []

    # Initiate population randomly
    print("*** Creating 0 generation ***")
    generation = 0
    for _ in range(0, POP_SIZE):
        kp = r_uni(K_RANGE[0], K_RANGE[1])
        kv = r_uni(k_limits[1][0](kp), k_limits[1][1](kp))
        kvi = r_uni(k_limits[2][0], k_limits[2][1](kp, kv))
        population.append(Individual(0, check_gains([kp, kv, kvi])))

    plot_group.append(population[0])
    population.sort(key=lambda p: p.score)
    win = population[0]
    print_results(population)
    historic = [[p.__dict__ for p in population]]

    improvs = 0
    while (generation < MAX_GENERATIONS) or INF_CYCLE:
        generation += 1
        print('\n'+"*** Creating "+str(generation) + " generation ***")
        parents = population[:SURVIVORS]
        del population[ELITES:]

        n = 0
        while len(population) < (POP_SIZE - MUTTS):
            p1 = parents[n % SURVIVORS]
            p2 = r_choice(parents)
            population.append(Individual(generation, cross_parents(p1, p2)))
            n += 1
        for m in range(MUTTS):
            mutt = population[m]
            population.append(Individual(generation, create_mutt(mutt)))

        population.sort(key=lambda p: p.score)
        print_results(population)
        historic.append([p.__dict__ for p in population])

        if (population[0] != win):
            win = population[0]
            improvs += 1
            if improvs == 2:
                plot_group.append(win)

    population.sort(key=lambda p: p.score)
    plot_group.append(population[0])

    #ML.ML_print_group_trajs(plot_group)
    save_ML_data(historic, population[0].__dict__, traj_array, save_file)
    return population[0].__dict__


def get_exec_errors_data(odrv, traj):
    robo_sleep(.3-STATIC_TEST_TIME)

    global g_data
    data = test_trajectory(odrv, traj, STATIC_TEST_TIME)
    g_data = data
    t_data = {}
    s_data = {}
    for field in data:
        t_data[field] = data[field][:len(traj)]
        s_data[field] = data[field][len(traj):]
    traj_error_a0 = sum(
        np.abs(np.subtract(t_data["pos_set_a0"], t_data["pos_estimate_a0"])))
    traj_error_a1 = sum(
        np.abs(np.subtract(t_data["pos_set_a1"], t_data["pos_estimate_a1"])))
    stat_error_a0 = sum(
        np.abs(np.subtract(s_data["pos_set_a0"], s_data["pos_estimate_a0"])))
    stat_error_a1 = sum(
        np.abs(np.subtract(s_data["pos_set_a1"], s_data["pos_estimate_a1"])))

    return (traj_error_a0, traj_error_a1, stat_error_a0, stat_error_a1,
            t_data, s_data)


def test_trajectory(odrv, traj, STATIC_TEST_TIME=.25):
    tot_time = T_INPUT*len(traj)

    success = False
    while not success:
        pos_set_a0 = []
        pos_set_a1 = []
        pos_estimate_a0 = []
        pos_estimate_a1 = []
        Iq_set_a0 = []
        Iq_set_a1 = []
        Iq_measured_a0 = []
        Iq_measured_a1 = []

        pset_0 = traj[0][0]
        pset_1 = traj[0][1]
        odrv.axis0.controller.input_pos = pset_0
        odrv.axis1.controller.input_pos = pset_1
        robo_sleep(T_INPUT-ML.ML_input_delay)

        start = time.perf_counter()
        for p in traj:
            pos_set_a0.append(p[0])
            pos_set_a1.append(p[1])
            pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
            pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
            Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
            Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
            Iq_measured_a0.append(odrv.axis0.motor.current_control.Iq_measured)
            Iq_measured_a1.append(odrv.axis1.motor.current_control.Iq_measured)

            odrv.axis0.controller.input_pos = p[0]
            odrv.axis1.controller.input_pos = p[1]

            robo_sleep(T_INPUT-(ML.ML_input_delay+ML.ML_data_delay)*.75)

        end = time.perf_counter()
        exec_time = end-start
        if abs(exec_time-tot_time) < tot_time*EXEC_TOLERANCE:
            success = True
        else:
            global TOLERANCE_FAILS
            TOLERANCE_FAILS += 1
            if TOLERANCE_FAILS >= RESET_DELAYS:
                print("ERROR EN TIMEPO = " + str(exec_time-tot_time))
                ML.ML_update_time_errors(odrv, SAMPLES_ERROR_TEST)
                odrv.axis0.controller.input_pos = traj[0][0]
                odrv.axis0.controller.input_pos = traj[1][0]
                time.sleep(.2)
                TOLERANCE_FAILS = 0
    # End While not Succes loop
    for _ in range(round(STATIC_TEST_TIME/T_INPUT)):
        pos_set_a0.append(pset_0)
        pos_set_a1.append(pset_1)
        pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
        pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
        Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
        Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
        Iq_measured_a0.append(odrv.axis0.motor.current_control.Iq_measured)
        Iq_measured_a1.append(odrv.axis1.motor.current_control.Iq_measured)
        robo_sleep(T_INPUT-ML.ML_data_delay*.75)

    return {
        "pos_set_a0": pos_set_a0,
        "pos_set_a1": pos_set_a1,
        "pos_estimate_a0": pos_estimate_a0,
        "pos_estimate_a1": pos_estimate_a1,
        "Iq_set_a0": Iq_set_a0,
        "Iq_set_a1": Iq_set_a1,
        "Iq_measured_a0": Iq_measured_a0,
        "Iq_measured_a1": Iq_measured_a1,
    }


def cross_parents(p1, p2):
    cross_rate = r_uni(0, (1+MUTT_RATE))
    ch_gains = np.add([p1.gains[g1]*cross_rate for g1 in p1.gains],
                      [p2.gains[g2]*(1-cross_rate) for g2 in p2.gains])
    return check_gains(ch_gains)


def create_mutt(origin):
    mutt_gains = [origin.gains[g]*(1+r_uni(-MUTT_RATE, MUTT_RATE))
                  for g in origin.gains]
    return check_gains(mutt_gains)


def print_results(pop):
    for i in pop:
        print(i.generation, round(i.score, 4), [round(i.gains[g], 3)
              for g in i.gains], sep="   ")
        print(round(i.errors["traj_error_a0"]+i.errors["traj_error_a1"], 5),
              round(i.errors["stat_error_a0"]+i.errors["stat_error_a1"], 5),
              sep=" + ")
