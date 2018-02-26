'''
Created on Jan 29, 2017

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
        
    def mainMenu(self):
        print("Game has begun!\n")
        ok = False
        print(str(self.__controller.getString())+" Score: "+str(self.__controller.getScore())+"\n")
        while ok == False:
            try:
                if self.__controller.getString().strip()==self.__controller.getCorrectString().strip():
                    print("Victory!!!")
                    ok = True
                elif self.__controller.getScore()==0:
                    print("Nice try loser!")
                    ok = True
                else:
                    command = input("Enter the swap: ex. swap 0 1 - 1 4\n")
                    if command[:5]=="swap ":
                        command = command[5:]
                        try:
                            w1 = int(command[0])
                            l1 = int(command[2])
                            w2 = int(command[6])
                            l2 = int(command[8])
                        except Exception as e:
                            print("Error "+str(e))
                        self.__controller.changeLetters(w1,l1,w2,l2)
                        self.__controller.decScore()
                        print(str(self.__controller.getString())+" Score: "+str(self.__controller.getScore())+"\n")
                    elif command=="undo":
                        self.__controller.undo()
                        print(str(self.__controller.getString())+" Score: "+str(self.__controller.getScore())+"\n")
                    else:
                        print("Invalid Command!")
            except Exception as e:
                print("Error: "+str(e))
                