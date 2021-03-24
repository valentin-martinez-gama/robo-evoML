import pandas as pd
import json

def build_ML_training_set(in_file, out_file='out_file.csv', group_size=5):

    error_cols = ['pos_error_'+ax+'_n'+str(g) for ax in ['a0','a1'] for g in range(group_size)]+['Iq_error_'+ax+'_n'+str(g) for ax in ['a0','a1'] for g in range(group_size)]
    k_in_cols = ['in_Kp_pos','in_Kp_vel','in_Ki_vel']
    k_out_cols = ['out_Kp_pos','out_Kp_vel','out_Ki_vel']

    fix_names = ['win_K']
    master_ML_df = pd.DataFrame(columns=k_in_cols+error_cols+k_out_cols)

    with open(in_file, 'r') as json_file:
        for evolution in json_file:
            evo_df = pd.DataFrame(columns=error_cols+k_in_cols)
            evo_data = json.loads(evolution)

            for generation in evo_data['runs_data']:
                for individual in generation:

                    base_df = pd.DataFrame(individual['traj_data'])
                    calc_df = pd.DataFrame()
                    calc_df['pos_error_a0'] = base_df['pos_set_a0'] - base_df['pos_estimate_a0']
                    calc_df['pos_error_a1'] = base_df['pos_set_a1'] - base_df['pos_estimate_a1']
                    calc_df['Iq_error_a0'] = base_df['Iq_set_a0'] - base_df['Iq_measured_a0']
                    calc_df['Iq_error_a1'] = base_df['Iq_set_a1'] - base_df['Iq_measured_a1']

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

    master_ML_df.to_csv(out_file, index=False)
