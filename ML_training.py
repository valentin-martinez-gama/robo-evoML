import json\import time

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

    ML.robo.start(odrv)
    #Opcion de randomizar orden de lista de trajectorias
    for i in range(num_evos):
        s_p0 = odrv.axis0.controller.input_pos=traj_list[i%len(traj_list)]['Trajectory'][0][0]
        s_p1 = odrv.axis0.controller.input_pos=traj_list[i%len(traj_list)]['Trajectory'][1][0]
        move_to_traj_start(odrv, [s_p0,s_p1])
        print("Ejecutando ejercicio de entrenamiento "+str(i))
        print("Trayectoria: "+traj_list[i]['Tag'])
        time.sleep(.2)
        iter_result = evo_ML.evo_gains_ML(odrv, traj_list[i]['Trajectory'], training_tag+'.json')
        print("Ganador del ejercicio = ")
        print(iter_result['gains'])

    ML_data.build_ML_training_set(training_tag+'.json', training_tag+'.csv')

def move_to_traj_start(odrv, p_list):

    ML.robo.configure.gains(odrv, 25, .25, .4)
    ML.robo.configure.trap_traj(odrv, vel_lim=1, accel_lim=3)
    axis = [odrv.axis0, odrv.axis1]

    for a in axis:
        a.controller.config.input_mode = INPUT_MODE_TRAP_TRAJ
        a.controller.input_pos = (a.encoder.pos_estimate%1)//.5
        time.sleep(.2)
    time.sleep(.5)

    for a in axis:
        a.encoder.set_linear_count(0)
        a.controller.input_pos = 0
        time.sleep(.015)

    for targ_pos,a in p_list,axis:
        safe_pos = targ_pos/abs(targ_pos)*(abs(targ_pos)%.5-(abs(targ_pos)%1)//.5*.5)
        a.controller.input_pos = safe_pos
    time.sleep(.6)

    for real_pos,a in p_list,axis:
        a.encoder.set_linear_count(real_pos)
        a.controller.input_pos = real_pos
        time.sleep(.015)

    return "DONE START TRAJ"
