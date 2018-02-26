'''
Created on Jan 30, 2017

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
        self.__controller = controller
    
    @staticmethod
    def printList(lista):
        for i in lista.getAll():
            print(str(i))
            
    def mainMenu(self):
        print("Hi\n")
        ok = False
        while ok ==False:
            try:
                command = input("Enter the command:\n")
                if command.strip()=="add":
                    a = input("Enter the string:")
                    self.__controller.addString(a)
                    Ui.printList(self.__controller.getAll())
                elif command.strip()=="write":
                    self.__controller.write("fila")
                elif command.strip()=="exit":
                    ok = True
                elif command.strip()=="start":
                    ok1 = False
                    lista = ["h","a","n","g","m","a","n"]
                    i = 0
                    string = ""
                    print(str(self.__controller.getPrintString()),"   ",string)
                    while ok1==False:
                        letter = input("Enter a letter: ").strip()
                        a = self.__controller.updateTheString(letter)
                        if a==-1:
                            string +=lista[i]
                            i +=1
                            print(str(self.__controller.getPrintString()),"   ",string)
                        else:
                            self.__controller.updateTheString(letter)
                            print(str(self.__controller.getPrintString()),"   ",string)
                        if self.__controller.verify(self.__controller.getPrintString())==1:
                            ok1 = True
                            print("Win!")
                        if len(string)==len(lista):
                            ok1 = True
                            print("Loser")
                else:
                    print("Invalid Command!")
            except Exception as e:
                print(str(e))