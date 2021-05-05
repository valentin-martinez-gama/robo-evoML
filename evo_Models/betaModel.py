from evo_Models.alfaModel import evo_Model
import time
import numpy as np
from Odrive_control.timetest import robo_sleep


class beta_Model(evo_Model):

    def __init__(self, odrv, training_tag):
        evo_Model.__init__(self, odrv, training_tag)
        self.midpoints = 3
        self.plot = True
        self.Individual = self.beta_Individual

    class beta_Individual(evo_Model.Individual):
        def traj_test(indiv):
            traj = indiv._outer.traj
            odrv = indiv._outer.odrv
            midpoints = indiv._outer.midpoints
            tot_time = indiv._outer.T_INPUT*len(traj)
            success = False

            while not success:
                pset_0 = traj[0][0]
                pset_1 = traj[0][1]
                odrv.axis0.controller.input_pos = pset_0
                odrv.axis1.controller.input_pos = pset_1
                robo_sleep(indiv._outer.T_INPUT-indiv._outer.input_delay)

                start = time.perf_counter()
                for p in traj:
                    odrv.axis0.controller.input_pos = p[0]
                    odrv.axis1.controller.input_pos = p[1]

                    for i in range(1, midpoints+1):
                        robo_sleep(indiv._outer.T_INPUT/midpoints -
                                   (indiv._outer.input_delay+indiv._outer.data_delay)*.65)

                        indiv._t_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                        indiv._t_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                        indiv._t_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                        indiv._t_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                        indiv._t_pos_set_a0.append(p[0]/midpoints*i)
                        indiv._t_pos_set_a1.append(p[1]/midpoints*i)
                end = time.perf_counter()

                exec_time = end-start
                if abs(exec_time-tot_time) < tot_time*indiv._outer.EXEC_TOLERANCE:
                    success = True
                else:
                    print("ERROR EN TIMEPO = " + str(exec_time-tot_time))
                    indiv._outer.correct_delay_error(pset_0, pset_1)

    def I_am(self):
        print("I am Beta")
