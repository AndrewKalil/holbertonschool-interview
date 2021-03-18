#!/usr/bin/python3
"""contains the nqueens code"""

from sys import argv, exit


def queens(N, i, j, my_list):
    """
    place queens recursively
    :param N: chessboard dimension
    :param i: row
    :param j: column
    :param my_list:
    :return:n queens
    """
    while i < N:
        if validation(i, j, my_list):
            my_list.append([i, j])
            if j == N - 1:
                print(my_list)
                my_list.pop()
            else:
                queens(N, 0, j + 1, my_list)

        i += 1

    if len(my_list) > 0:
        my_list.pop()

    return


def validation(i, j, my_list):
    """
    check if the position is valid
    :param i: rows
    :param j: columns
    :param my_list: previously tested positions
    :return: TRUE if valid, FALSE if not
    """
    rows = []
    cols = []
    diag1 = []
    diag2 = []

    for elem in my_list:
        # rows and columns
        rows.append(elem[0])
        cols.append(elem[1])

        # diagonals
        diag1.append(elem[0] + elem[1])
        diag2.append(elem[1] - elem[0])

    if i in rows or j in cols:
        return False

    if i + j in diag1 or j - i in diag2:
        return False

    return True


if __name__ == "__main__":

    length = len(argv)
    if length != 2:
        print("Usage: nqueens N")
        exit(1)

    if argv[1].isdigit() is False:
        print("N must be a number")
        exit(1)

    N = int(argv[1])

    if N < 4:
        print("N must be at least 4")
        exit(1)

    positions = []

    queens(N, 0, 0, positions)
