'''
Created on Jan 30, 2017

@author: Cristian
'''
from Sentence import *
import random
class Repository():
    '''
    class for repo
    '''


    def __init__(self):
        '''
        Constructor for repo
        '''
        self.__stringList = []
        
    def findSentence(self,string):
        '''
        finds if there are duplicate strings
        '''
        for i in self.__stringList:
            if i==string:
                return 0
        return -1
        
    def readFile(self,fileName):
        '''
        reads the sentences from a file
        '''
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
        self.__stringList = result
        
    def writeFile(self,fileName):
        try:
            f = open(fileName,"w")
            for a in self.__stringList:
                string = str(a.getCorrect())+"\n"
                f.write(string)
            f.close()
        except Exception as e:
            print("Error: "+str(e))
            
    def addElement(self,el):
        '''
        adds an string into the string list
        '''
        self.__stringList.append(el)
        
    def getRandomString(self):
        '''
        returns a random string from the list
        '''
        x = random.randint(0,len(self.__stringList)-1)
        return str(self.__stringList[x])
    
    def getElement(self,index):
        return self.__stringList[index]
    
    def removeAll(self):
        self.__stringList.clear()
    
    def getAll(self):
        return self.__stringList
        
    def __str__(self):
        string = "dsadsa"
        for i in range(len(self.__stringList)):
            string +=str(self.__stringList[i].getCorrect())+"\n"
        return string
            
    def __len__(self):
        return len(self.__stringList)
            
def testrepo():
    a = Repository()
    a.addElement(Sentence("ana"))
    a.addElement(Sentence("el"))
    assert len(a)==2
    assert a.findSentence("ana")==-1
testrepo()