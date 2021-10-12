"""
 @file Sudoku_Validator.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-09-14
 
 @copyright Copyright (c) 2021
"""

import numpy as np
import itertools

##############################################
def solve(sudokuGrid):
    
    perfect = np.asarray([1, 2, 3, 4, 5, 6, 7, 8, 9], dtype=np.uint8)
    for i in range (9):
        test = np.sort(sudokuGrid[i, :], axis=None)
        if not np.array_equal(test, perfect):
            return False
    
    for j in range (9):
        test = np.sort(sudokuGrid[:, j], axis=None)
        if not np.array_equal(test, perfect):
            return False

    for i, j in itertools.product(range(3), range(3)):
        test = np.sort(sudokuGrid[i * 3: 3 * (i+1), j * 3 : 3 * (j+1)], axis=None)
        if not np.array_equal(test, perfect):
            return False

    return True

##############################################
mySudoku = []
for i in range(9):
    for j in input().split():
        mySudoku = np.append(mySudoku, int(j))

print("true") if solve(mySudoku.reshape((9, 9))) else print("false")