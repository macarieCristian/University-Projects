'''
Created on Jan 29, 2017

@author: Cristian
'''
from Sentence import *

class Repository():
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        '''
        self.__listStrings = []
        
    def readFile(self,fileName):
        result = []
        try:
            f = open(fileName,"r")
            line = f.readline().strip()
            while len(line)>0:
                result.append(Sentence(line))
                line = f.readline().strip()
            f.close()
        except Exception as e:
            print("Error: "+str(e))
        self.__listStrings = result
        
    def getElementRandom(self):
        '''
        returns randomly a string
        '''
        x = random.randint(0,len(self.__listStrings)-1)
        return self.__listStrings[x]