import json
import time

import odrive
from odrive.enums import *

from Odrive_control import configure, plots
import ML
import ML_data
import evo_ML

def traj_training(odrv, training_tag='Test', num_evos=5, traj_file='robo_trajs.json'):
    traj_dir='Trajectories/'
    traj_list = []
    with open(traj_dir+traj_file, 'r') as t_file:
        for traj in t_file:
            traj_list.append(json.loads(traj))

    trap_move_to_start(odrv, [.7,.7])
    ML.robo.start(odrv)
    #Opcion de randomizar orden de lista de trajectorias
    for i in range(num_evos):
        lim_index = i%len(traj_list)
        s_p0 = traj_list[lim_index]['Trajectory'][0][0]
        s_p1 = traj_list[lim_index]['Trajectory'][0][1]
        print("Moviendose a "+str(s_p0)+'-'+str(s_p1))
        trap_move_to_start(odrv, [s_p0,s_p1])
        print("Ejecutando ejercicio de entrenamiento "+str(i))
        print("Trayectoria: " + traj_list[lim_index]['Tag'])
        ML.ML_sleep(.2)
        iter_result = evo_ML.evo_gains_ML(odrv, traj_list[lim_index]['Trajectory'], training_tag+'.json')
        print("Ganador del ejercicio = ")
        print(iter_result['gains'])

    ML_data.build_ML_training_set(training_tag+'.json', training_tag+'.csv')

def trap_move_to_start(odrv, p_list):

    wait_time = 1.5
    axis = [odrv.axis0, odrv.axis1]
    ML.robo.configure.gains(odrv, 20, .16, .32)
    ML.robo.configure.trap_traj(odrv, vel_lim=.75, accel_lim=2)

    for a in range(len(axis)):
        axis[a].controller.config.input_mode = INPUT_MODE_TRAP_TRAJ

    #Regresar a 0
    axis[0].controller.input_pos = .25
    ML.ML_sleep(wait_time)
    axis[1].controller.input_pos = 0
    ML.ML_sleep(wait_time)
    axis[0].controller.input_pos = 0
    ML.ML_sleep(wait_time)

    #Ir a nueva posicion de inicio
    axis[0].controller.input_pos = .25
    ML.ML_sleep(wait_time)
    axis[1].controller.input_pos = p_list[1]
    ML.ML_sleep(wait_time)
    axis[0].controller.input_pos = p_list[0]
    ML.ML_sleep(wait_time)

    for a,real_pos in enumerate(p_list):
        axis[a].controller.config.input_mode = INPUT_MODE_PASSTHROUGH

    return print("DONE TRAP START MOVE")

'''
def move_to_traj_start(odrv, p_list):

    ML.robo.configure.gains(odrv, 25, .25, .4)
    ML.robo.configure.trap_traj(odrv, vel_lim=1, accel_lim=3)

    for a in range(len(axis)):
        axis[a].controller.config.input_mode = INPUT_MODE_TRAP_TRAJ
        axis[a].controller.input_pos = (axis[a].encoder.pos_estimate%1)//.5
        ML.ML_sleep(.2)
    ML.ML_sleep(.5)

    for a in range(len(axis)):
        axis[a].requested_state = 1
        axis[a].encoder.set_linear_count(0)
        axis[a].controller.input_pos = 0
        ML.ML_sleep(.015)
        axis[a].requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

    for a,targ_pos, in enumerate(p_list):
        safe_pos = targ_pos/abs(targ_pos)*(abs(targ_pos)%.5-(abs(targ_pos)%1)//.5*.5)
        axis[a].controller.input_pos = safe_pos
    ML.ML_sleep(.6)
    input("A3")
    for a,real_pos in enumerate(p_list):
        axis[a].requested_state = 1
        axis[a].encoder.set_linear_count(real_pos)
        axis[a].controller.input_pos = real_pos
        ML.ML_sleep(.015)
        axis[a].requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        axis[a].controller.config.input_mode = INPUT_MODE_PASSTHROUGH
        ML.ML_sleep(.015)

    return "DONE START TRAJ"
'''
