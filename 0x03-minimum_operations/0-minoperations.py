#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    count = 0
    if type(n) != int or n < 0:
        return 0

    if n % 2 != 0:
        n -= 1
    while n > 1:
        count += 1
        count += 1
        n = n / 2

    return int(count)