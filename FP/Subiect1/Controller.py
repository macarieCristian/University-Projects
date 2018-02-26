'''
Created on Jan 28, 2017

@author: Cristian
'''
from Repository import *

class Controller(object):
    '''
    class for controller
    '''


    def __init__(self, repo):
        '''
        Constructor
        '''
        self.__repo = repo
        
    def __len__(self):
        return len(self.__repo)
    
    def getAll(self):
        return self.__repo.getAll()
    
    def getElement(self,index):
        return self.__repo.getElement(index)
    
    def addQuestion(self,id,text,a1,a2,a3,correct,difficulty):
        '''
        adds a new question to the list
        input data for a Question
        '''
        a = Question(id,text,a1,a2,a3,correct,difficulty)
        self.__repo.addQuestion(a)
        
    def __str__(self):
        string = ""
        for i in range(len(self.__repo)):
            string +=str(self.__repo.getElement(i))+"\n"
        return string
    
    def createQuizz(self,difficulty,numQ,fileName):
        '''
        create a new quizz if the conditions are statisfied
        input difficulty,number of questions,the name of the file
        '''
        nr = 0
        for i in range(len(self.__repo)):
            if self.__repo.getElement(i).getDifficulty()==difficulty:
                nr +=1
        if (int(numQ)>len(self.__repo))or(nr<len(self.__repo)//2):
            raise Exception
        else:
            self.__repo.writeToFile(fileName)
            
    def verifyq(self,index,answer):
        '''
        verifys if the answer was right
        returns the coresponding score
        '''
        if self.__repo.getElement(index).getCorrect()==answer.strip():
            if self.__repo.getElement(index).getDifficulty()=="easy":
                return 1
            elif self.__repo.getElement(index).getDifficulty()=="medium":
                return 2
            elif self.__repo.getElement(index).getDifficulty()=="hard":
                return 3
    
    def startQ(self,fileName):
        '''
        start a quiz
        '''
        self.__repo.removeAll()
        self.__repo.readFile(fileName)
        