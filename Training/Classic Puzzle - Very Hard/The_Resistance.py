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


def solve(sequence, start):
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

    if (start == len(sequence)):
        return 1

    for morseWord in morseWords:
        if morseWord == sequence[start: start + len(morseWord)]: 
            counter += solve(sequence , start + len(morseWord))
    
    return counter


##########  Read Data ##########
morseWords = [] # list of words in the dictionary coded in Morse code

morseSequence = input()
dictionarySize = int(input())

for i in range(dictionarySize):
    morseWords.append( toMorse(input())) # get word, convert it to morse langage, and add it to out list

##########  solve problem ##########
print (solve (morseSequence, 0))