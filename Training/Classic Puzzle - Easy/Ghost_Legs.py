"""
 @file Ghost_Legs.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-10-12
 
 @copyright Copyright (c) 2021
"""

w, h = [int(i) for i in input().split()]
myMatrix= []
for i in range(h):
    myMatrix.append(input())

for j in range (0, w, 3):
    actualCol = j
    actualLine = 0
    
    while actualLine != h - 1:   
        if actualCol >= 3 and myMatrix[actualLine][actualCol-1] == '-' :
            actualCol -= 3

        elif actualCol <= w-3 and myMatrix[actualLine][actualCol+1] == '-':
            actualCol += 3

        actualLine += 1


    print(myMatrix[0][j]+myMatrix[actualLine][actualCol])