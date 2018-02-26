'''
Created on Jan 29, 2017

@author: Cristian
'''
import random

class Sentence():
    '''
    class
    '''


    def __init__(self, string):
        '''
        Constructor
        '''
        self.__correctString = string
        self.__generatedString = self.prepareString()
    
    def getCorrectString(self):
        return self.__correctString
    
    def getGeneratedString(self):
        return self.__generatedString
    
    def prepareString(self):
        '''
        randomly mix the letters in the words of the sentence
        '''
        a = self.__correctString.split(" ")
        string = ""
        for cuv in a:
            result = list(cuv)
            if len(cuv)>2:
                for i in range(5):
                    x = random.randint(1,len(cuv)-2)
                    y = random.randint(1,len(cuv)-2)
                    result[x],result[y]=result[y],result[x]
            cuv = "".join(result)
            string +=cuv+" "
        return string
                

def testPrepare():
    string = "sarmale cu salam"
    a = Sentence(string)
    assert a.getCorrectString()=="sarmale cu salam"
testPrepare()   