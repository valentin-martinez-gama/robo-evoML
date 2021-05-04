import time
import json
import pandas as pd
import numpy as np
from random import uniform as r_uni
from random import triangular as r_tri
from random import choice as r_choice

from Odrive_control import configure
from Odrive_control.timetest import robo_sleep
from Odrive_control import timetest

import ML


def create_alfa_Model(odrv, training_tag):
    alfa_Model = evo_Model(odrv, training_tag)
    return alfa_Model


class evo_Model:
    '''Basic object representation of evo Model - allows to tune models '''
    def __init__(self, odrv, training_tag):
        self.odrv = odrv
        self.training_tag = training_tag
        ML.robo.start(odrv, time_error=False)
        self.update_time_errors(odrv)
        self.I_am()

    def I_am(self):
        print("I am Alpha")
    # EXECUTION TIME TOLERANCES
    EXEC_TOLERANCE = 10/100
    RESET_DELAYS = 6
    SAMPLES_ERROR_TEST = 50
    TOLERANCE_FAILS = 0
    input_delay = .0015
    ML_input_delay = .0035
    # SAMPLING AND TRAJECTORY
    T_INPUT = .02  # SECONDSW
    traj = []
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
    # SAFETY LIMITS
    K_RANGE = (20, 60)
    k_limits = ((K_RANGE[0], K_RANGE[1]),
                (lambda kp: .052+.00020*kp, lambda kp: .48-.005*kp),
                (0, lambda kp, kv: (8+(kv/.052+.00020*kp)*3)*kv))
    # lambda kp:.48-.005*kp

    def check_gains(self, proposed):
        prop_kp, prop_kv, prop_kv_int = proposed
        k_limits = self.k_limits
        kp = min(max(prop_kp, k_limits[0][0]), k_limits[0][1])
        kv = min(max(prop_kv, k_limits[1][0](kp)), k_limits[1][1](kp))
        kv_int = min(max(prop_kv_int, k_limits[2][0]), k_limits[2][1](kp, kv))
        return kp, kv, kv_int

    def test_trajectory(self):
        odrv = self.odrv
        traj = self.traj
        tot_time = self.T_INPUT*len(traj)

        success = False
        while not success:
            pos_set_a0 = []
            pos_set_a1 = []
            pos_estimate_a0 = []
            pos_estimate_a1 = []
            Iq_set_a0 = []
            Iq_set_a1 = []

            pset_0 = traj[0][0]
            pset_1 = traj[0][1]
            odrv.axis0.controller.input_pos = pset_0
            odrv.axis1.controller.input_pos = pset_1
            robo_sleep(self.T_INPUT-self.input_delay)

            start = time.perf_counter()
            for p in traj:
                pos_set_a0.append(p[0])
                pos_set_a1.append(p[1])
                pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)

                odrv.axis0.controller.input_pos = p[0]
                odrv.axis1.controller.input_pos = p[1]

                robo_sleep(self.T_INPUT-(self.input_delay+self.data_delay)*.75)

            end = time.perf_counter()
            exec_time = end-start
            if abs(exec_time-tot_time) < tot_time*self.EXEC_TOLERANCE:
                success = True
            else:
                self.TOLERANCE_FAILS += 1
                if self.TOLERANCE_FAILS >= self.RESET_DELAYS:
                    print("ERROR EN TIMEPO = " + str(exec_time-tot_time))
                    self.update_time_errors(odrv, self.SAMPLES_ERROR_TEST)
                    odrv.axis0.controller.input_pos = traj[0][0]
                    odrv.axis0.controller.input_pos = traj[1][0]
                    time.sleep(.2)
                    self.TOLERANCE_FAILS = 0
        # End While not Succes loop
        for _ in range(round(self.STATIC_TEST_TIME/self.T_INPUT)):
            pos_set_a0.append(pset_0)
            pos_set_a1.append(pset_1)
            pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
            pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
            Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
            Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
            robo_sleep(self.T_INPUT-self.data_delay*.75)

        return {
            "pos_set_a0": pos_set_a0,
            "pos_set_a1": pos_set_a1,
            "pos_estimate_a0": pos_estimate_a0,
            "pos_estimate_a1": pos_estimate_a1,
            "Iq_set_a0": Iq_set_a0,
            "Iq_set_a1": Iq_set_a1,
        }

    def get_exec_errors_data(self):
        traj = self.traj
        robo_sleep(.3-self.STATIC_TEST_TIME)

        data = self.test_trajectory()
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

    def save_ML_data(self, historic_gen_list, winner):
        now = time.localtime()
        newData = {
            "runID": int(str(now.tm_year) + str(now.tm_mon) + str(now.tm_mday)
                         + str(now.tm_hour) + str(now.tm_min)),
            "winner": winner,
            "traj": self.traj,
            "runs_data": historic_gen_list
        }
        with open('Datasets/' + self.training_tag+'.json', 'a') as lean_file:
            json.dump(newData, lean_file)
            lean_file.write('\n')

    def build_ML_training_set(in_file, out_file='out_file.csv', group_size=10):
        error_cols = [
            'pos_error_'+ax+'_n'+str(g) for ax in ['a0', 'a1']
            for g in range(group_size)]+['Iq_set_'+ax+'_n'+str(g)
            for ax in ['a0', 'a1'] for g in range(group_size)]

        k_in_cols = ['in_Kp_pos', 'in_Kp_vel', 'in_Ki_vel']
        k_out_cols = ['out_Kp_pos', 'out_Kp_vel', 'out_Ki_vel']

        master_ML_df = pd.DataFrame(columns=k_in_cols+error_cols+k_out_cols)

        data_dir = 'Datasets/'
        with open(data_dir+in_file, 'r') as json_file:
            for evolution in json_file:
                evo_df = pd.DataFrame(columns=error_cols+k_in_cols)
                evo_data = json.loads(evolution)

                for generation in evo_data['runs_data']:
                    for individual in generation:

                        base_df = pd.DataFrame(individual['traj_data'])
                        calc_df = pd.DataFrame()
                        calc_df['pos_error_a0'] = base_df['pos_set_a0'] - base_df['pos_estimate_a0']
                        calc_df['pos_error_a1'] = base_df['pos_set_a1'] - base_df['pos_estimate_a1']
                        calc_df['Iq_set_a0'] = base_df['Iq_set_a0']
                        calc_df['Iq_set_a1'] = base_df['Iq_set_a1']

                        train_set = []
                        for s in range(len(calc_df)-(group_size-1)):
                            train_set.append(calc_df[s:s+group_size].values.ravel('F'))

                        ind_df = pd.DataFrame(train_set, columns=error_cols)
                        ind_df['in_Kp_pos'] = individual['gains']["Kp_pos"]
                        ind_df['in_Kp_vel'] = individual['gains']["Kp_vel"]
                        ind_df['in_Ki_vel'] = individual['gains']["Ki_vel"]
                        evo_df = evo_df.append(ind_df)

                evo_df['out_Kp_pos'] = evo_data['winner']['gains']["Kp_pos"]
                evo_df['out_Kp_vel'] = evo_data['winner']['gains']["Kp_vel"]
                evo_df['out_Ki_vel'] = evo_data['winner']['gains']["Ki_vel"]
                master_ML_df = master_ML_df.append(evo_df)

        master_ML_df.to_csv(data_dir+out_file, index=False)

    def evo_gains_ML(self, traj_array):
        self.traj = traj_array
        odrv = self.odrv
        k_limits = self.k_limits

        outer = self
        class Individual:
            def __init__(self, generation, gains):
                self.generation = generation
                self.gains = {
                    "Kp_pos": gains[0],
                    "Kp_vel": gains[1],
                    "Ki_vel": gains[2]
                }
                configure.gains(odrv, *gains)
                te0, te1, se0, se1, t_dat, s_dat = outer.get_exec_errors_data()
                self.errors = {
                    "traj_error_a0": te0,
                    "traj_error_a1": te1,
                    "stat_error_a0": se0,
                    "stat_error_a1": se1
                }
                self.score = te0+te1+se0+se1
                self.traj_data = t_dat
                self.stat_data = s_dat

        self.plot_group = []
        self.population = []
        population = self.population
        plot_group = self.plot_group

        # Initiate population randomly
        print("*** Creating 0 generation ***")
        generation = 0
        for _ in range(0, self.POP_SIZE):
            kp = r_uni(self.K_RANGE[0], self.K_RANGE[1])
            kv = r_uni(k_limits[1][0](kp), k_limits[1][1](kp))
            kvi = r_uni(k_limits[2][0], k_limits[2][1](kp, kv))
            population.append(Individual(0, self.check_gains([kp, kv, kvi])))

        plot_group.append(population[0])
        population.sort(key=lambda p: p.score)
        win = population[0]
        self.print_results(population)
        historic = [[p.__dict__ for p in population]]

        improvs = 0
        while (generation < self.MAX_GENERATIONS) or self.INF_CYCLE:
            generation += 1
            print('\n'+"*** Creating "+str(generation) + " generation ***")
            parents = population[:self.SURVIVORS]
            del population[self.ELITES:]

            n = 0
            while len(population) < (self.POP_SIZE - self.MUTTS):
                p1 = parents[n % self.SURVIVORS]
                p2 = r_choice(parents)
                population.append(Individual(generation, self.cross_parents(p1, p2)))
                n += 1
            for m in range(self.MUTTS):
                mutt = population[m]
                population.append(Individual(generation, self.create_mutt(mutt)))

            population.sort(key=lambda p: p.score)
            self.print_results(population)
            historic.append([p.__dict__ for p in population])

            if (population[0] != win):
                win = population[0]
                improvs += 1
                if improvs == 2:
                    plot_group.append(win)

        population.sort(key=lambda p: p.score)
        plot_group.append(population[0])

        # ML.ML_print_group_trajs(plot_group)
        self.save_ML_data(historic, population[0].__dict__)
        return population[0].__dict__

    def cross_parents(self, p1, p2):
        cross_rate = r_uni(0, (1+self.MUTT_RATE))
        ch_gains = np.add([p1.gains[g1]*cross_rate for g1 in p1.gains],
                          [p2.gains[g2]*(1-cross_rate) for g2 in p2.gains])
        return self.check_gains(ch_gains)

    def create_mutt(self, origin):
        mutt_gains = [origin.gains[g]*(1+r_uni(-self.MUTT_RATE, self.MUTT_RATE))
                      for g in origin.gains]
        return self.check_gains(mutt_gains)

    def print_results(self, pop):
        for i in pop:
            print(i.generation, round(i.score, 4), [round(i.gains[g], 3)
                  for g in i.gains], sep="   ")
            print('  ', round(i.errors["traj_error_a0"]+i.errors["traj_error_a1"], 5),
                  round(i.errors["stat_error_a0"]+i.errors["stat_error_a1"], 5),
                  sep=" + ")

    def get_info_read_delay(self, odrv, iters=50):
        p_init_0 = odrv.axis0.encoder.pos_estimate
        p_init_1 = odrv.axis1.encoder.pos_estimate
        outbound = [i*(-.027)/(iters//2) for i in range(0, iters//2)]
        ret = list(outbound)
        ret.reverse()
        points = (outbound+ret)
        pos_set_a0 = []
        pos_set_a1 = []
        pos_estimates_a0 = []
        pos_estimates_a1 = []
        current_set_a0 = []
        current_set_a1 = []
        delays = []
        for p in points:
            odrv.axis0.controller.input_pos = p + p_init_0
            odrv.axis1.controller.input_pos = p + p_init_1
            robo_sleep(.02)
            start = time.perf_counter()
            pos_set_a0.append(p)
            pos_set_a1.append(p)
            pos_estimates_a0.append(odrv.axis0.encoder.pos_estimate)
            pos_estimates_a1.append(odrv.axis1.encoder.pos_estimate)
            current_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
            current_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
            end = time.perf_counter()
            delays.append(end-start)
        read_delay = sum(delays)/len(delays)
        print("Read_info execution time is %0.5fms" % (read_delay*1000))
        return read_delay

    def update_time_errors(self, odrv, samples=50):
        robo_sleep(.1)
        print("Adjusting update time errors")
        self.input_delay = timetest.get_input_pos_delay(odrv, samples)
        self.data_delay = self.get_info_read_delay(odrv, samples)
        return (self.input_delay+self.data_delay)*1000
