'''
Created on May 29, 2017

@author: Cristian
'''

from UndirectedGraph import*


class Ui():
    '''
    classdocs
    '''


    def __init__(self, graph):
        '''
        Constructor
        '''
        self.__graph = graph
        
    
    @staticmethod
    def printMenu():
        string = "\tThe menu:\n"
        string +="1 - Get the number of vertices;\n"
        string +="0 - Exit!"
        print(string)
        
        
        
    def mainMenu(self):
        stop = False
        while stop==False:
            Ui.printMenu()
            command = input("Enter the command: ")
            if command=="0":
                stop = True
            elif command=="1":
                n = len(self.__graph.parseX())
                print("\nThe graph has %d vertices.\n" %(n))