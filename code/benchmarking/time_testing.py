#!/usr/bin/env python

# name    :  time_testing.py
# version :  0.0.1
# date    :  20241115
# author  :  
# desc    :  

import time


start_time = time.perf_counter()
time.sleep(1.78)
stop_time = time.perf_counter()
print("{:3f} time units".format(stop_time - start_time))

