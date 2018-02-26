'''
Created on Jan 29, 2017

@author: Cristian
'''
from Repository import *

class Controller():
    '''
    classdocs
    '''


    def __init__(self, repo):
        '''
        Constructor
        '''
        self.__elem = repo.getElementRandom()
        self.__string = self.__elem.getGeneratedString()
        self.__undo = []
        self.__undo.append(self.__string)
        self.__listString = self.__string.split(" ")
        self.score = self.numberLetters()
        self.__correctString = self.__elem.getCorrectString()
        
    def getCorrectString(self):
        return self.__correctString
        
    def getString(self):
        return self.__string
        
    def numberLetters(self):
        '''
        returns the number of letters in a string
        '''
        a = self.__string.split(" ")
        a = "".join(a)
        return len(a)
    
    def getScore(self):
        return self.score
    
    def decScore(self):
        self.score -=1
    
    def changeLetters(self,w1,l1,w2,l2):
        '''
        change the letters from 2 words
        '''
        if (w1>len(self.__listString))or(w2>len(self.__listString)):
            raise Exception("wrong words indices")
        else:
            word1 = list(self.__listString[w1])
            word2 = list(self.__listString[w2])
            if (l1>len(word1))or(l2>len(word2)):
                raise Exception("wrong leter indices")
            else:
                word1[l1],word2[l2]=word2[l2],word1[l1]
                word1[l2],word2[l1]=word2[l1],word1[l2]
                word1 = "".join(word1)
                word2 = "".join(word2)
                self.__listString[w1] = word1
                self.__listString[w2] = word2
                self.__string = " ".join(self.__listString)
                self.__undo.append(self.__string)
    
    def undo(self):
        '''
        undo the last operation
        '''
        self.__undo.pop()
        self.__string = self.__undo[-1]
        
    
    