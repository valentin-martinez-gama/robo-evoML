import json
import csv
from random import shuffle
from math import pi
import numpy as np
import matplotlib.pyplot as plt
from random import uniform as r_uni
from importlib import reload
import keras

from Odrive_control import configure, robo
from Odrive_control.timetest import robo_sleep
from evo_Models.greekModel import greek_Model as evo_default

from odrive.enums import *
'''
Plataforma de entrenamiento para red neuronal a partir de evolución diferencial

    3.- La data que debe de recoger el robot:
        5 points - Err pos(respecto a Setpoint pasado)
        5 points - Err corriente

        x2 motores.
'''

'''
    Otros TO DOs:

    * Definir trajectoria independiente para cada motor

    PREGUNTAS

    Que cada motor evolucione sus propias gancias?
    Con scores (y papas) separados o con score suma?

    Cuanta importancia para el estatico vs Trayectoria?

'''


def generate_results(odrv, evo_gains, ML_file, traj_file, results_tag='results'):
    trap_move_to_start(odrv, [.65, .65])


    traj_dir = 'Trajectories/'
    traj_list = []
    with open(traj_dir+traj_file, 'r') as t_file:
        for traj in t_file:
            traj_list.append(json.loads(traj))

    obj = evo_default(odrv, results_tag+'_RES')
    ML_model = load_net(ML_file)

    for t in traj_list:
        s_p0 = t['Trajectory'][0][0]
        s_p1 = t['Trajectory'][0][1]
        print("Obteniendo resultados para Trayectoria: "+t['Tag'])
        trap_move_to_start(odrv, [s_p0, s_p1])
        robo_sleep(.2)

        obj.traj = t['Trajectory']

        #print("RANDOM INDIV *********")
        #axis = [0, 1]
        #k_limits = obj.k_limits
        #kp = [r_uni(obj.K_RANGE[0], obj.K_RANGE[1]) for m in axis]
        #kv = [r_uni(k_limits[1][0](kp[m]), k_limits[1][1](kp[m])) for m in axis]
        #kvi = [r_uni(k_limits[2][0], k_limits[2][1](kp[m], kv[m])) for m in axis]
        #rand_indiv = [obj.Individual(111,
        #                             obj.check_gains([kp[0], kv[0], kvi[0]]),
        #                             obj.check_gains([kp[1], kv[1], kvi[1]]),
        #                             obj.outer)]
        #obj.print_results(rand_indiv)

        #print("EVO GAINS INDIV ***********")
        #evo_indiv = [obj.Individual(222,
        #                            obj.check_gains(evo_gains[0]),
        #                            obj.check_gains(evo_gains[1]),
        #                            obj.outer)]
        #obj.print_results(evo_indiv)

        print("ML GAINS INDIV **********")
        original_function = obj.Individual.get_training_errors_data
        obj.ML_model = ML_model
        obj.Individual.get_training_errors_data = obj.Individual.get_ML_errors_data
        ML_indiv = [obj.Individual(333,
                                   obj.check_gains(evo_gains[0]),
                                   obj.check_gains(evo_gains[1]),
                                   obj.outer)]
        obj.print_results(ML_indiv)
        obj.Individual.get_training_errors_data = original_function

        combined_results = [ML_indiv]#[rand_indiv, evo_indiv, ML_indiv]

        max_score = 99999
        for r in combined_results:
            if r[0].score < max_score:
                winner = r[0]
        obj.traj_name=t['Tag']
        obj.print_group([r[0] for r in combined_results])
        obj.save_ML_data([c[0].export_dict() for c in combined_results], winner.export_dict())
    print(obj.am)
    return combined_results

