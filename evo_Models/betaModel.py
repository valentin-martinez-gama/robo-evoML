from evo_Models.alfaModel import evo_Model
import time
import numpy as np
from Odrive_control.timetest import robo_sleep


class beta_Model(evo_Model):

    def __init__(self, odrv, training_tag):
        evo_Model.__init__(self, odrv, training_tag)

        print("Input_delay = " + str(self.input_delay))
        print("Data_delay = " + str(self.data_delay))

    def I_am(self):
        print("I am Beta")

    def test_trajectory(self):
        odrv = self.odrv
        traj = self.traj
        tot_time = self.T_INPUT*len(traj)

        success = False
        while not success:
            pos_set_a0 = []
            pos_set_a1 = []
            pos_estimate_a0 = []
            pos_estimate_a1 = []

            pset_0 = traj[0][0]
            pset_1 = traj[0][1]
            odrv.axis0.controller.input_pos = pset_0
            odrv.axis1.controller.input_pos = pset_1
            robo_sleep(self.T_INPUT-self.input_delay)

            start = time.perf_counter()
            for p in traj:
                for i in self.midpoints:

                pos_set_a0.append(p[0])
                pos_set_a1.append(p[1])
                pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
                pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)

                odrv.axis0.controller.input_pos = p[0]
                odrv.axis1.controller.input_pos = p[1]

                robo_sleep(self.T_INPUT-(self.input_delay+self.data_delay)*.75)

            end = time.perf_counter()
            pset_0 = p[0]
            pset_1 = p[1]

            exec_time = end-start
            if abs(exec_time-tot_time) < tot_time*self.EXEC_TOLERANCE:
                success = True
            else:
                self.TOLERANCE_FAILS += 1
                if self.TOLERANCE_FAILS >= self.RESET_DELAYS:
                    print("ERROR EN TIMEPO = " + str(exec_time-tot_time))
                    self.update_time_errors(odrv, self.SAMPLES_ERROR_TEST)
                    odrv.axis0.controller.input_pos = traj[0][0]
                    odrv.axis0.controller.input_pos = traj[1][0]
                    time.sleep(.2)
                    self.TOLERANCE_FAILS = 0
        # End While not Succes loop
        for _ in range(round(self.STATIC_TEST_TIME/self.T_INPUT)):
            pos_set_a0.append(pset_0)
            pos_set_a1.append(pset_1)
            pos_estimate_a0.append(odrv.axis0.encoder.pos_estimate)
            pos_estimate_a1.append(odrv.axis1.encoder.pos_estimate)
            robo_sleep(self.T_INPUT-self.data_delay*.75)

        return {
            "pos_set_a0": pos_set_a0,
            "pos_set_a1": pos_set_a1,
            "pos_estimate_a0": pos_estimate_a0,
            "pos_estimate_a1": pos_estimate_a1
        }

    def get_exec_errors_data(self):
        traj = self.traj
        robo_sleep(.3-self.STATIC_TEST_TIME)

        data = self.test_trajectory()
        t_data = {}
        s_data = {}
        for field in data:
            t_data[field] = data[field][:len(traj)]
            s_data[field] = data[field][len(traj):]
        traj_error_a0 = sum(
            np.abs(np.subtract(t_data["pos_set_a0"], t_data["pos_estimate_a0"])))
        traj_error_a1 = sum(
            np.abs(np.subtract(t_data["pos_set_a1"], t_data["pos_estimate_a1"])))
        stat_error_a0 = sum(
            np.abs(np.subtract(s_data["pos_set_a0"], s_data["pos_estimate_a0"])))
        stat_error_a1 = sum(
            np.abs(np.subtract(s_data["pos_set_a1"], s_data["pos_estimate_a1"])))

        return (traj_error_a0, traj_error_a1, stat_error_a0, stat_error_a1,
                t_data, s_data)

        def get_info_read_delay(self, odrv, iters=50):
            p_init_0 = odrv.axis0.encoder.pos_estimate
            p_init_1 = odrv.axis1.encoder.pos_estimate
            outbound = [i*(-.027)/(iters//2) for i in range(0, iters//2)]
            ret = list(outbound)
            ret.reverse()
            points = (outbound+ret)
            pos_set_a0 = []
            pos_set_a1 = []
            pos_estimates_a0 = []
            pos_estimates_a1 = []
            delays = []
            for p in points:
                odrv.axis0.controller.input_pos = p + p_init_0
                odrv.axis1.controller.input_pos = p + p_init_1
                robo_sleep(.02)
                start = time.perf_counter()
                pos_set_a0.append(p)
                pos_set_a1.append(p)
                pos_estimates_a0.append(odrv.axis0.encoder.pos_estimate)
                pos_estimates_a1.append(odrv.axis1.encoder.pos_estimate)
                end = time.perf_counter()
                delays.append(end-start)
            read_delay = sum(delays)/len(delays)
            print("Read_info execution time is %0.5fms" % (read_delay*1000))
            return read_delay
