'''
Created on Jan 13, 2017

@author: Cristian
'''
from BusRepository import BusRepository
from RouteRepository import RouteRepository

class Controller():
    '''
    class for the controller
    '''


    def __init__(self, busList, routeList):
        '''
        Constructor for the controller class
        '''
        self.__busList = busList
        self.__routeList = routeList
        
    def use(self, busid, routecode):
        '''
        increase the usage of the bus with the given id
        '''
        if (self.__busList.findId(busid)==-1)or(self.__routeList.findRouteCode(routecode)==-1):
            raise ControllerException("Invalid!")
        else:
            a = self.__busList.findId(busid)
            b = self.__busList.getElement(a).getTimeUsed()
            self.__busList.getElement(a).setTimeUsed(b+1)
           
    def computeKm(self, busId, routecode):
        '''
        returns the number of km
        '''
        a = self.__busList.findId(busId)
        b = self.__routeList.findRouteCode(routecode)
        return self.__busList.getElement(a).getTimeUsed()*self.__routeList.getElement(b).getLenght()
    
    def sortDescending(self):
        '''
        sort the busses descending
        '''
        ok = True
        while ok==True:
            ok = False
            for i in range(len(self.__busList)-1):
                a = self.__busList.computeKm(self.__busList.getElement(i).getId(),self.__busList.getElement(i).getRouteCode())
                b = self.__busList.computeKm(self.__busList.getElement(i+1).getId(),self.__busList.getElement(i+1).getRouteCode())
                if a<b:
                    aux = self.__busList[i]
                    self.__busList[i] = self.__busList[i+1]
                    self.__busList[i+1] = aux
                    ok = True
        
    def filterBuses(self, route):
        '''
        returns the list of the busses which have the route code route
        '''
        lista = []
        for a in self.__busList.getAll():
            if a.getRouteCode()==route:
                lista.append(a)
        return lista
        
    def getAll(self):
        '''
        returns the whole list
        '''
        return self.__controller.getAll()    
    
    def __len__(self):
        '''
        overWriting the len function
        '''
        return len(self.__controller)
    
    def __str__(self):
        '''
        returns the list in a nice looking view
        '''
        s = ""
        for i in range(len(self.__controller)):
            s += self.__controller.getPerson(i) + "\n"
        return s
        
        
class ControllerException(Exception):
    '''
    Exception class 
    '''
    def __init__(self, message):
        '''
        Constructor for controller exception
        output message
        '''
        self.__message = message

    def __str__(self):
        return self.__message
    
    