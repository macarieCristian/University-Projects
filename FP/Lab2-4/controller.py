from domain import *
import copy

def addToUndoList(undoList,apartamentList):
    '''
    add the current appartament list to the undo list
    input the apartament list and the undo list
    output the modified undo list
    '''
    undoList.append(copy.deepcopy(apartamentList))

def removeFromUndoList(undoList,apartamentList):
    '''
    remove the last element from the undo list and update the apartamentList
    input the undo list, the apartament list
    output the modified undo list and apartamentList
    '''
    undoList.pop(len(undoList)-1)
    apartamentList.clear()
    apartamentList=copy.deepcopy(undoList[len(undoList)-1])

def addExpense(apartamentList,a,t,v):
    '''
    Add an specific expense to an apartament
    Input:apartamentList
    -v:the triplet to be added
    -t:the type
    -v:the amount
    Output: the modified list
    Exceptions:-
    '''
    x=[a,t,v]
    apartamentList.append(x)

def findApartamentExpense(apartamentList,a,t):
    '''
    return the position of the expense in the primary list
    Input a=ap num, t=expense type, apartamentList=the list
    Output position
    '''
    for i in range(0,len(apartamentList)):
        if (apartamentList[i][0]==a) and (apartamentList[i][1]==t):
            return i
    return -1

def findType(apartamentList,t):
    '''
    returns the position of the first element with the type t
    input the apartamentList, the type t
    output position
    '''
    for i in range(0,len(apartamentList)):
        if apartamentList[i][1]==t:
            return i
    return -1

def findApartament(List,a):
    '''
    return the position of the first expense of apartament a in the list
    input the list, apart num
    output the position
    '''
    for i in range(len(List)):
        if List[i]==a:
            return i
    return -1

def findApartamentTriplet(List,a):
    '''
    return the position of the first expense of apartament a in the list of triplets
    input the list, apart num
    output the position
    '''
    for i in range(len(List)):
        if List[i][0]==a:
            return i
    return -1       

def removeApartament(apartamentList,pos):
    '''
    remove the expense from the primary list
    input the list, the position
    output the modifyed list
    '''
    apartamentList.pop(pos)

def removeTriplet(apartamentList,a):
        '''
        removes a triplet from the primary list
        Input the initial list
        output the modifyed list
        '''
  
        pos=findApartamentTriplet(apartamentList,a)
        if pos==-1:
            return "Can't find that appartment"
        while findApartamentTriplet(apartamentList,a)!=-1:
            removeApartament(apartamentList,pos)
        return ''

def removeSqApartaments(apartamentList,a1,a2):
    '''
    remove the apartaments between a1 and a2
    input the list, apart 1=a1 and apart 2=a2
    output the modifyed list
    '''
    k=0
    i=0
    while i<len(apartamentList):
        if (apartamentList[i][0]>=a1) and (apartamentList[i][0]<=a2) or (apartamentList[i][0]<=a1) and (apartamentList[i][0]>=a2):
            removeApartament(apartamentList,i)
            k=1
        else:
            i=i+1
    if k==0:
        return "there is no apartament between",a1," and ",a2
    else:
        return''

def removeAllExpensesWithType (apartamentList,t):
    '''
    removes from list all the expenses with type t
    input the list, the type
    output the modifyed list
    '''
    k=0
    i=0
    while i<len(apartamentList):
        if apartamentList[i][1]==t:
            removeApartament(apartamentList,i)
            k=1
        else:
            i=i+1
    if k==0:
        return "there is no expence with the type",t
    else:
        return''

def replaceExpenseValue(apartamentList,a,t,v):
    '''
    replaces the expenses of the ap a of the type t with the given value v
    input list,a,t,v=ap num, ex type, new value
    output the modifyed list
    '''
    pos=findApartamentExpense(apartamentList,a,t)
    if pos!=-1:
        while pos!=-1:
            removeApartament(apartamentList,pos)
            pos=findApartamentExpense(apartamentList,a,t)
        addExpense(apartamentList,a,t,v)
        return''
    else:
        return "there is no ",t," expence for apartament ",a

