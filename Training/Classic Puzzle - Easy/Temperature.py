"""
 @file Temperature.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-10-11
 
 @copyright Copyright (c) 2021
"""

n = int(input())
minTemp = 5526

for temp in input().split():
    temp = int(temp)
    if abs(temp) < abs(minTemp) or (abs(temp) == abs(minTemp) and temp > minTemp):
        minTemp = temp

print(minTemp if n!=0 else 0)