# Script test
import pandas as pd

def build_pandas(samples):
    df = pd.DataFrame()
    # Create columns to store data
    id = pd.Series([], dtype=int)
    pos_gain = pd.Series([], dtype=float)
    vel_gain = pd.Series([], dtype=float)
    vel_integrator_gain = pd.Series([], dtype=float)
    df.insert(0, "Iteracion", id)
    df.insert(1, "pos_gain", pos_gain)
    df.insert(2, "vel_gain", vel_gain)
    df.insert(3, "vel_integrator_gain", vel_integrator_gain)
    for i in range(samples):
        actual_pos = "pos_estimate" + str(i)
        desired_pos = "input_pos" + str(i)
        iq_measured = "iq_measured" + str(i)
        vel_estimate = "vel_estimate" + str(i)
        df.insert(i+4, actual_pos, pd.Series([], dtype=float))
        df.insert(2*i+5, desired_pos, pd.Series([], dtype=float))
        df.insert(3*i+6, iq_measured, pd.Series([], dtype=float))
        df.insert(4*i+7, vel_estimate, pd.Series([], dtype=float))
    return df

def add_pandas_entry(df, id, kp, kv, kvi, estimates, inputs, currents, vels):
    row = [id, kp, kv, kvi] + estimates + inputs + currents + vels
    df.loc[len(df.index)] = row
    return df

def calculate_error(data, samples):
    df = pd.DataFrame()
    df = data.iloc[:, :4]
    positive_error = pd.Series([], dtype=float)
    negative_error = pd.Series([], dtype=float)
    current_sum = pd.Series([], dtype=float)
    curr_vel = pd.Series([], dtype=float)
    for i in range(len(data)):
        pos_error = 0.0
        neg_error = 0.0
        total_current = 0.0
        all_curr_vel = []
        for s in range(samples):
            error = data["input_pos" + str(s)][i] - data["pos_estimate" + str(s)][i]
            if error > 0:
                pos_error += error
            else:
                neg_error += error
            iter_curr = data["iq_measured" + str(s)][i]
            total_current += abs(iter_curr)
            cur_vel_division = iter_curr/data["vel_estimate" + str(s)][i]
            all_curr_vel.append(cur_vel_division)
        positive_error[i] = pos_error
        negative_error[i] = neg_error
        current_sum[i] = total_current
        curr_vel[i] = sum(all_curr_vel)/float(len(all_curr_vel))
    df.insert(4, "positive_error", positive_error)
    df.insert(5, "negative_error", negative_error)
    df.insert(6, "current_sum", current_sum)
    df.insert(7, "curr_vel", curr_vel)
    return df


def csv_export(df):
    csv_name = input("Introduce el nombre con el que quieres guardar el archivo (SIN .csv): ")
    df.to_csv(rf"{csv_name}.csv", index = False)
