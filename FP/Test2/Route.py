'''
Created on Jan 13, 2017

@author: Cristian
'''

class Route():
    '''
    class for
    '''


    def __init__(self, Id,lenght):
        '''
        Constructor
        '''
        self.__routeCode = Id
        self.__lenght = lenght
        
    def getRouteCode(self):
        return self.__routeCode
    
    def setRouteCode(self,value):
        self.__routeCode = value
        
    def getLenght(self):
        return self.__lenght
    
    def setLenght(self, value):
        self.__lenght = value
        
    def __str__(self):
        return "Id="+str(self.__Id) + "  "+"lenght="+str(self.__lenght)+ "\n"
        