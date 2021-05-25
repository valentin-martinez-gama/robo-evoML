from evo_Models.betaModel import beta_Model
from random import uniform as r_uni
from random import choice as r_choice
from random import randrange
import numpy as np
import pandas as pd
import json

from Odrive_control import configure
import ML


class gamma_Model(beta_Model):

    def __init__(self, odrv, training_tag):
        beta_Model.__init__(odrv, training_tag)
        self.Individual = self.gamma_Individual

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
            del population[self.ELITES:]

            n = 0
            while len(population) < self.POP_SIZE:
                p1 = parents[n % self.SURVIVORS]
                p2 = r_choice(parents)
                population.append(self.Individual(generation, *self.cross_parents(p1, p2), self.outer))
                n += 1
            for _ in range(self.MUTTS):
                mutt_pos = randrange(self.ELITES, self.POP_SIZE)
                population[mutt_pos] = self.Individual(generation, *self.create_mutt(population[mutt_pos]), self.outer)

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
            ML.ML_print_indiv_group_trajs(plot_group)

        self.save_ML_data(historic, population[0].export_dict())
        return population[0].export_dict()

    def cross_parents(self, p1, p2):
        cross_rate = r_uni(0, (1+self.MUTT_RATE))
        ch_gains = np.add([p1.gains[g1]*cross_rate for g1 in p1.gains],
                          [p2.gains[g2]*(1-cross_rate) for g2 in p2.gains])
        return (self.check_gains(ch_gains[:3]), self.check_gains(ch_gains[3:]))

    def create_mutt(self, origin):
        mutt_gains = [origin.gains[g]*(1+r_uni(-self.MUTT_RATE, self.MUTT_RATE))
                      for g in origin.gains]
        return (self.check_gains(mutt_gains[:3]), self.check_gains(mutt_gains[3:]))

    def build_ML_training_set(self, group_size=10):
        in_file = self.training_tag + '.json'
        out_file = self.training_tag + '.csv'
        error_cols = [
            'pos_error_'+ax+'_n'+str(g) for ax in ['a0', 'a1']
            for g in range(group_size)]+['Iq_set_'+ax+'_n'+str(g)
            for ax in ['a0', 'a1'] for g in range(group_size)]

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

    def I_am(self):
        print("I am Gamma")
