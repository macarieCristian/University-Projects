from controller import *
import time

def printMenu():
	menuString = '\nAvailable commands:\n'
	menuString += '\t 1 - Add a new transaction to the list.\n'
	menuString += '\t 2 - Modify expenses from the list.\n'
	menuString += '\t 3 - Print the expenses having different properties.\n'
	menuString += '\t 4 - Obtain different characteristics of the expenses.\n'
	menuString += '\t 5 - Filter.\n'
	menuString += '\t 6 - Undo.\n'
	menuString += '\t 0 - Exit.\n'
	print(menuString)

def printSubMenu2():
        subMenuString = '\nAvailable commands:\n'
        subMenuString += '\t 2a - Remove apartament expense.\n'
        subMenuString += '\t 2b - Remove all the expenses between two apartments.\n'
        subMenuString += '\t 2c - Remove all the expenses for a type from all apartments.\n'
        subMenuString += '\t 2d - Replace the amount of the expense of a type for an apartment with the given value.\n'
        subMenuString += '\t 2e - Back to Main Menu.\n'
        print(subMenuString)
        
def printSubMenu3():
        subMenuString = '\nAvailable commands:\n'
        subMenuString += '\t 3a - Write the entire list of expenses.\n'
        subMenuString += '\t 3b - Write all expenses for the given apartament.\n'
        subMenuString += '\t 3c - Write all the apartaments having total expenses </=/> than a given value.\n'
        subMenuString += '\t 3d - Back to Main Menu.\n'
        print(subMenuString)

def printSubMenu4():
        subMenuString = '\nAvailable commands:\n'
        subMenuString += '\t 4a - Write the total amount for the expenses having the given type.\n'
        subMenuString += '\t 4b - Write the maximum amount per each expense type for the given apartment.\n'
        subMenuString += '\t 4c - Write the list of apartments sorted ascending by total amount of expenses.\n'
        subMenuString += '\t 4d - Write the total amount of expenses for each type, sorted ascending by amount of money.\n'
        subMenuString += '\t 4e - Back to Main Menu.\n'
        print(subMenuString)

def printSubMenu5():
        subMenuString = '\nAvailable commands:\n'
        subMenuString += '\t 5a - Keep only expenses for the type given.\n'
        subMenuString += '\t 5b - Keep only expenses having an amount of money smaller than a given value.\n'
        subMenuString += '\t 5c - Back to Main Menu.\n'
        print(subMenuString)

