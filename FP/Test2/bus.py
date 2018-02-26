'''
Created on Jan 13, 2017

@author: Cristian
'''

class Bus(object):
    '''
    classdocs
    '''


    def __init__(self, Id, routecode, model, timeused):
        '''
        Constructor
        '''
        self.__Id = Id
        self.__routeCode = routecode
        self.__model = model
        self.__timeUsed = timeused
        
    def getId(self):
        return self.__Id
    
    def setId(self, value):
        self.__Id = value
        
    def getRouteCode(self):
        return self.__routeCode
    
    def setRouteCode(self, value):
        self.__routeCode = value
        
    def getModel(self):
        return self.__model
    
    def setModel(self, value):
        self.__model = value
        
    def getTimeUsed(self):
        return self.__timeUsed
    
    def setTimeUsed(self, value):
        self.__timeUsed = value
        
    def __str__(self):
        return "Id=" + str(self.__Id)+ "  " + "Route code="+str(self.__routeCode) + "  "+ "Model="+ self.__model+ "  " + "Time used=" + str(self.__timeUsed)+ "\n"