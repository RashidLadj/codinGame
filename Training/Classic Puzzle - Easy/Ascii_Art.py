"""
 @file Ascii_Art.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-10-25
 
 @copyright Copyright (c) 2021
"""

length_ = int(input())
heigth_ = int(input())
input_ = input()

alphabet = [input() for i in range(heigth_)]

for x in alphabet:
    tempLigne = []
    for actual_ in input_:
        if actual_ >= 'a' and actual_ <= 'z':
            idx = ord(actual_) - ord('a')
        elif actual_ >= 'A' and actual_ <= 'Z':
            idx = ord(actual_) - ord('A')
        else:
            idx = ord('z') - ord('a') + 1
        tempLigne.append(x[idx * length_: idx * length_ + length_])

    print("".join(tempLigne))