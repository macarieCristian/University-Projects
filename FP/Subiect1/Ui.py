'''
Created on Jan 28, 2017

@author: Cristian
'''
from Controller import *
class Ui():
    '''
    class for ui
    '''


    def __init__(self, controller):
        '''
        Constructor
        '''
        self.__controller = controller
        
    def mainMenu(self):
            print("Hi!")
            ok = False
        #try:
            while ok == False:
                command = input("Enter the command: \n")
                if command.strip()=="exit":
                    ok = True
                elif command[:4]=="add ":
                    command = command[4:]
                    command = command.split(";")
                    self.__controller.addQuestion(int(command[0]),command[1],command[2],command[3],command[4],command[5],command[6])
                    Ui.printList(self.__controller.getAll())
                elif command[:7]=="create ":
                    command = command[7:]
                    command = command.split(" ")
                    try:
                        self.__controller.createQuizz(command[0],command[1],command[2])
                    except Exception as e:
                        print("Error: "+str(e))
                elif command[:6]=="start ":
                    command = command[6:]
                    self.__controller.startQ(command)
                    score = 0
                    for i in range(len(self.__controller)):
                        print("\n"+str(self.__controller.getElement(i)))
                        answer = str(input("your answer is:"))
                        score += self.__controller.verifyq(i,answer)
                    print("\n Your score is:",score)
                else:
                    print("Invalid Command!")
        #except Exception as e:
            #print("Error: "+str(e))
            
    @staticmethod
    def printList(l):
        for e in l:
            print(str(e))