def organize_results(result_tag):
    data_dir = 'Datasets/'
    in_file = result_tag + '.json'
    out_file = result_tag + '.csv'
    code = {111:'RANDOM', 222:'EVO', 333:'ML'}
    with open(data_dir+in_file, 'r') as json_file, open(data_dir+out_file, 'w', newline='') as res_file:
        res_write = csv.writer(res_file)
        for line in json_file:
            data = json.loads(line)
            res_write.writerow([data['winner']['generation'], 'runID=',data['runID'], 'Trajectory',data['traj']])
            for m in data['runs_data']:
                res_write.writerow([code[m['generation']], m['score']])
                res_write.writerow(['Gains'])
                res_write.writerow(list(m['gains'].keys()))
                res_write.writerow(list(m['gains'].values()))
                res_write.writerow(['Calculated errors'])
                res_write.writerow(['Total Error', 'AO Error', 'A1 Error']+list(m['errors'].keys()))
                res_write.writerow([sum(list(m['errors'].values())),
                                    m['errors']['traj_error_a0']+m['errors']['stat_error_a0'],
                                    m['errors']['traj_error_a1']+m['errors']['stat_error_a1']]
                                    + list(m['errors'].values()))
                res_write.writerow(['Pos Set A0 - A1'])
                pos_set_a0 = m['traj_data']['pos_set_a0'] + m['stat_data']['pos_set_a0']
                pos_set_a1 = m['traj_data']['pos_set_a1'] + m['stat_data']['pos_set_a1']
                res_write.writerows([pos_set_a0,pos_set_a1])
                res_write.writerow(['Pos Estimates A0 - A1'])
                pos_estimate_a0 = m['traj_data']['pos_estimate_a0'] + m['stat_data']['pos_estimate_a0']
                pos_estimate_a1 = m['traj_data']['pos_estimate_a1'] + m['stat_data']['pos_estimate_a1']
                res_write.writerows([pos_estimate_a0,pos_estimate_a1])
                res_write.writerow(['Errors A0 - A1'])
                res_write.writerows([np.abs(np.subtract(pos_set_a0,pos_estimate_a0)),
                                     np.abs(np.subtract(pos_set_a1,pos_estimate_a1))])
                res_write.writerow([''])
            res_write.writerow(['---------'])
            res_write.writerow([''])
    return 1


def traj_training(odrv, evo_model,
                  num_evos=5, traj_file='all_trajs.json'):

    traj_dir = 'Trajectories/'
    traj_list = []
    with open(traj_dir+traj_file, 'r') as t_file:
        for traj in t_file:
            traj_list.append(json.loads(traj))

    trap_move_to_start(odrv, [.65, .65])
    robo.start(odrv, time_error=False)
    # Opcion de randomizar orden de lista de trajectorias
    shuffle(traj_list)
    for i in range(num_evos):
        lim_index = i % len(traj_list)
        s_p0 = traj_list[lim_index]['Trajectory'][0][0]
        s_p1 = traj_list[lim_index]['Trajectory'][0][1]
        print("*************************************************")
        print("Ejecutando ejercicio de entrenamiento "+str(i+1))
        print("Trayectoria: " + traj_list[lim_index]['Tag'])
        print("Moviendose a "+str(s_p0)+'-'+str(s_p1))
        trap_move_to_start(odrv, [s_p0, s_p1])
        robo_sleep(.2)
        iter_result = evo_model.evo_gains_ML(traj_list[lim_index]['Trajectory'])
        print("--------------------------------------------------")
        print("Ganador del ejercicio = ")
        print(iter_result['gains'])
        print()
        configure.gains(odrv)

    evo_model.build_ML_training_set()
    robo.idle(odrv)


def execute_ML_file(odrv, evo_model, ML_file='model', traj_file='all_trajs.json', num_execs=1):
    ML_model = load_net(ML_file)

    traj_dir = 'Trajectories/'
    traj_list = []
    with open(traj_dir+traj_file, 'r') as t_file:
        for traj in t_file:
            traj_list.append(json.loads(traj))

    trap_move_to_start(odrv, [.65, .65])
    robo.start(odrv, time_error=False)
    # Opcion de randomizar orden de lista de trajectorias
    shuffle(traj_list)
    for i in range(num_execs):
        lim_index = i % len(traj_list)
        s_p0 = traj_list[lim_index]['Trajectory'][0][0]
        s_p1 = traj_list[lim_index]['Trajectory'][0][1]
        print("*************************************************")
        print("Ejecutando red en timepo real "+str(i+1))
        print("Trayectoria: " + traj_list[lim_index]['Tag'])
        print("Moviendose a "+str(s_p0)+'-'+str(s_p1))
        trap_move_to_start(odrv, [s_p0, s_p1])
        robo_sleep(.2)
        evo_model.run_ML_model_traj(ML_model, traj_list[lim_index]['Trajectory'])
        print("--------------------------------------------------")
        print()
        if evo_model.plot is True:
            evo_model.ML_model_exec_plot()
        configure.gains(odrv)

    robo.idle(odrv)


