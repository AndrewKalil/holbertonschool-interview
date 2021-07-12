#!/usr/bin/python3
"""Program that returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """Function that returns the perimeter of the island described in grid"""
    islands = 0
    neighbours = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if (grid[i][j] == 1):
                islands += 1
                if ((i < len(grid) - 1) and (grid[i + 1][j] == 1)):
                    neighbours += 1
                if ((j < len(grid[i]) - 1) and (grid[i][j + 1] == 1)):
                    neighbours += 1
    return (islands * 4 - neighbours * 2)
