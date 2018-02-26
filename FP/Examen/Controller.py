'''
Created on Jan 30, 2017

@author: Cristian
'''
from Repository import *

class Controller():
    '''
    class for controller
    '''


    def __init__(self, repo):
        '''
        Constructor for controller class
        '''
        self.__repo = repo
        self.__el = Sentence(self.__repo.getRandomString())
        self.__goodString = str(self.__el.getCorrect())
        self.__printString = self.__el.getPrintSentence()
        
    def addString(self,string):
        '''
        appends a new string to the list of the repo 
        input string
        '''
        a = Sentence(string)
        lista = a.getCorrect().split(" ")
        if self.__repo.findSentence(a)==0:
            raise Exception("Duplicate string")
        for i in lista:
            if len(i)<3:
                raise Exception("sub 3 letter word!")
        self.__repo.addElement(a)
        
    def updateTheString(self,letter):
        '''
        replace the - with the corresponding letter
        '''
        lista = list(self.__printString)
        string = ""
        a=-1
        for i in range(len(self.__goodString)):
            
            if self.__goodString[i]==letter:
                lista[i]=letter
                a=0
            string = "".join(lista)
            self.__printString = string
            
        if a==-1:
            return -1
        
    def verify(self,string):
        '''
        verify if the string is done
        '''
        for i in string:
            if i=="-":
                return -1
        return 1
                
        
    def write(self,fileName):
        '''
        write to the file the repo 
        '''
        self.__repo.writeFile(fileName)
        
    def getGoodString(self):
        return str(self.__goodString)
    
    def getPrintString(self):
        return str(self.__printString)
    
    def getAll(self):
        return self.__repo
    
    def __str__(self):
        string = ""
        for i in self.__repo.getAll():
            string +=str(i)
        return string
    
    def __repr__(self):
        return str(self.__repo.getAll())
    
            