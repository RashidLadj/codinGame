"""
 @file Chunk_Norris.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-10-12
 
 @copyright Copyright (c) 2021
"""

message = input()
binaryM = ''.join(f'{ord(i):07b}' for i in message)
temp = -1
result = ""
for current in binaryM:
    if current != temp:
        if temp != -1:
            result += " "
        result += "0 " if current == '1' else "00 "
        temp = current
    result += "0"
print(result)