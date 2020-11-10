import time
from math import floor, log, ceil

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
