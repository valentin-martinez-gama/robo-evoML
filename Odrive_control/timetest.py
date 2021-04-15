import time


def robo_sleep(duration, get_now=time.perf_counter):
    now = get_now()
    end = now + duration
    while now < end:
        now = get_now()


def check_time_sleep(amount):
    start = time.perf_counter()
    time.sleep(amount)
    end = time.perf_counter()
    return end-start


def check_robo_sleep(amount):
    start = time.perf_counter()
    robo_sleep(amount)
    end = time.perf_counter()
    return end-start


def get_robo_sleep_error(mint=1000, maxt=17000, tinter=2000):
    errs = []
    reps = 50
    for sleep_time in range(mint, maxt, tinter):
        error = sum([check_robo_sleep(sleep_time/1000000)-sleep_time/1000000
                    for i in range(reps)])/reps
        # print("Requested sleep time is %0.3fms" % (sleep_time/1))
        errs.append(error)
        print(error)

    sleep_err = sum(errs)/len(errs)
    print("Average robo_sleep() error is %0.5fms" % (sleep_err*1000))
    return sleep_err


def get_time_sleep_error(mint=1000, maxt=17000, tinter=2000):
    errs = []
    reps = 50
    for sleep_time in range(mint, maxt, tinter):
        error = sum([check_time_sleep(sleep_time/1000000)-sleep_time/1000000
                    for i in range(reps)])/reps
        # print("Requested sleep time is %0.3fms" % (sleep_time/1))
        errs.append(error)
        print(error)

    sleep_err = sum(errs)/len(errs)
    print("Average time.sleep() error is %0.5fms" % (sleep_err*1000))
    return sleep_err


def get_input_pos_delay(odrv, iters=50):
    delays = []

    p_init_0 = odrv.axis0.encoder.pos_estimate
    p_init_1 = odrv.axis1.encoder.pos_estimate

    outbound = [i*(10/360)/(iters//2) for i in range(0, iters//2)]
    ret = list(outbound)
    ret.reverse()
    points = (outbound+ret)

    for p in points:
        start = time.perf_counter()
        odrv.axis0.controller.input_pos = p + p_init_0
        odrv.axis1.controller.input_pos = p + p_init_1
        end = time.perf_counter()
        delays.append(end-start)
        time.sleep(.01)

    input_del = sum(delays)/len(delays)
    print("Average input_pos execution time is %0.5fms" % (input_del*1000))
    return input_del


def get_info_read_delay(odrv, iters=50):
    p_init_0 = odrv.axis0.encoder.pos_estimate
    p_init_1 = odrv.axis1.encoder.pos_estimate

    outbound = [i*(-10/360)/(iters//2) for i in range(0, iters//2)]
    ret = list(outbound)
    ret.reverse()
    points = (outbound+ret)

    estimates_a0 = []
    estimates_a1 = []
    inputs = []
    currents_a0 = []
    currents_a1 = []
    delays = []

    for i, p in enumerate(points):
        odrv.axis0.controller.input_pos = p + p_init_0
        odrv.axis1.controller.input_pos = p + p_init_1
        time.sleep(.01)

        start = time.perf_counter()
        inputs.append(p)
        estimates_a0.append(odrv.axis0.encoder.pos_estimate)
        currents_a0.append(odrv.axis0.motor.current_control.Iq_setpoint)
        estimates_a1.append(odrv.axis1.encoder.pos_estimate)
        currents_a1.append(odrv.axis1.motor.current_control.Iq_setpoint)
        end = time.perf_counter()
        delays.append(end-start)

    read_del = sum(delays)/len(delays)
    # print("Average read_info execution time is %0.5fms" % (read_del*1000))
    return read_del
