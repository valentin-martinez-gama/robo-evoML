import json
from random import shuffle

import ML
import ML_data
import evo_ML

from odrive.enums import *

from Odrive_control import configure
from Odrive_control.timetest import robo_sleep


def traj_training(odrv, training_tag='Test',
                  num_evos=5, traj_file='all_trajs.json'):

    traj_dir = 'Trajectories/'
    traj_list = []
    with open(traj_dir+traj_file, 'r') as t_file:
        for traj in t_file:
            traj_list.append(json.loads(traj))

    trap_move_to_start(odrv, [.7, .7])
    ML.robo.start(odrv)
    # Opcion de randomizar orden de lista de trajectorias
    shuffle(traj_list)
    for i in range(num_evos):
        lim_index = i % len(traj_list)
        s_p0 = traj_list[lim_index]['Trajectory'][0][0]
        s_p1 = traj_list[lim_index]['Trajectory'][0][1]
        print("*************************************************")
        print("Ejecutando ejercicio de entrenamiento "+str(i))
        print("Trayectoria: " + traj_list[lim_index]['Tag'])
        print("Moviendose a "+str(s_p0)+'-'+str(s_p1))
        trap_move_to_start(odrv, [s_p0, s_p1])
        robo_sleep(.2)
        iter_result = evo_ML.evo_gains_ML(
            odrv, traj_list[lim_index]['Trajectory'], training_tag+'.json')
        print("--------------------------------------------------")
        print("Ganador del ejercicio = ")
        print(iter_result['gains'])
        print()

    ML_data.build_ML_training_set(training_tag+'.json', training_tag+'.csv')
    ML.robo.idle(odrv)


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


'''
def move_to_traj_start(odrv, p_list):

    configure.gains(odrv, 25, .25, .4)
    configure.trap_traj(odrv, vel_lim=1, accel_lim=3)

    for a in range(len(axis)):
        axis[a].controller.config.input_mode = INPUT_MODE_TRAP_TRAJ
        axis[a].controller.input_pos = (axis[a].encoder.pos_estimate%1)//.5
        robo_sleep(.2)
    robo_sleep(.5)

    for a in range(len(axis)):
        axis[a].requested_state = 1
        axis[a].encoder.set_linear_count(0)
        axis[a].controller.input_pos = 0
        robo_sleep(.015)
        axis[a].requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL

    for a,targ_pos, in enumerate(p_list):
        safe_pos = targ_pos/abs(targ_pos)*(abs(targ_pos)%.5-
                    (abs(targ_pos)%1)//.5*.5)
        axis[a].controller.input_pos = safe_pos
    robo_sleep(.6)
    input("A3")
    for a,real_pos in enumerate(p_list):
        axis[a].requested_state = 1
        axis[a].encoder.set_linear_count(real_pos)
        axis[a].controller.input_pos = real_pos
        robo_sleep(.015)
        axis[a].requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        axis[a].controller.config.input_mode = INPUT_MODE_PASSTHROUGH
        robo_sleep(.015)

    return "DONE START TRAJ"
'''
