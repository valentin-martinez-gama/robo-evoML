import pandas as pd
import numpy as np

def build_raw(samples):
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

def add_raw(df, id, kp, kv, kvi, estimates, inputs, currents, vels):
    row = [id, kp, kv, kvi] + estimates + inputs + currents + vels
    df.loc[len(df)] = row
    return df

def clean_data(data, samples):
    gains = data.iloc[:, :4]
    estimates = data.iloc[:, 4:(samples+4)]
    inputs = data.iloc[:, (samples+4):(2*samples+4)]
    currents = data.iloc[:, (2*samples+4):(3*samples+4)]
    vels = data.iloc[:, (3*samples+4):(4*samples+4)]

    inputs.columns = estimates.columns
    errors = inputs-estimates
    positive_error = errors.where(errors > 0).sum(1)
    negative_error = errors.where(errors < 0).sum(1)

    current_sum = currents.abs().sum(1)

    vels.columns = currents.columns
    curr_vel = (currents.abs()/vels.abs()).mean(1)

    df = gains
    df.insert(4, "positive_error", positive_error)
    df.insert(5, "negative_error", negative_error)
    df.insert(6, "current_sum", current_sum)
    df.insert(7, "curr_vel", curr_vel)
    return df


def csv_export(df):
    csv_name = input("Introduce el nombre con el que quieres guardar el archivo (SIN .csv): ")
    df.to_csv(rf"{csv_name}.csv", index = False)