def mainMenu():
        apartamentList=[[1,"water",25],[1,"gas",225],[1,"electricity",125],[1,"water",25],[2,"heating",32],[2,"heating",323],[2,"gas",132],[2,"heating",35],[2,"other",32],[4,"electricity",44],[3,"gas",55],[5,"gas",120],[6,"other",30],[5,"water",124],[5,"gas",120],[5,"other",40],[5,"electricity",190],[20,"gas",2120],[20,"water",120]]
        undoList=[]
        addToUndoList(undoList,apartamentList)
        sortedByApartament(apartamentList)
        printAppartmentList(apartamentList)
        stop=False
        while stop==False:
                printMenu()
                command=input("Enter command:")
                if command=='1':
                        a=readApartamentValue()
                        t=readExpenseType()
                        v=readExpenseAmount()
                        addExpense(apartamentList,a,t,v)
                        sortedByApartament(apartamentList)
                        printAppartmentList(apartamentList)
                        addToUndoList(undoList,apartamentList)
                elif command=='2':
                        stop2=False
                        while stop2==False:
                                printSubMenu2()
                                command=input("Enter command:")
                                if command=='2a':
                                        a=readApartamentValue()
                                        msgErr=removeTriplet(apartamentList,a)
                                        if len(msgErr)>0:
                                                print(msgErr)
                                        else:
                                                sortedByApartament(apartamentList)
                                                printAppartmentList(apartamentList)
                                                addToUndoList(undoList,apartamentList)
                                elif command=='2b':
                                        a1=readApartamentValue()
                                        a2=readApartamentValue()
                                        msgErr=removeSqApartaments(apartamentList,a1,a2)
                                        if len(msgErr)>0:
                                                print(msgErr)
                                        else:
                                                sortedByApartament(apartamentList)
                                                printAppartmentList(apartamentList)
                                                addToUndoList(undoList,apartamentList)
                                elif command=='2c':
                                        t=readExpenseType()
                                        msgErr=removeAllExpensesWithType (apartamentList,t)
                                        if len(msgErr)>0:
                                                print(msgErr)
                                        else:
                                                sortedByApartament(apartamentList)
                                                printAppartmentList(apartamentList)
                                                addToUndoList(undoList,apartamentList)
                                elif command=='2d':
                                        a=readApartamentValue()
                                        t=readExpenseType()
                                        v=readExpenseAmount()
                                        msgErr=replaceExpenseValue(apartamentList,a,t,v)
                                        if len(msgErr)>0:
                                                print(msgErr)
                                        else:
                                                sortedByApartament(apartamentList)
                                                printAppartmentList(apartamentList)
                                                addToUndoList(undoList,apartamentList)
                                elif command=='2e':
                                        stop2=True
                                else:
                                        print("Please enter a valid command!")
                                        time.sleep(1)
                elif command=='3':
                        stop3=False
                        while stop3==False:
                                printSubMenu3()
                                command=input("Enter command:")
                                if command=='3a':
                                        msgErr=listToStr(apartamentList)
                                        if len(msgErr)==0:
                                                print("The list is empty")
                                        else:
                                                sortedByApartament(apartamentList)
                                                printAppartmentList(apartamentList)
                                elif command=='3b':
                                        a=readApartamentValue()
                                        msgErr=listTo1ApartamentList(apartamentList,a)
                                        if len(msgErr)==0:
                                                print("There is no expense for apartament",a)
                                        else:
                                                print(msgErr)
                                                
                                elif command=='3c':
                                        criteria=readCriteria()
                                        v=readExpenseAmount()
                                        msgErr=selectiveCriteria(apartamentList,criteria,v)
                                        if len(msgErr)==0:
                                                print("There is no apartament with such expenses")
                                        else:
                                                print("The list of such apartaments is:\n \t",msgErr)
                                elif command=='3d':
                                        stop3=True
                                else:
                                        print("Please enter a valid command!")
                                        time.sleep(1)
                elif command=='4':
                        stop4=False
                        while stop4==False:
                                printSubMenu4()
                                command=input("Enter command:")
                                if command=='4a':
                                        t=readExpenseType()
                                        err=sumAllExpensesOfType(apartamentList,t)
                                        if err==0:
                                                print("There is no expense of this type")
                                        else:
                                                print("For ",t," the value of the expense is: ",err)
                                elif command=='4b':
                                        a=readApartamentValue()
                                        err=maxPerExpenses (apartamentList,a)
                                        if len(err)==0:
                                                print("There are no expenses for apartament number ",a)
                                        else:
                                                sortedByApartament(err)
                                                printAppartmentList(err)
                                elif command=='4c':
                                        lis=listOfAllApartamentExpenses(apartamentList)
                                        if len(lis)==0:
                                                print("The list is empty")
                                        else:
                                                lis=sortedByApartamentExpenses(lis)
                                                printAppartmentList(lis)
                                elif command=='4d':
                                        l=listOfAllExpenses(apartamentList)
                                        if len(l)==0:
                                                print("The list is empty")
                                        else:
                                                l=sortedByApartamentExpenses(l)
                                                printAppartmentList(l)
                                elif command=='4e':
                                        stop4=True
                                else:
                                        print("Please enter a valid command!")
                                        time.sleep(1)
                elif command=='5':
                        stop5=False
                        while stop5==False:
                                printSubMenu5()
                                command=input("Enter command:")
                                if command=='5a':
                                        t=readExpenseType()
                                        err=filterByType(apartamentList,t)
                                        if err=='':
                                                print("There is no expense of this type")
                                        else:
                                                sortedByApartament(err)
                                                printAppartmentList(err)
                                                addToUndoList(undoList,apartamentList)
                                elif command=='5b':
                                        v=readExpenseAmount()
                                        err=filterBySmallerThan(apartamentList,v)
                                        if len(err)==0:
                                                print("There is no expense satisfying the condition")
                                        else:
                                                sortedByApartament(err)
                                                printAppartmentList(err)
                                                addToUndoList(undoList,apartamentList)
                                elif command=='5c':
                                        stop5=True
                                else:
                                        print("Please enter a valid command!")
                                        time.sleep(1)                
                elif command=='6':
                        if len(undoList)==1:
                                print("You have the initial list.")
                                time.sleep(1)
                                print("\tNice try!")
                        else:
                                undoList.pop(len(undoList)-1)
                                apartamentList.clear()
                                apartamentList=copy.deepcopy(undoList[len(undoList)-1])
                                printAppartmentList(apartamentList)
                elif command=='0':
                        stop=True
                else:
                        print("Please enter a valid command!")
                        time.sleep(1)
                           
def printAppartmentList(apartamentList):
        '''
        prints the list nicely
        input the list
        output
        '''
        print(listToStr(apartamentList))

def readCriteria():
        '''
        read the criteria for printing
        input
        output the criteria
        '''
        result=None
        while result==None:
                try:
                        result=input("Please enter the criteria:")
                        if not result in ['<','=','>']:
                                raise ValueError
                except ValueError:
                        print("Please enter a valid criteria </=/>")
                        result=None
        return result
                        
def readApartamentValue():
    '''
    Reads the apartament number
    Input:-
    Output: An apartament number
    '''
    result=None
    while result==None:
        try:
            result=int(input("Please enter the apartament number:"))
            if result<=0:
                raise ValueError
        except ValueError:
            print("Please enter a number >0")
            result=None
    return result

def readExpenseType():
        '''
        Reads the type of the expence
        Input
        Output the type
        '''
        res=None
        l=["water","heating","electricity","gas","other"]
        while res==None:
                s=input("Enter the type:")
                if not s in l:
                        print("please enter a valid type:water,heating,electricity,gas,other!")
                else:
                        return s

def readExpenseAmount():
    '''
    Reads the expense amount
    Input:-
    Output: the expense amount
    '''
    result=None
    while result==None:
        try:
            result=int(input("Please enter the amount:"))
        except ValueError:
            print("Please enter a number!")
            result=None
    return result



