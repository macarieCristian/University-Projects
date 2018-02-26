'''
Created on Jan 9, 2017

@author: Cristian
'''
from Controller import *

class Ui():
    '''
    classdocs
    '''


    def __init__(self, controller):
        '''
        Constructor
        '''
        self.__personController = controller
        
    @staticmethod
    def printMenu():
        string = "\tAvailable commands= \n"
        string += "1 - Add a person\n"
        string += "2 - New day\n"
        string += "3 - Vaccinate a person\n"
        string += "0 - Exit"
        print(string)
        
    @staticmethod
    def readPositiveInteger(message):
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
            try:
                Ui.printList(self.__personController.getAll())
                Ui.printMenu()
                command = input("Enter the command=")
                if command == "0":
                    stop = True
                elif command == "1":
                    try:
                        a = Ui.readPositiveInteger("Enter the id=")
                        self.__personController.add(a)
                        self.__personController.sortById()
                    except ControllerException as e:
                        print(e)
                elif command == "2":
                    try:
                        self.__personController.newDay()
                        self.__personController.sortById()
                    except ControllerException as e:
                        print(e)
                elif command == "3":
                    try:
                        a = Ui.readPositiveInteger("Enter the id=")
                        self.__personController.vaccinatePerson(a)
                        Ui.printList(self.__personController.getAll())
                    except ControllerException as e:
                        print(e)
            except Exception as e:
                print(str(e))
                        
                    
                    
                    
                    
                    
    