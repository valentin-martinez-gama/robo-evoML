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
        df.insert(i+4, actual_pos, pd.Series([], dtype=float))
        df.insert(2*i+5, desired_pos, pd.Series([], dtype=float))
    return df

def add_pandas_entry(df, id, kp, kv, kvi, estimates, inputs):
    row = [id, kp, kv, kvi] + estimates + inputs
    df.loc[len(df.index)] = row
    return df

def csv_export(df):
    csv_name = input("Introduce el nombre con el que quieres guardar el archivo (SIN .csv): ")
    df.to_csv(rf"{csv_name}.csv", index = False)
