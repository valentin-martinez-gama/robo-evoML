import pandas as pd
import numpy as np

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
    errors = list(map(lambda i,e: np.subtract(i,e), inputs, estimates))
    positive_error = [sum(filter(lambda e: e >0, iter)) for iter in errors]
    negative_error = [sum(filter(lambda e: e <0, iter)) for iter in errors]
    current_sum = [sum(np.abs(iter)) for iter in currents]
    curr_vel = list(map(lambda c,v: np.mean(np.abs(c))/np.mean(np.abs(v)), currents, vels))

    df = gains
    df.insert(4, "positive_error", positive_error)
    df.insert(5, "negative_error", negative_error)
    df.insert(6, "current_sum", current_sum)
    df.insert(7, "curr_vel", curr_vel)
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
