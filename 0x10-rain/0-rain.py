#!/usr/bin/env python3

def rain(walls):
    if not isinstance(walls, list) and len(walls) < 2:
        return 0

    if not all(isinstance(n, int) for n in walls):  # any no integer
        return 0

    rain = 0
    for i in range(1, len(walls) - 1):

        # Find the maximum element on its left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Find the maximum element on its right
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        # Update the maximum of rain collected
        rain += (min(left, right) - walls[i])

    return rain
