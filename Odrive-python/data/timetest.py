import time
from math import floor, log, ceil

import control.trajectory as trajectory

def check_sleep(amount):
    start = time.perf_counter()
    time.sleep(amount)
    end = time.perf_counter()
    return end-start

def get_sleep_error(mint=1, maxt=5+1, tinter=1):
    errs = []
    for sleep_time in range(mint, maxt, tinter):
        error = sum(check_sleep(sleep_time/1000)-sleep_time/1000 for i in range(100))*8
        print("Requested sleep time is %0.3fms" % (sleep_time/1))
        errs.append(error)

    sleep_err = sum(errs)/len(errs)/1000
    print("Average time.sleep() error is %0.5fs" % sleep_err)
    return sleep_err

def get_input_pos_delay(odrv, iters=100):
    delays = []
    last = max(51, iters)
    step = max(floor((last-1)/iters), 1)
    midpoint = round(last/2)
    magnitude = ceil(log(iters,10))

    outbound = [i/10**magnitude for i in range(0, last, step*2)]
    ret = list(outbound)
    ret.reverse()
    points = (outbound+ret)

    for p in points:
        start = time.perf_counter()
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        end = time.perf_counter()
        delays.append(end-start)
        time.sleep(1/iters)

    odrv.axis0.controller.input_pos = 0
    odrv.axis1.controller.input_pos = 0

    input_del = sum(delays)/len(delays)
    print("Average input_pos execution time is %0.5fms" % input_del)
    return input_del

def get_info_read_delay(odrv, iters=25):
    traj = trajectory.build_trajectory()

    sample_interval = (len(traj["OUTBOUND"])+len(traj["RETURN"]))//iters
    out_time = traj["OUT_PERIOD"]
    ret_time = traj["RET_PERIOD"]
    sample_diff = len(traj["OUTBOUND"])%sample_interval

    estimates_a0 = []
    estimates_a1 = []
    inputs = []
    currents_a0 = []
    currents_a1 = []
    delays = []

    for i, p in enumerate(traj["OUTBOUND"]):
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(out_time)
        if ((i-1)%sample_interval == sample_interval-1):
            start = time.perf_counter()
            inputs.append(p)
            estimates_a0.append(odrv.axis0.encoder.pos_estimate)
            currents_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
            estimates_a1.append(odrv.axis1.encoder.pos_estimate)
            currents_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
            end = time.perf_counter()
            delays.append(end-start)
    for i, p in enumerate(traj["RETURN"]):
        odrv.axis0.controller.input_pos = p
        odrv.axis1.controller.input_pos = p
        time.sleep(ret_time)
        if ((i-1+sample_diff)%sample_interval == sample_interval-1):
            start = time.perf_counter()
            inputs.append(p)
            estimates_a0.append(odrv.axis0.encoder.pos_estimate)
            currents_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
            estimates_a1.append(odrv.axis1.encoder.pos_estimate)
            currents_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
            end = time.perf_counter()
            delays.append(end-start)

    read_del = sum(delays)/len(delays)
    print("Average read_info execution time is %0.5fms" % read_del)
    return read_del
