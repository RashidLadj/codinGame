"""
 @file Power_of_Thor_EP1.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-10-11
 
 @copyright Copyright (c) 2021
"""

light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]
deltaX, deltaY = None, None

# /** Game loop **/ #
while True:
    remaining_turns = int(input())  # The remaining amount of turns Thor can move. Do not remove this line.
    
    if deltaX == None:
        deltaX = light_x - initial_tx
        deltaY = light_y - initial_ty

    result = ""

    if deltaY > 0:
        result += "S"
        deltaY -= 1

    elif deltaY < 0:
        result += "N"
        deltaY += 1
    
    if deltaX > 0:
        result += "E"
        deltaX -= 1
    
    elif deltaX < 0:
        result += "W"
        deltaX += 1

    # A single line providing the move to be made: N NE E SE S SW W or NW
    print(result)