def sortedByApartament(apartamentList):
    '''
    sort the list ascending by the apartament number
    input the list
    output the sorted list
    '''
    for i in range(len(apartamentList)-1):
        for j in range(i+1,len(apartamentList)):
            if apartamentList[i][0]>apartamentList[j][0]:
                apartamentList[i],apartamentList[j]=apartamentList[j],apartamentList[i]
    return apartamentList

def sortedByApartamentExpenses(apartamentList):
    '''
    sort the list ascending by the apartament expenses
    input the list
    output the sorted list
    '''
    for i in range(len(apartamentList)-1):
        for j in range(i+1,len(apartamentList)):
            if apartamentList[i][2]>apartamentList[j][2]:
                apartamentList[i],apartamentList[j]=apartamentList[j],apartamentList[i]
    return apartamentList
                
def listToStr(apartamentList):
    '''
    convert the list to a nice looking string
    input the list
    output the string representation
    '''
    if len(apartamentList)==0:
        return ""
    l=[]
    string=""
    for i in range(len(apartamentList)):
        if findApartament(l,apartamentList[i][0])==-1:
            l.append(apartamentList[i][0])
            string += listTo1ApartamentList(apartamentList,apartamentList[i][0])
    return string
    
def listTo1ApartamentList(apartamentList,a):
    '''
    select the list of expenses for the apartament a
    input the list , the apartament number
    output the string representation of the sublist
    '''
    i=0
    string=''
    for i in range(len(apartamentList)):
        if apartamentList[i][0]==a:
            string +='█'
            string +=" Ap num= "
            string +=str(apartamentList[i][0])
            string +=" Type= "
            string +=str(apartamentList[i][1])
            string +=" Cost= "
            string +=str(apartamentList[i][2])
            string +=" "
    string +='█'
    string="\n"+string
    for p in range(len(string)-1):
        string="▄"+string
    string +="\n"
    for p in range(len(string)//2-1):
        string +="▀"
    string +="\n"
    return string

def selectiveCriteria(apartamentList,criteria,v):
    '''
    select the apartaments which fufill the criteria
    input the list, the criteria, the value
    output the list of apartaments num
    '''
    lis=[]
    k=0
    for i in range(len(apartamentList)):
        if findApartament(lis,apartamentList[i][0])==-1:
            s=sumAllExpensesForApartament(apartamentList,apartamentList[i][0])
            if criteria=='>':
                if s>int(v):
                    lis.append(apartamentList[i][0])
                    k=1
            elif criteria=='=':
                if s==int(v):
                    lis.append(apartamentList[i][0])
                    k=1
            elif criteria=='<':
                if s<int(v):
                    lis.append(apartamentList[i][0])
                    k=1
    if k==0:
        return''
    else:
        return lis

def maxPerExpenses (apartamentList,a):
    '''
    return a list of max expenses for the apartament a
    input apartamentList=the list, a the apartament number
    output the specificed list
    '''
    l=[]
    for i in range(len(apartamentList)):
        if apartamentList[i][0]==a:
            if findApartamentExpense(l,a,apartamentList[i][1])==-1:
                l.append(apartamentList[i])
            elif apartamentList[i][2]>l[findApartamentExpense(l,a,apartamentList[i][1])][2]:
                l[findApartamentExpense(l,a,apartamentList[i][1])][2]=apartamentList[i][2]
    return l

def listOfAllApartamentExpenses(apartamentList):
    '''
    returns a list with the existing apartaments as [num, apartament, all expenses]
    input the list with te apartaments expenses
    output the predefined list
    '''
    lis=[]
    for i in range(len(apartamentList)):
        if findApartamentExpense(lis,apartamentList[i][0],"total")==-1:
            el=[apartamentList[i][0],"total",sumAllExpensesForApartament(apartamentList,apartamentList[i][0])]
            lis.append(el)
    return lis

def listOfAllExpenses(apartamentList):
    '''
    returns a list with the existing types as [All,type ,the toatal expense]
    input the list of the apartament expenses
    output the list defined before
    '''
    l=[]
    for i in range(len(apartamentList)):
        if findType(l,apartamentList[i][1])==-1:
            el=["All",apartamentList[i][1],sumAllExpensesOfType(apartamentList,apartamentList[i][1])]
            l.append(el)
    return l
        
def filterByType(apartamentList,t):
    '''
    remove from the list all the expenses that doesn't have the type t
    input the list , the type
    output the modified list
    '''
    i=0
    if findType(apartamentList,t)==-1:
        return ''
    while i<len(apartamentList):
        if apartamentList[i][1]!=t:
            removeApartament(apartamentList,i)
        else:
            i=i+1
    return apartamentList

def filterBySmallerThan(apartamentList,v):
    '''
    remove from the list all the expenses that are >= with the given value
    input the list , the value
    output the modified list
    '''
    i=0
    while i<len(apartamentList):
        if apartamentList[i][2]>=v:
            removeApartament(apartamentList,i)
        else:
            i=i+1
    return apartamentList
    
#########################################    
#               Tests                   #   
#########################################

def testAddToUndoList():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]]
    p=[]
    addToUndoList(p,l)
    assert len(p)>0
