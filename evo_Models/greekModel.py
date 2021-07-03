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


class greek_Model:
    '''Basic object representation of evo Model - allows to tune models '''

    def __init__(self, odrv, training_tag):
        self.odrv = odrv
        self.training_tag = training_tag
        self.midpoints = 4
        ML.robo.start(odrv, time_error=False)
        self.I_am()
        self.outer = self

    def I_am(self):
        print("I am Greek")
        self.am = 'A greek motherfucker'
    plot = False
    # EXECUTION TIME TOLERANCES
    update_interval = 13
    EXEC_TOLERANCE = 20/100 #10/100
    RESET_DELAYS = 3
    SAMPLES_ERROR_TEST = 30
    tolerance_fails = 0
    # SAMPLING AND TRAJECTORY
    T_INPUT = .02  # SECONDSW
    traj = []
    # VIBRATION TEST TOLERANCES ++ = MORE FLEXIBILITY
    STATIC_TEST_TIME = .25
    # EVOLUTONARY PARAMETERS
    MAX_GENERATIONS = 8
    INF_CYCLE = False
    population = []
    plot_group = []
    POP_SIZE = 16
    ELITES = 3
    SURVIVORS = 8
    MUTTS = 9
    MUTT_RATE = .2
    # SAFETY LIMITS
    K_RANGE = (40, 90)
    k_limits = ((K_RANGE[0], K_RANGE[1]),
                (lambda kp: .052+.00020*kp, lambda kp: .48*1.2-.005*kp),
                (0, lambda kp, kv: 1.25-.0075*kp + kv*6))

    def check_gains(self, proposed):
        prop_kp, prop_kv, prop_kv_int = proposed
        k_limits = self.k_limits
        kp = min(max(prop_kp, k_limits[0][0]), k_limits[0][1])
        kv = min(max(prop_kv, k_limits[1][0](kp)), k_limits[1][1](kp))
        kv_int = min(max(prop_kv_int, k_limits[2][0]), k_limits[2][1](kp, kv))
        return kp, kv, kv_int

    class Individual:
        def __init__(indiv, generation, A0_gains, A1_gains, outer):
            indiv._outer = outer
            indiv.generation = generation
            indiv.gains = {
                "A0_Kp_pos": A0_gains[0],
                "A0_Kp_vel": A0_gains[1],
                "A0_Ki_vel": A0_gains[2],
                "A1_Kp_pos": A1_gains[0],
                "A1_Kp_vel": A1_gains[1],
                "A1_Ki_vel": A1_gains[2]
            }
            indiv._A0_gains = A0_gains
            indiv._A1_gains = A1_gains
            configure.independent_gains(outer.odrv, A0_gains, A1_gains)
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

            indiv._outer.run_ML_model_traj(ML_model)
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
                np.square(np.subtract(indiv._t_pos_set_a0, indiv._t_pos_estimate_a0)))
            traj_error_a1 = sum(
                np.square(np.subtract(indiv._t_pos_set_a1, indiv._t_pos_estimate_a1)))
            stat_error_a0 = sum(
                np.square(np.subtract(indiv._s_pos_set_a0, indiv._s_pos_estimate_a0)))
            stat_error_a1 = sum(
                np.square(np.subtract(indiv._s_pos_set_a1, indiv._s_pos_estimate_a1)))
            return (traj_error_a0, traj_error_a1, stat_error_a0, stat_error_a1)

        def static_test(indiv):
            odrv = indiv._outer.odrv
            traj = indiv._outer.traj
            pset_0 = traj[0][0]
            pset_1 = traj[0][1]

            start = time.perf_counter()
            s_now = time.perf_counter()

            for i in range(round(indiv._outer.STATIC_TEST_TIME/(indiv._outer.T_INPUT/indiv._outer.midpoints))):
                while ((s_now-start) // (indiv._outer.T_INPUT/indiv._outer.midpoints)) < i:
                    s_now = time.perf_counter()

                indiv._s_pos_set_a0.append(pset_0)
                indiv._s_pos_set_a1.append(pset_1)
                indiv._s_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                indiv._s_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                indiv._s_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                indiv._s_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)

        def traj_test(indiv):
            traj = indiv._outer.traj
            odrv = indiv._outer.odrv
            midpoints = indiv._outer.midpoints
            tot_time = indiv._outer.T_INPUT*len(traj)
            success = False
            while not success:
                indiv._t_pos_set_a0 = []
                indiv._t_pos_set_a1 = []
                indiv._t_pos_estimate_a0 = []
                indiv._t_pos_estimate_a1 = []
                indiv._t_Iq_set_a0 = []
                indiv._t_Iq_set_a1 = []

                odrv.axis0.controller.input_pos = lp0 = traj[0][0]
                odrv.axis1.controller.input_pos = lp1 = traj[0][1]
                robo_sleep(.015)

                start = time.perf_counter()
                p_now = time.perf_counter()
                p_count = 0

                for p in traj:
                    while ((p_now-start) // indiv._outer.T_INPUT) < p_count:
                        p_now = time.perf_counter()
                    p_count += 1

                    odrv.axis0.controller.input_pos = p[0]
                    odrv.axis1.controller.input_pos = p[1]

                    m_now = time.perf_counter()
                    for i in range(1, midpoints+1):
                        while ((m_now-start) // (indiv._outer.T_INPUT/midpoints)) < p_count*midpoints+i:
                            m_now = time.perf_counter()

                        indiv._t_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                        indiv._t_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                        indiv._t_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                        indiv._t_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                        indiv._t_pos_set_a0.append((p[0]-lp0)/midpoints*i+lp0)
                        indiv._t_pos_set_a1.append((p[1]-lp1)/midpoints*i+lp1)

                    lp0 = p[0]
                    lp1 = p[1]

                end = time.perf_counter()

                exec_time = end-start
                if abs(exec_time-tot_time) < tot_time*indiv._outer.EXEC_TOLERANCE:
                    success = True
                else:
                    print("ERROR EN TIMEPO = " + str(exec_time-tot_time))

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
            for g in range(group_size)] + [
            'Iq_set_'+ax+'_n'+str(g) for ax in ['a0', 'a1']
            for g in range(group_size)]

        k_in_cols = ['in_A0_Kp_pos', 'in_A0_Kp_vel', 'in_A0_Ki_vel',
                     'in_A1_Kp_pos', 'in_A1_Kp_vel', 'in_A1_Ki_vel']
        k_out_cols = ['out_A0_Kp_pos', 'out_A0_Kp_vel', 'out_A0_Ki_vel',
                      'out_A1_Kp_pos', 'out_A1_Kp_vel', 'out_A1_Ki_vel']

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
                        for g in individual['gains']:
                            ind_df['in_'+g] = individual['gains'][g]
                        evo_df = evo_df.append(ind_df)

                for wg in evo_data['winner']['gains']:
                    evo_df['out_'+wg] = evo_data['winner']['gains'][wg]
                master_ML_df = master_ML_df.append(evo_df)

        master_ML_df.to_csv(data_dir+out_file, index=False)

    def evo_gains_ML(self, traj_array, traj_name='test'):
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
        axis = [0, 1]
        for _ in range(0, self.POP_SIZE):
            kp = [r_uni(self.K_RANGE[0], self.K_RANGE[1]) for m in axis]
            kv = [r_uni(k_limits[1][0](kp[m]), k_limits[1][1](kp[m])) for m in axis]
            kvi = [r_uni(k_limits[2][0], k_limits[2][1](kp[m], kv[m])) for m in axis]
            population.append(self.Individual(0,
                                              self.check_gains([kp[0], kv[0], kvi[0]]),
                                              self.check_gains([kp[1], kv[1], kvi[1]]),
                                              self.outer))

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

            for p, elite in enumerate(population[:self.ELITES]):
                population[p] = self.Individual(elite.generation, elite._A0_gains, elite._A1_gains, self.outer)
            del population[self.ELITES:]

            n = 0
            while len(population) < (self.POP_SIZE - self.MUTTS):
                p1 = parents[n % self.SURVIVORS]
                p2 = r_choice(parents)
                population.append(self.Individual(generation, *self.cross_parents(p1, p2), self.outer))
                n += 1
            for _ in range(self.MUTTS):
                mutt = r_choice(population)
                population.append(self.Individual(generation, *self.create_mutt(mutt), self.outer))

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

    def cross_parents(self, p1, p2):
        cross_rate = r_uni(0, (1+self.MUTT_RATE))
        ch_gains = np.add([p1.gains[g1]*cross_rate for g1 in p1.gains],
                          [p2.gains[g2]*(1-cross_rate) for g2 in p2.gains])
        return (self.check_gains(ch_gains[:3]), self.check_gains(ch_gains[3:]))

    def create_mutt(self, origin):
        mutt_gains_A0 = []
        mutt_gains_A1 = []
        mutt_rate_A0 = 1+r_uni(-self.MUTT_RATE, self.MUTT_RATE)
        mutt_rate_A1 = 1+r_uni(-self.MUTT_RATE, self.MUTT_RATE)
        for g in origin.gains:
            if g.startswith('A0'):
                mutt_gains_A0.append(origin.gains[g]*mutt_rate_A0)
            else:
                mutt_gains_A1.append(origin.gains[g]*mutt_rate_A1)
        return (self.check_gains(mutt_gains_A0), self.check_gains(mutt_gains_A1))

    def print_results(self, pop):
        for i in pop:
            print(i.generation, round(i.score, 4), [round(i.gains[g], 3)
                  for g in i.gains], sep="  ")
            print('  ', round(i.errors["traj_error_a0"]+i.errors["traj_error_a1"], 5),
                  round(i.errors["stat_error_a0"]+i.errors["stat_error_a1"], 5),
                  sep=" + ")

    def print_group(self, plot_group):
        self.print_indiv_group_trajs(plot_group)

    def print_indiv_group_trajs(self, chosen):
        time_axis = []
        accumulated_time = 0
        estimatess = []
        inputss = []
        errorss = []
        for indiv in chosen:
            time_axis.extend([t+accumulated_time for t in range(0,
                             (len(indiv.traj_data['pos_estimate_a1']+indiv.stat_data['pos_estimate_a1'])*2))])
            accumulated_time = time_axis[-1]

            e0 = indiv.traj_data['pos_estimate_a0']+indiv.stat_data['pos_estimate_a0']
            e1 = indiv.traj_data['pos_estimate_a1']+indiv.stat_data['pos_estimate_a1']
            estimatess.extend(e0 + e1)
            i0 = indiv.traj_data['pos_set_a0']+indiv.stat_data['pos_set_a0']
            i1 = indiv.traj_data['pos_set_a1']+indiv.stat_data['pos_set_a1']
            inputss.extend(i0 + i1)
            errorss.extend(list(np.multiply(1, np.abs(np.subtract(np.array(i0+i1), np.array(e0+e1))))))
        plt.plot(time_axis, estimatess)
        plt.plot(time_axis, inputss)
        plt.plot(time_axis, errorss)
        plt.xlabel("Muestreo")
        plt.ylabel("Posición")
        plt.legend(["Posición Actual", "Referencia", "Error"])
        plt.show()

    def run_ML_model_traj(self, ML_model):
        self.ML_model = ML_model
        self.ML_model.predict(np.matrix([0 for i in range(40)]))
        traj = self.traj
        odrv = self.odrv
        midpoints = self.midpoints
        tot_time = self.T_INPUT*len(traj)
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
            robo_sleep(.015)

            start = time.perf_counter()
            p_now = time.perf_counter()
            p_count = 0

            for p in traj:
                while ((p_now-start) // self.T_INPUT) < p_count:
                    p_now = time.perf_counter()
                p_count += 1

                odrv.axis0.controller.input_pos = p[0]
                odrv.axis1.controller.input_pos = p[1]
                m_now = time.perf_counter()

                for i in range(1, midpoints+1):
                    while ((m_now-start) // (self.T_INPUT/midpoints)) < p_count*midpoints+i:
                        m_now = time.perf_counter()

                    self._ML_pos_set_a0.append((p[0]-lp0)/midpoints*i+lp0)
                    self._ML_pos_set_a1.append((p[1]-lp1)/midpoints*i+lp1)
                    self._ML_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                    self._ML_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                    self._ML_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                    self._ML_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                    self._ML_pos_error_a0.append(self._ML_pos_set_a0[-1]-self._ML_pos_estimate_a0[-1])
                    self._ML_pos_error_a1.append(self._ML_pos_set_a1[-1]-self._ML_pos_estimate_a1[-1])
                    ref_counter += 1
                    if ref_counter % self.update_interval == 0:
                        #start=time.perf_counter()
                        self.do_model_predict()
                        #end=time.perf_counter()
                        #print('Tiempo de predicción')
                        #print(end-start)

                lp0 = p[0]
                lp1 = p[1]

            #end = time.perf_counter()
            #exec_time = end-start

            #if abs(exec_time-tot_time) < tot_time*self.EXEC_TOLERANCE:
            success = True
            #else:
            #    print("ERROR EN TIMEPO = " + str(exec_time-tot_time))

    def do_model_predict(self):
        self.X_val = np.matrix([self._ML_pos_error_a0[-10:]
                                + self._ML_pos_error_a1[-10:]
                                + self._ML_Iq_set_a0[-10:]
                                + self._ML_Iq_set_a1[-10:]])

        self.results = self.ML_model(self.X_val, training=False)
        predicted_A0_gains = [self.results[0][0], self.results[0][1]/100, self.results[0][2]/10]
        predicted_A1_gains = [self.results[0][3], self.results[0][4]/100, self.results[0][5]/10]
        configure.independent_gains(self.odrv, predicted_A0_gains, predicted_A1_gains)

    def ML_model_exec_plot(self):
        time_axis = range(0, len(self._ML_pos_set_a0)*2)
        plt.plot(time_axis, self._ML_pos_estimate_a0+self._ML_pos_estimate_a1)
        plt.plot(time_axis, self._ML_pos_set_a0+self._ML_pos_set_a1)
        plt.plot(time_axis, np.multiply(15, np.abs(self._ML_pos_error_a0+self._ML_pos_error_a1)))
        plt.xlabel("Muestreo")
        plt.ylabel("Posición")
        plt.legend(["Posición Actual", "Referencia", "Error (Abs)"])
        plt.show()

    def set_test_params(self):
        self.MAX_GENERATIONS = 5
        self.POP_SIZE = 10
        self.ELITES = 2
        self.SURVIVORS = 6
        self.MUTTS = 4
        self.plot = True
