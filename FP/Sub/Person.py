'''
Created on Jan 9, 2017

@author: Cristian
'''

class Person():
    '''
    class for the person model
    '''


    def __init__(self, personId, imunStatus, status):
        '''
        Constructor for the person class
        '''
        self.__id = personId
        self.__imunStatus = imunStatus
        self.__status = status
        self.__numOfDaysInfected = 0
        
    def getId(self):
        return self.__id
    
    def setId(self, value):
        self.__id = value
        
    def getImunStatus(self):
        return self.__imunStatus
    
    def setImunStatus(self, value):
        self.__imunStatus = value
        
    def getStatus(self):
        return self.__status
    
    def setStatus(self, value):
        self.__status = value
        
    def getDays(self):
        return self.__numOfDaysInfected
    
    def incDays(self):
        self.__numOfDaysInfected +=1
        
    def __str__(self):
        return "Id=" + str(self.__id) + "  " + "Imunization Status=" + self.__imunStatus + "  " + "Status=" + self.__status + "\n"
    
        