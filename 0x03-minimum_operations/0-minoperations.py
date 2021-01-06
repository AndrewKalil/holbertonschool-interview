#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    if type(n) != int or n < 0:
        return 0

    res = 0
    i = 2
    while i <= n:
        if n % i == 0:
            res += i
            n = n / i
            i = i - 1
        i = i + 1
    return int(res)
