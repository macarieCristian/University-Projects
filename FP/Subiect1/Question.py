'''
Created on Jan 28, 2017

@author: Cristian
'''

class Question():
    '''
    class for question
    '''


    def __init__(self, id, text, a1, a2, a3, correctAnswer, difficulty):
        '''
        Constructor
        '''
        self.__id = id
        self.__text = text
        self.__answer1 = a1
        self.__answer2 = a2
        self.__answer3 = a3
        self.__correctAnswer = correctAnswer
        self.__difficulty = difficulty
        
    def getId(self):
        return self.__id
    
    def getText(self):
        return self.__text
    
    def getA1(self):
        return self.__answer1
    
    def getA2(self):
        return self.__answer2
    
    def getA3(self):
        return self.__answer3
    
    def getCorrect(self):
        return self.__correctAnswer
    
    def getDifficulty(self):
        return self.__difficulty
    
    def __str__(self):
        return "Id="+str(self.__id)+" Question="+self.__text+" a) "+self.__answer1+" b) "+self.__answer2+" c) "+self.__answer3+" Difficulty="+self.__difficulty+"\n"