def load_net(ML_file):
    # load json and create model
    json_file = open('ML_Models/'+ML_file+'.json', 'r')
    loaded_model_json = json_file.read()
    json_file.close()
    ML_model = keras.models.model_from_json(loaded_model_json)
    # load weights into new model
    ML_model.load_weights('ML_Models/'+ML_file+".h5")
    print("Loaded model from disk")

    ML_model.compile(loss='mean_squared_error', optimizer='adam')

    return ML_model


def trap_move_to_start(odrv, p_list):
    """ Slowly return robo the 0 position and next start configuration"""
    wait_time = 1.5
    axis = [odrv.axis0, odrv.axis1]
    configure.gains(odrv, 20, .16, .32)
    configure.trap_traj(odrv, vel_lim=.75, accel_lim=2)

    for a in range(len(axis)):
        axis[a].controller.config.input_mode = INPUT_MODE_TRAP_TRAJ

    # Regresar a 0
    if axis[1].encoder.pos_estimate > .5:
        axis[1].controller.input_pos = .75
        robo_sleep(wait_time)
    axis[0].controller.input_pos = .25
    robo_sleep(wait_time)
    axis[1].controller.input_pos = 0
    robo_sleep(wait_time)
    axis[0].controller.input_pos = 0
    robo_sleep(wait_time)

    # Ir a nueva posicion de inicio
    axis[0].controller.input_pos = .25
    robo_sleep(wait_time)
    axis[1].controller.input_pos = p_list[1]
    robo_sleep(wait_time)
    axis[0].controller.input_pos = p_list[0]
    robo_sleep(wait_time)

    for a, real_pos in enumerate(p_list):
        axis[a].controller.config.input_mode = INPUT_MODE_PASSTHROUGH

    return print("DONE TRAP START MOVE")


def build_traj_from_csv(in_file, traj_tag, out_file='all_trajs.json'):
    traj_dir = 'Trajectories/'
    with open(traj_dir+in_file, 'r') as csv_traj:

        traj_data = list(csv.reader(csv_traj))
        pos_set_a0 = [float(p) for p in traj_data[0]]
        pos_set_a1 = [float(p) for p in traj_data[1]]

        if any(p < 0 for p in pos_set_a0):
            pos_set_a0 = [p+1 for p in pos_set_a0]
        if any(p < 0 for p in pos_set_a1):
            pos_set_a1 = [p+1 for p in pos_set_a1]

        traj = list(zip(pos_set_a0, pos_set_a1))

    with open(traj_dir+out_file, 'a') as list_traj:
        json.dump({'Tag': traj_tag, 'Trajectory': traj}, list_traj)
        list_traj.write('\n')


def ML_trajectory(pos1=0, pos2=pi, t=.5):
    traj_data = robo.trajectory.build_trajectory(pos1, pos2, t1=t, t2=t, res=2*t/.02)
    ML_traj = [[traj_data["OUTBOUND"][i], traj_data["OUTBOUND"][i]] for i in range(len(traj_data["OUTBOUND"]))] + [[traj_data["RETURN"][i], traj_data["RETURN"][i]] for i in range(len(traj_data["RETURN"]))]
    return ML_traj


def ML_print_indiv_group_trajs(chosen):
    time_axis = []
    accumulated_time = 0
    estimatess = []
    inputss = []
    errorss = []
    for indiv in chosen:
        time_axis.extend([t+accumulated_time for t in range(0,
                        len(indiv.traj_data['pos_estimate_a1']+indiv.stat_data['pos_estimate_a1']))])
        accumulated_time = time_axis[-1]

        e = indiv.traj_data['pos_estimate_a1']+indiv.stat_data['pos_estimate_a1']
        estimatess.extend(e)
        i = indiv.traj_data['pos_set_a1']+indiv.stat_data['pos_set_a1']
        inputss.extend(i)
        errorss.extend(list(np.multiply(1, np.abs(np.subtract(np.array(i), np.array(e))))))
    plt.plot(time_axis, estimatess)
    plt.plot(time_axis, inputss)
    plt.plot(time_axis, errorss)
    plt.xlabel("Muestreo")
    plt.ylabel("Posición")
    plt.legend(["Posición Actual", "Referencia", "Error"])
    plt.show()
