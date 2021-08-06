#!/usr/bin/python3
"""Program that returns a list of lists of integers
representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """Function that returns a list of lists of integers
    representing the Pascal’s triangle of n"""
    if n <= 0:
        return []
    pascal = [[1]]
    while len(pascal) != n:
        prev = pascal[-1]
        current = [1]
        for i in range(len(prev) - 1):
            current.append(prev[i] + prev[i + 1])
        current.append(1)
        pascal.append(current)
    return pascal
