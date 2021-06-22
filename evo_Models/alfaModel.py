import time
import json
import pandas as pd
import numpy as np
from random import uniform as r_uni
from random import choice as r_choice
import matplotlib.pyplot as plt

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
        self.update_time_errors()
        self.I_am()
        self.outer = self

    def I_am(self):
        print("I am Alpha")
        self.am = 'AlphaAF'
    plot = False
    # EXECUTION TIME TOLERANCES
    update_interval = 10
    EXEC_TOLERANCE = 10/100
    RESET_DELAYS = 6
    SAMPLES_ERROR_TEST = 50
    tolerance_fails = 0
    input_delay = .0015
    ML_input_delay = .0035
    delay_adjust = .75
    ML_adjust = 2.25 #1.05
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

    class Individual:
        def __init__(indiv, generation, gains, outer):
            indiv._outer = outer
            indiv.generation = generation
            indiv.gains = {
                "Kp_pos": gains[0],
                "Kp_vel": gains[1],
                "Ki_vel": gains[2]
            }
            configure.gains(outer.odrv, *gains)
            te0, te1, se0, se1 = indiv.get_training_errors_data()
            indiv.errors = {
                "traj_error_a0": te0,
                "traj_error_a1": te1,
                "stat_error_a0": se0,
                "stat_error_a1": se1
            }
            indiv.score = te0+te1+se0+se1
            indiv.build_data()

        def get_ML_errors_data(indiv):
            ML_model=indiv._outer.ML_model
            robo_sleep(.3-indiv._outer.STATIC_TEST_TIME)

            indiv._outer.run_ML_model_traj(ML_model, indiv._outer.traj)
            indiv._t_pos_set_a0 = indiv._outer._ML_pos_set_a0
            indiv._t_pos_set_a1 = indiv._outer._ML_pos_set_a1
            indiv._t_pos_estimate_a0 = indiv._outer._ML_pos_estimate_a0
            indiv._t_pos_estimate_a1 = indiv._outer._ML_pos_estimate_a1
            indiv._t_Iq_set_a0 = indiv._outer._ML_Iq_set_a0
            indiv._t_Iq_set_a1 = indiv._outer._ML_Iq_set_a1

            indiv._s_pos_set_a0 = []
            indiv._s_pos_set_a1 = []
            indiv._s_pos_estimate_a0 = []
            indiv._s_pos_estimate_a1 = []
            indiv._s_Iq_set_a0 = []
            indiv._s_Iq_set_a1 = []
            indiv.static_test()

            errs = indiv.calc_error()
            return errs

        def get_training_errors_data(indiv):
            robo_sleep(.3-indiv._outer.STATIC_TEST_TIME)

            indiv._t_pos_set_a0 = []
            indiv._t_pos_set_a1 = []
            indiv._t_pos_estimate_a0 = []
            indiv._t_pos_estimate_a1 = []
            indiv._t_Iq_set_a0 = []
            indiv._t_Iq_set_a1 = []

            indiv._s_pos_set_a0 = []
            indiv._s_pos_set_a1 = []
            indiv._s_pos_estimate_a0 = []
            indiv._s_pos_estimate_a1 = []
            indiv._s_Iq_set_a0 = []
            indiv._s_Iq_set_a1 = []

            indiv.traj_test()
            indiv.static_test()
            errs = indiv.calc_error()
            return errs

        def calc_error(indiv):
            traj_error_a0 = sum(
                np.abs(np.subtract(indiv._t_pos_set_a0, indiv._t_pos_estimate_a0)))
            traj_error_a1 = sum(
                np.abs(np.subtract(indiv._t_pos_set_a1, indiv._t_pos_estimate_a1)))
            stat_error_a0 = sum(
                np.abs(np.subtract(indiv._s_pos_set_a0, indiv._s_pos_estimate_a0)))
            stat_error_a1 = sum(
                np.abs(np.subtract(indiv._s_pos_set_a1, indiv._s_pos_estimate_a1)))
            return (traj_error_a0, traj_error_a1, stat_error_a0, stat_error_a1)

        def static_test(indiv):
            odrv = indiv._outer.odrv
            traj = indiv._outer.traj
            pset_0 = traj[0][0]
            pset_1 = traj[0][1]
            for _ in range(round(indiv._outer.STATIC_TEST_TIME/indiv._outer.T_INPUT)):
                indiv._s_pos_set_a0.append(pset_0)
                indiv._s_pos_set_a1.append(pset_1)
                indiv._s_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                indiv._s_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                indiv._s_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                indiv._s_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                robo_sleep(indiv._outer.T_INPUT-indiv._outer.data_delay *
                           indiv._outer.delay_adjust)

        def traj_test(indiv):
            traj = indiv._outer.traj
            odrv = indiv._outer.odrv
            tot_time = indiv._outer.T_INPUT*len(traj)
            success = False

            while not success:
                indiv._t_pos_set_a0 = []
                indiv._t_pos_set_a1 = []
                indiv._t_pos_estimate_a0 = []
                indiv._t_pos_estimate_a1 = []
                indiv._t_Iq_set_a0 = []
                indiv._t_Iq_set_a1 = []

                pset_0 = traj[0][0]
                pset_1 = traj[0][1]
                odrv.axis0.controller.input_pos = pset_0
                odrv.axis1.controller.input_pos = pset_1
                robo_sleep(indiv._outer.T_INPUT-indiv._outer.input_delay)

                start = time.perf_counter()
                for p in range(1, len(traj)):
                    indiv._t_pos_set_a0.append(traj[p-1][0])
                    indiv._t_pos_set_a1.append(traj[p-1][1])
                    indiv._t_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                    indiv._t_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                    indiv._t_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                    indiv._t_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)

                    odrv.axis0.controller.input_pos = traj[p][0]
                    odrv.axis1.controller.input_pos = traj[p][1]
                    robo_sleep(indiv._outer.T_INPUT -
                               (indiv._outer.input_delay+indiv._outer.data_delay) *
                               indiv._outerdelay_adjust)

                end = time.perf_counter()

                exec_time = end-start
                if abs(exec_time-tot_time) < tot_time*indiv._outer.EXEC_TOLERANCE:
                    success = True
                else:
                    print("ERROR EN TIMEPO = " + str(exec_time-tot_time))
                    indiv._outer.correct_delay_error(pset_0, pset_1)
            # End While not Succes loop

        def build_data(indiv):
            indiv.traj_data = {
                "pos_set_a0": indiv._t_pos_set_a0,
                "pos_set_a1": indiv._t_pos_set_a1,
                "pos_estimate_a0": indiv._t_pos_estimate_a0,
                "pos_estimate_a1": indiv._t_pos_estimate_a1,
                "Iq_set_a0": indiv._t_Iq_set_a0,
                "Iq_set_a1": indiv._t_Iq_set_a1,
            }
            indiv.stat_data = {
                "pos_set_a0": indiv._s_pos_set_a0,
                "pos_set_a1": indiv._s_pos_set_a1,
                "pos_estimate_a0": indiv._s_pos_estimate_a0,
                "pos_estimate_a1": indiv._s_pos_estimate_a1,
                "Iq_set_a0": indiv._s_Iq_set_a0,
                "Iq_set_a1": indiv._s_Iq_set_a1,
            }

        def export_dict(indiv):
            data = dict(indiv.__dict__)
            for item in indiv.__dict__:
                if item.startswith('_'):
                    del data[item]
            return data

    def correct_delay_error(self, t0, t1):
        self.tolerance_fails += 1
        if self.tolerance_fails >= self.RESET_DELAYS:
            self.update_time_errors()
            self.odrv.axis0.controller.input_pos = t0
            self.odrv.axis1.controller.input_pos = t1
            time.sleep(.2)
            self.tolerance_fails = 0

    def save_ML_data(self, historic_gen_list, winner):
        now = time.localtime()
        newData = {
            "runID": int(str(now.tm_year) + str(now.tm_mon) + str(now.tm_mday)
                         + str(now.tm_hour) + str(now.tm_min)),
            "winner": winner,
            "traj": self.traj_name,
            "runs_data": historic_gen_list
        }
        with open('Datasets/' + self.training_tag+'.json', 'a') as lean_file:
            json.dump(newData, lean_file)
            lean_file.write('\n')

    def build_ML_training_set(self, group_size=10):
        in_file = self.training_tag + '.json'
        out_file = self.training_tag + '.csv'
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
                        for s in range(0, len(calc_df)-(group_size-1), 3):
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

    def evo_gains_ML(self, traj_array, traj_name):
        self.traj_name = traj_name
        self.traj = traj_array
        k_limits = self.k_limits

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
            population.append(self.Individual(0, self.check_gains([kp, kv, kvi]), self.outer))

        plot_group.append(population[0])
        population.sort(key=lambda p: p.score)
        win = population[0]
        self.print_results(population)
        historic = [[p.export_dict() for p in population]]

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
                population.append(self.Individual(
                    generation, self.cross_parents(p1, p2), self.outer))
                n += 1
            for m in range(self.MUTTS):
                mutt = population[m]
                population.append(self.Individual(generation, self.create_mutt(mutt), self.outer))

            population.sort(key=lambda p: p.score)
            self.print_results(population)
            historic.append([p.export_dict() for p in population])

            if (population[0] != win):
                win = population[0]
                improvs += 1
                if improvs == 2:
                    plot_group.append(win)

        population.sort(key=lambda p: p.score)
        plot_group.append(population[0])

        if self.plot is True:
            self.print_group(plot_group)

        self.save_ML_data(historic, population[0].export_dict())
        return population[0].export_dict()

    def print_group(self, plot_group):
        ML.ML_print_indiv_group_trajs(plot_group)

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
                  for g in i.gains], sep="  ")
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

    def update_time_errors(self):
        samples = self.SAMPLES_ERROR_TEST
        robo_sleep(.1)
        print("Adjusting update time errors")
        self.input_delay = timetest.get_input_pos_delay(self.odrv, samples)
        self.data_delay = self.get_info_read_delay(self.odrv, samples)
        # self.configure_delay = timetest.get_configure_delay(self.odrv, samples)
        return (self.input_delay+self.data_delay)*1000

    def run_ML_model_traj(self, ML_model, traj):
        self.ML_model = ML_model
        tot_time = self.T_INPUT*len(traj)
        odrv = self.odrv
        success = False

        while not success:
            self._ML_pos_set_a0 = []
            self._ML_pos_set_a1 = []
            self._ML_pos_estimate_a0 = []
            self._ML_pos_estimate_a1 = []
            self._ML_Iq_set_a0 = []
            self._ML_Iq_set_a1 = []
            self._ML_pos_error_a0 = []
            self._ML_pos_error_a1 = []

            ref_counter = 0
            lp0 = traj[0][0]
            lp1 = traj[0][1]
            odrv.axis0.controller.input_pos = lp0
            odrv.axis1.controller.input_pos = lp1
            robo_sleep(self.T_INPUT-self.input_delay)

            start = delay_start = time.perf_counter()
            for p in traj:
                self._ML_pos_set_a0.append(lp0)
                self._ML_pos_set_a1.append(lp1)
                self._ML_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                self._ML_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                self._ML_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                self._ML_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                self._ML_pos_error_a0.append(self._ML_pos_set_a0[-1]-self._ML_pos_estimate_a0[-1])
                self._ML_pos_error_a1.append(self._ML_pos_set_a1[-1]-self._ML_pos_estimate_a1[-1])
                ref_counter += 1

                if ref_counter % self.update_interval == 0:
                    self.do_model_predict()
                    delay_end = time.perf_counter()
                    robo_sleep(self.T_INPUT - (delay_end-delay_start)*self.ML_adjust)

                else:
                    delay_end = time.perf_counter()
                    robo_sleep(self.T_INPUT - (delay_end-delay_start)*self.ML_adjust)

                delay_start = time.perf_counter() ######

                odrv.axis0.controller.input_pos = lp0 = p[0]
                odrv.axis1.controller.input_pos = lp1 = p[1]

            end = time.perf_counter()
            exec_time = end-start
            if abs(exec_time-tot_time) < tot_time*self.EXEC_TOLERANCE:
                success = True
            else:
                print("ERROR EN TIMEPO = " + str(exec_time-tot_time))
                self.correct_delay_error(lp0, lp1)

    def do_model_predict(self):
        self.X_val = np.matrix([self._ML_pos_error_a0[-10:]
                                + self._ML_pos_error_a1[-10:]
                                + self._ML_Iq_set_a0[-10:]
                                + self._ML_Iq_set_a1[-10:]])

        self.results = ML_model.predict(self.X_val)
        configure.gains(odrv, self.results[0][0],
                        self.results[0][1]/10, self.results[0][2]/10)

    def ML_model_exec_plot(self):
        time_axis = range(0, len(self._ML_pos_set_a0)*2)
        plt.plot(time_axis, self._ML_pos_estimate_a0+self._ML_pos_estimate_a1)
        plt.plot(time_axis, self._ML_pos_set_a0+self._ML_pos_set_a1)
        plt.plot(time_axis, np.multiply(15, np.abs(self._ML_pos_error_a0+self._ML_pos_error_a1)))
        plt.xlabel("Muestreo")
        plt.ylabel("Posición")
        plt.legend(["Posición Actual", "Referencia", "Error (Abs)"])
        plt.show()