testAddToUndoList()

def testRemoveFromUndoList():
    l=[[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]],
       [[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]]]
    li=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]]
    removeFromUndoList(l,li)
    assert len(l)==1
testRemoveFromUndoList()

def testAddExpense():
    l=[]
    addExpense(l,1,"gas",20)==[[1,"gas",20]]
    assert len(l)==1
testAddExpense()

def testfindApartamentExpense():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    assert findApartamentExpense(l,3,"gas")==3
testfindApartamentExpense()

def testFindType():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    assert findType(l,"gas")==3
    assert findType(l,"water")==0
testFindType()

def testFindApartament():
    l=[1,2,3,4,6]
    assert findApartament(l,1)==0
    assert findApartament(l,5)==-1
testFindApartament()

def testFindApartamentTriplet():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    assert findApartamentTriplet(l,1)==0
testFindApartamentTriplet()

def testRemoveApartament():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    removeApartament(l,0)
    assert l[0]==[2,"heating",32]
testRemoveApartament()

def testRemoveTriplet():
        l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
        a=len(l)
        assert len(removeTriplet(l,1))==0
        assert len(l)==a-1
testRemoveTriplet()

def testRemoveSqApartaments():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    assert removeSqApartaments(l,1,4)==''
testRemoveSqApartaments()

def testRemoveAllExpensesWithType():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]]
    assert removeAllExpensesWithType (l,"gas")==''
testRemoveAllExpensesWithType()

def testReplaceExpenseValue():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]]
    replaceExpenseValue(l,1,"water",50)
    assert l==[[2, 'heating', 32], [4, 'electricity', 44], [3, 'gas', 55], [4, 'gas', 24], [6, 'other', 30], [1, 'water', 50]]
testReplaceExpenseValue()

def testSortedByApartament():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    sortedByApartament(l)
    assert l==[[1,"water",25],[2,"heating",32],[3,"gas",55],[4,"electricity",44],[6,"other",30]]
testSortedByApartament()

def testSortedByApartamentExpenses():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    sortedByApartamentExpenses(l)
    assert l==[[1,"water",25],[6,"other",30],[2,"heating",32],[4,"electricity",44],[3,"gas",55]]
testSortedByApartamentExpenses()

def testSelectiveCriteria():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[6,"other",30]]
    selectiveCriteria(l,"=",25)
    assert selectiveCriteria(l,"=",25)==[1]
testSelectiveCriteria()

def testMaxPerExpenses():
    l=[[1,"water",25],[1,"water",32]]
    assert maxPerExpenses (l,1)==[[1,"water",32]]
testMaxPerExpenses()

def testListOfAllApartamentExpenses():
    l=[[1,"water",25],[1,"water",32]]
    assert listOfAllApartamentExpenses(l)==[[1,"total",57]]
testListOfAllApartamentExpenses()

def testListOfAllExpenses():
    l=[[1,"water",25],[2,"water",32]]
    assert listOfAllExpenses(l)==[["All","water",57]]
testListOfAllExpenses()

def testFilterByType():
    l=[[1,"water",25],[2,"gas",32]]
    assert filterByType(l,"gas")==[[2,"gas",32]]
testFilterByType()

def testFilterBySmallerThan():
    l=[[1,"water",25],[2,"gas",32]]
    assert filterBySmallerThan(l,25)==[]
testFilterBySmallerThan()
