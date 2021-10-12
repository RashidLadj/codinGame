"""
 @file Horse_Racing_Duals.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-10-12
 
 @copyright Copyright (c) 2021
"""

n = int(input())
myList = []
for i in range(n):
    myList.append(int(input()))

myList = sorted(myList)

diff = -1
for i in range (1, n):
    d = abs(myList[i] - myList[i-1])
    if d < diff or diff == -1:
        diff = d
print(diff)

