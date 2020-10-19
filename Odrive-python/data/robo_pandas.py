import pandas as pd
import numpy as np
from statistics import mean

def build_raw(samples):
    df = pd.DataFrame()
    # Create columns to store data
    df.insert(0, "Iteracion", pd.Series([], dtype=int))
    df.insert(1, "pos_gain", pd.Series([], dtype=float))
    df.insert(2, "vel_gain", pd.Series([], dtype=float))
    df.insert(3, "vel_integrator_gain", pd.Series([], dtype=float))
    df.insert(4, "pos_estimate", pd.Series([], dtype=object))
    df.insert(5, "input_pos", pd.Series([], dtype=object))
    df.insert(6, "Iq_measured", pd.Series([], dtype=object))
    df.insert(7, "vel_estimate", pd.Series([], dtype=object))

    return df

def add_raw(df, id, kp, kv, kvi, estimates, inputs, currents, vels):
    row = [id, kp, kv, kvi, estimates, inputs, currents, vels]
    df.loc[len(df)] = row
    return df

def clean_data(data):
    gains = data.iloc[:, :4]
    estimates = data.iloc[:, 4]
    inputs = data.iloc[:, 5]
    currents = data.iloc[:, 6]
    vels = data.iloc[:, 7]

    #errors = ([np.subtract(inputs[i], estimates[i]) for i in range(inputs.size)])
    sample_size = len(estimates[0])
    errors = list(map(lambda i,e: np.subtract(i,e), inputs, estimates))
    lag_error = [sum(filter(lambda e: e>0, iter)) for iter in errors[0:sample_size//2]] + [sum(filter(lambda e: e<0, iter)) for iter in errors[sample_size//2:]]
    ahead_error = [sum(filter(lambda e: e<0, iter)) for iter in errors[0:sample_size//2]] + [sum(filter(lambda e: e>0, iter)) for iter in errors[sample_size//2:]]

    overshoot_error = list(map(lambda i,e: max(e)-max(i), inputs, estimates))

    current_sum = [sum(np.abs(iter)) for iter in currents]
    curr_vel = list(map(lambda c,v: np.mean(np.abs(c))/np.mean(np.abs(v)), currents, vels))

    error_sum = abs(lag_error) + abs(ahead_error)
    masa = mean(curr_vel)

    df = gains
    df.insert(4, "lag_error", lag_error)
    df.insert(5, "ahead_error", ahead_error)
    df.insert(6, "error_sum", error_sum)
    df.insert(7, "overshoot_error", overshoot_error)
    df.insert(8, "current_sum", current_sum)
    df.insert(9, "curr_vel", curr_vel)
    df.insert(10, "masa", masa)
    return df

def export_raw(rawdf):
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
    for i in range(len(rawdf.iloc[0,4])):
        actual_pos = "pos_estimate" + str(i)
        desired_pos = "input_pos" + str(i)
        iq_measured = "iq_measured" + str(i)
        vel_estimate = "vel_estimate" + str(i)
        df.insert(i+4, actual_pos, pd.Series([], dtype=float))
        df.insert(2*i+5, desired_pos, pd.Series([], dtype=float))
        df.insert(3*i+6, iq_measured, pd.Series([], dtype=float))
        df.insert(4*i+7, vel_estimate, pd.Series([], dtype=float))

    for e in range(len(rawdf)):
        row  = rawdf.iloc[e,:4].values.tolist()
        vals = [item for elem in rawdf.iloc[e,4:].values.tolist() for item in elem]
        df.loc[len(df.index)] = row + vals
    csv_export(df)
    return df

def csv_export(df):
    choice = input("Want to export DataFrame to CSV?: y/n ")
    if choice == "y":
        csv_name = input("Introduce el nombre con el que quieres guardar el archivo (SIN .csv): ")
        df.to_csv(rf"{csv_name}.csv", index = False)
    return
