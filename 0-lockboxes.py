#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened """

    found_keys = []
    for i in range(len(boxes)):
        for j in range(len(boxes[i])):
            if i < boxes[i][j] < len(boxes):
                found_keys.append(boxes[i][j])
        if len(boxes[i]) == 0 and i == len(boxes) - 1:
            found_keys.append(0)
    if len(found_keys) == len(boxes):
        return True
    else:
        return False
