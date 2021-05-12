from evo_Models.alfaModel import evo_Model
import time
from Odrive_control.timetest import robo_sleep
import numpy as np


class beta_Model(evo_Model):

    def __init__(self, odrv, training_tag):
        evo_Model.__init__(self, odrv, training_tag)
        self.midpoints = 4
        self.Individual = self.beta_Individual

    VERSION = "0.2"
    plot = False
    # EXECUTION TIME TOLERANCES
    EXEC_TOLERANCE = 8/100
    RESET_DELAYS = 3
    SAMPLES_ERROR_TEST = 50
    tolerance_fails = 0
    input_delay = .0015
    ML_input_delay = .0035
    delay_adjust = .6
    # SAMPLING AND TRAJECTORY
    T_INPUT = .02  # SECONDSW
    traj = []
    # VIBRATION TEST TOLERANCES ++ = MORE FLEXIBILITY
    STATIC_TEST_TIME = .25
    # EVOLUTONARY PARAMETERS
    MAX_GENERATIONS = 8
    INF_CYCLE = False
    population = []
    plot_group = []
    POP_SIZE = 16
    ELITES = 3
    SURVIVORS = 8
    MUTTS = 9
    MUTT_RATE = .2
    # SAFETY LIMITS
    K_RANGE = (40, 90)
    k_limits = ((K_RANGE[0], K_RANGE[1]),
                (lambda kp: .052+.00020*kp, lambda kp: .48*1.2-.005*kp),
                (0, lambda kp, kv: 1.25-.0075*kp + kv*5))

    class beta_Individual(evo_Model.Individual):

        def traj_test(indiv):
            traj = indiv._outer.traj
            odrv = indiv._outer.odrv
            midpoints = indiv._outer.midpoints
            tot_time = indiv._outer.T_INPUT*len(traj)
            success = False

            while not success:
                pset_0 = lp0 = traj[0][0]
                pset_1 = lp1 = traj[0][1]
                odrv.axis0.controller.input_pos = pset_0
                odrv.axis1.controller.input_pos = pset_1
                robo_sleep(indiv._outer.T_INPUT-indiv._outer.input_delay)

                start = time.perf_counter()
                for p in traj:
                    odrv.axis0.controller.input_pos = p[0]
                    odrv.axis1.controller.input_pos = p[1]

                    for i in range(1, midpoints+1):
                        robo_sleep(indiv._outer.T_INPUT/midpoints -
                                   (indiv._outer.input_delay+indiv._outer.data_delay) *
                                   indiv._outer.delay_adjust)

                        indiv._t_pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                        indiv._t_pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
                        indiv._t_Iq_set_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
                        indiv._t_Iq_set_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
                        indiv._t_pos_set_a0.append((p[0]-lp0)/midpoints*i+lp0)
                        indiv._t_pos_set_a1.append((p[1]-lp1)/midpoints*i+lp1)

                    lp0 = p[0]
                    lp1 = p[1]
                end = time.perf_counter()

                exec_time = end-start
                if abs(exec_time-tot_time) < tot_time*indiv._outer.EXEC_TOLERANCE:
                    success = True
                else:
                    print("ERROR EN TIMEPO = " + str(exec_time-tot_time))
                    indiv._outer.correct_delay_error(pset_0, pset_1)

        def calc_error(indiv):
            traj_error_a0 = sum(
                np.abs(np.subtract(indiv._t_pos_set_a0, indiv._t_pos_estimate_a0)))
            traj_error_a1 = sum(
                np.abs(np.subtract(indiv._t_pos_set_a1, indiv._t_pos_estimate_a1)))
            stat_error_a0 = sum(
                np.abs(np.subtract(indiv._s_pos_set_a0, indiv._s_pos_estimate_a0)))
            stat_error_a1 = sum(
                np.abs(np.subtract(indiv._s_pos_set_a1, indiv._s_pos_estimate_a1)))
            return (traj_error_a0, traj_error_a1, stat_error_a0, stat_error_a1)

    def I_am(self):
        print("I am Beta")
