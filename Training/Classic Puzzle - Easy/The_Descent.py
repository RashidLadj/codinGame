"""
 @file The_Descent.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2020-10-11
 
 @copyright Copyright (c) 2020
"""

# game loop
while True:
    indice = -1
    maxHeight = -1
    for i in range(8):
        mountain_h = int(input())  # represents the height of one mountain.

        if mountain_h > maxHeight : 
            maxHeight = mountain_h
            indice = i

    print(indice)