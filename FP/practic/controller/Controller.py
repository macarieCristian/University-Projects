'''
Created on Jan 23, 2017

@author: Madalina
'''
from random import randint
import copy
class Controller:
    def __init__(self, repo):
        self.__repo = repo
        self._correct = self._chooseRandom()
        self._guess = self.shuffle()
        
    def _chooseRandom(self):
        '''
        Chooses a random number between 0 and the total number of sentences from the list and returns
        the sentence on that position.
        '''
        
        index = randint(0, len(self) - 1)
        
        return self.getAll()[index]
    
    def swap(self, firstWord, firstLetter, secondWord, secondLetter):
        '''
        Swaps the letter at position [firstWord][firstLetter] with [secondWord][secondLetter]
        input - 4 integers
        '''
        
        if len(self._guess[0]) == 1:
            self._guess[firstLetter], self._guess[secondLetter] = self._guess[secondLetter], self._guess[firstLetter]
        else:
            self._guess[firstWord][firstLetter], self._guess[secondWord][secondLetter] = self._guess[secondWord][secondLetter], self._guess[firstWord][firstLetter]
    
    def shuffle(self):
        '''
        Shuffles a sentence.
        If the length of the sentence is 1, uses 5 switches. Otherwise, uses 10 switches.
        '''
        
        self._guess = copy.deepcopy(self._correct)
        if len(self._guess[0]) > 1:
            for i in range(0, 11):
                firstWord = randint(0, len(self._guess) - 1)
                while len(self._guess[firstWord]) < 3:
                    firstWord = randint(0, len(self._guess) - 1)
                secondWord = randint(0, len(self._guess) - 1)
                while len(self._guess[secondWord]) < 3:
                    secondWord = randint(0, len(self._guess) - 1)
                    
                if len(self._guess[firstWord]) == 3:
                    firstLetter = 1
                else:
                    firstLetter = randint(1, len(self._guess[firstWord]) - 2)
                if len(self._guess[secondWord]) == 3:
                    secondLetter = 1
                else:
                    secondLetter = randint(1, len(self._guess[secondWord]) - 2)
                
                self._guess[firstWord][firstLetter], self._guess[secondWord][secondLetter] = self._guess[secondWord][secondLetter], self._guess[firstWord][firstLetter]

        else:
            for i in range(0, 6):
                firstLetter = randint(1, len(self._guess) - 2)
                secondLetter = randint(1, len(self._guess) - 2)
                while secondLetter == firstLetter:
                    secondLetter = randint(1, len(self._guess) - 2)
                self._guess[firstLetter], self._guess[secondLetter] = self._guess[secondLetter], self._guess[firstLetter]
                  
        return self._guess
    
    def getGuess(self):
        return self._guess
    
    def getCorrect(self):
        return self._correct
    
    def getAll(self):
        return self.__repo.getAll()
    
    def __str__(self):
        return str(self.__repo)
    
    def __len__(self):
        return len(self.__repo)
    