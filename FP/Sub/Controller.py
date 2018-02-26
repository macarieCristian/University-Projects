'''
Created on Jan 9, 2017

@author: Cristian
'''
from Repository import Repository

class Controller():
    '''
    class for the controller
    '''


    def __init__(self, repo):
        '''
        Constructor for the controller class
        '''
        self.__controller = repo
        
    def add(self, Id):
        '''
        adds a new person
        '''
        if self.__controller.findPerson(Id)!=-1:
            raise ControllerException("The id must be unique")
        else:
            self.__controller.addPerson(Id)
            
    def sortById(self):
        '''
        sorts the list ascending by the id
        '''
        ok = True
        while ok==True:
            ok = False
            for i in range(len(self.__controller)-1):
                a = self.__controller.getPerson(i).getId()
                b = self.__controller.getPerson(i+1).getId()
                if a>b:
                    self.__controller.getPerson(i).setId(b)
                    self.__controller.getPerson(i+1).setId(a)
                    ok = True
                    
                    
            
    def newDay(self):
        '''
        simulates a new day
        '''
        for i in self.__controller.getAll():
            if (i.getStatus()=="ill")and(i.getDays()!=3):
                i.incDays()
            if i.getDays()==3:
                i.setStatus("healty")
                
        if self.__controller.findSuitablePerson()==-1:
            raise ControllerException("You can't infect any person today")
        elif self.__controller.findIllPerson()!=-1:
            a = self.__controller.findSuitablePerson()
            self.__controller.getPerson(a).setStatus("ill")
            
    def vaccinatePerson(self, Id):
        '''
        vaccinate a person
        '''
        a = self.__controller.findPerson(Id)
        if self.__controller.getPerson(a).getStatus()=="healty":
            self.__controller.getPerson(a).setImunStatus("vaccinated")
        else:
            raise ControllerException("the person is ill")
        
    def getAll(self):
        return self.__controller.getAll()    
    
    def __len__(self):
        return len(self.__controller)
    
    def __str__(self):
        s = ""
        for i in range(len(self.__controller)):
            s += self.__controller.getPerson(i) + "\n"
        return s
        
        
class ControllerException(Exception):
    '''
    Exception class for controller errors
    '''
    def __init__(self, message):
        '''
        Constructor for controller exception class
        message - A string representing the exception message
        '''
        self.__message = message

    def __str__(self):
        return self.__message