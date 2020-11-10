from datetime import datetime
import time

def check_sleep(amount):
    start = datetime.now()
    time.sleep(amount)
    end = datetime.now()
    delta = end-start
    return delta.seconds + delta.microseconds/1000000.

def get_sleep_error(mint=1, maxt=6, tinter=1):
    errs = []
    for sleep_time in range(mint, maxt, tinter):
        error = sum(abs(check_sleep(sleep_time/1000)-sleep_time/1000) for i in range(100))*10
        print("Requested sleep time is %0.3fms" % (sleep_time/1))
        print("Average error is %0.2fms" % error)
        errs.append(error)

    return sum(errs)/len(errs)/1000
