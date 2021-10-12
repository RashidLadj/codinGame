"""
 @file The_Resistance.py
 @author Ladjouzi Rachid (RashidLadj@gmail.com)
 @brief 
 @version 0.1
 @date 2021-08-31
 
 @copyright Copyright (c) 2021
"""

import sys
import math

morseAlphabet = [
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
]

def toMorse (word):
    """
      Conversion of a character string from Latin alphabet to Morse code 
      Args:
              word (string): the string to convert to morse code
      Returns:
              morseWord_ (string) : Returning value
    """

    morseWord_ = ""
    for i in word:
        morseWord_ += morseAlphabet[ord(i) - 65]

    return morseWord_

def solve(sequence, start, resultTemp):
    """
      recursive function which calculates the number of sentences 
      that can be decoded from a sequence of Morse code.
      
      Args:
              Sequence (string): The character string comprising the sequence in Morse code
              start (int) : An integer representing the start of the sub-sequence to be processed
      Returns:
              counter (integer) : Returning value
    """

    counter = 0
    if start == len(sequence):
        return 1
    
    # if resultTemp[start] != math.nan:
    if not math.isnan(resultTemp[start]):
        return resultTemp[start]

    for morseWord in morseWords:
        if morseWord == sequence[start: start + len(morseWord)]: 
            occurence = morseWords[morseWord]
            counter += occurence * solve(sequence , start + len(morseWord), resultTemp)

    resultTemp[start] = counter

    return counter


##########  Read Data ##########
morseWords = {} # list of words in the dictionary coded in Morse code
resultTemp = [] # list of results for each subsequence start in index i not to calculate each time

morseSequence = input()
dictionarySize = int(input())

for i in range(dictionarySize):
    morseWord = toMorse(input())   # get word and convert it to morse langage

    # /** This is for optimization in solve method **/
    # /** if x different word have same morse code, we just give value "x" to the key "morseWord" **/
    # /** the goal is to avoid looping multiple times on equivalent words when we can just do a simple multiplication **/
    #
    if morseWord in morseWords:
        morseWords[morseWord] += 1
    else:
        morseWords[morseWord] = 1

##########  solve problem ##########
for i in range(len(morseSequence)):
    resultTemp.append(math.nan)

print( solve(morseSequence, 0, resultTemp))