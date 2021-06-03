from evo_Models.betaModel import beta_Model
import matplotlib.pyplot as plt
from random import uniform as r_uni
from random import choice as r_choice
import numpy as np
import pandas as pd
import json

from Odrive_control import configure
import ML


class gamma_Model(beta_Model):

    def __init__(self, odrv, training_tag):
        beta_Model.__init__(self, odrv, training_tag)
        self.Individual = self.gamma_Individual
        self.plot = True

    class gamma_Individual(beta_Model.beta_Individual):

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

    def do_model_predict(self):
        self.X_val = np.matrix([self._ML_pos_error_a0[-10:]
                                + self._ML_pos_error_a1[-10:]
                                + self._ML_Iq_set_a0[-10:]
                                + self._ML_Iq_set_a1[-10:]])

        self.results = self.ML_model.predict(self.X_val)
        predicted_A0_gains = [self.results[0][0], self.results[0][1]/10, self.results[0][2]/10]
        predicted_A1_gains = [self.results[0][3], self.results[0][4]/10, self.results[0][5]/10]
        configure.independent_gains(self.odrv, predicted_A0_gains, predicted_A1_gains)

    def evo_gains_ML(self, traj_array,):
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
            errorss.extend(list(np.multiply(15, np.abs(np.subtract(np.array(i0+i1), np.array(e0+e1))))))
        plt.plot(time_axis, estimatess)
        plt.plot(time_axis, inputss)
        plt.plot(time_axis, errorss)
        plt.xlabel("Muestreo")
        plt.ylabel("Posición")
        plt.legend(["Posición Actual", "Referencia", "Error"])
        plt.show()

    def print_group(self, plot_group):
        self.print_indiv_group_trajs(plot_group)

    def I_am(self):
        print("I am Gamma")

    def set_test_params(self):
        self.MAX_GENERATIONS = 5
        self.POP_SIZE = 10
        self.ELITES = 2
        self.SURVIVORS = 6
        self.MUTTS = 4
        self.plot = True
