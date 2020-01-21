#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import math

# input data
T = int(input().strip())

for _ in range(T):
    Xa, Ya, Xb, Yb, Xc, Yc, R = map(int, input().strip().split())

    # insert your code here

    result = 1.23456789

    # print result (round down and print six decimals)
    # DO NOT EDIT!
    result = math.floor(result * 10**6) / 10**6
    print("{:.6f}".format(result))
