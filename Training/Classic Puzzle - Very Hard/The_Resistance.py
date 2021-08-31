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



##########  Read Data ##########
morseWords = [] # list of words in the dictionary coded in Morse code

morseSequence = input()
dictionarySize = int(input())

for i in range(dictionarySize):
    morseWords.append( toMorse(input())) # get word, convert it to morse langage, and add it to out list


##########  solve problem ##########
if morseSequence in morseWords:
  print ("1")