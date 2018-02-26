
def sumAllExpensesOfType(apartamentList,t):
    '''
    return the sum of all expenses from all apartaments for the given type
    input the list, the type
    output the described sum
    '''
    s=0
    for i in range(len(apartamentList)):
        if apartamentList[i][1]==t:
            s += apartamentList[i][2]
    return s

def sumAllExpensesForApartament(apartamentList,a):
    '''
    return the sum of all expenses for the apartament a
    input the list of expenses, the apart num
    output the sum
    '''
    s=0
    for i in range(len(apartamentList)):
        if apartamentList[i][0]==a:
            s +=apartamentList[i][2]
    return s
        
#########################################    
#               Tests                   #   
#########################################

def testSumAllExpensesOfType():
    l=[[1,"water",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]]
    assert sumAllExpensesOfType(l,"gas")==79
    assert sumAllExpensesOfType(l,"water")==25
testSumAllExpensesOfType()

def testSumAllExpensesForApartament():
    l=[[1,"water",25],[1,"gas",25],[1,"heating",25],[2,"heating",32],[4,"electricity",44],[3,"gas",55],[4,"gas",24],[6,"other",30]]
    assert sumAllExpensesForApartament(l,1)==75
    assert sumAllExpensesForApartament(l,3)==55
testSumAllExpensesForApartament()
