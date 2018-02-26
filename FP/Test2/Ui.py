'''
Created on Jan 13, 2017

@author: Cristian
'''
from Controller import *

class Ui():
    '''
    classdocs
    '''


    def __init__(self, controller):
        
        self.__controller = controller
        
    @staticmethod
    def printMenu():
        string = "\tAvailable commands= \n"
        string += "1 - Display buses on rute given\n"
        string += "2 - Use bus\n"
        string += "3 - Buses ordered\n"
        string += "0 - Exit"
        print(string)
        
    @staticmethod
    def readInteger(message):
        '''
        Reads a positive integer number
        Input: message - the message to be displayed on the read command
        '''
        result = None
        while result == None:
            try:
                result = int(input(message))
                if result < 0:
                    result = None
                    raise ValueError
            except ValueError:
                print("Please enter a positive number\n")
        return result
    
    @staticmethod
    def printList(l):
        '''
        Prints a given list
        '''
        for e in l:
            print('\t' + str(e))
        
    def menu(self):
        '''
        the menu function
        '''
        stop = False
        while stop == False:
            #try:
                Ui.printMenu()
                command = input("Enter the command=")
                if command == "0":
                    stop = True
                elif command == "1":
                    try:
                        a = Ui.readInteger("Enter route code=")
                        lista = self.__controller.filterBuses(a)
                        Ui.printList(lista)
                    except ControllerException as e:
                        print(e)
                elif command == "2":
                    #try:
                        a = Ui.readInteger("Enter bus id=")
                        b = Ui.readInteger("Enter route code=")
                        self.__controller.use(a,b)
                    #except ControllerException as e:
                        #print(e)
                elif command == "3":
                    #try:
                        lista = self.__controller.sortDescending()
                        Ui.printList(lista)
                    #except ControllerException as e:
                        #print(e)
            #except Exception as e:
                #print(str(e))