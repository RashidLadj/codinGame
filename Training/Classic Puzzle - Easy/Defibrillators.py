"""
 @file Defibrillators.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-10-12
 
 @copyright Copyright (c) 2021
"""

import math

lon, lat, n = float(input().replace(",",".")), float(input().replace(",",".")), int(input())

defibs = []
distance, pos = None, 0

for i in range(n):
    defibs.append(input().split(";"))
    defibs[i][4] = float(defibs[i][4].replace(",","."))
    defibs[i][5] = float(defibs[i][5].replace(",","."))
    
    x = (lon - (defibs[i][4])) * math.cos((lat + defibs[i][5]) / 2)
    y = lat - defibs[i][5]
    d = math.sqrt(pow(x, 2) + pow(y, 2)) * 6371

    if distance == None or distance > d :
        distance = d
        pos = i

print(defibs[pos][1])
