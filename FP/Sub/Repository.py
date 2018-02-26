'''
Created on Jan 9, 2017

@author: Cristian
'''
from Person import Person

class Repository():
    '''
    class for the person repository
    '''


    def __init__(self):
        '''
        Constructor for the repository
        '''
        self.__repo = []
        
    def addPerson(self, Id):
        '''
        adds a new person to the repository list
        input the id
        '''
        person = Person(Id,"nonvaccinated", "healty")
        self.__repo.append(person)
        
    def findSuitablePerson(self):
        '''
        returns the index of a suitable person
        '''
        for i in range(len(self.__repo)):
            if (self.__repo[i].getImunStatus()=="nonvaccinated")and(self.__repo[i].getStatus()=="healty")and(self.__repo[i].getDays()!=3):
                return i
        return -1
    
    def findIllPerson(self):
        '''
        returns 1 if exists
        '''
        for i in range(len(self.__repo)):
            if self.__repo[i].getStatus()=="ill":
                return 1
        return -1
        
    def findPerson(self, Id):
        '''
        returns the position of the person with the given id
        input id
        '''
        for i in range(len(self.__repo)):
            if self.__repo[i].getId()==Id:
                return i
        return -1
    
    def getPerson(self, index):
        '''
        returns the person on the position index in the repo list
        input index
        '''
        return self.__repo[index]
    
    def getAll(self):
        '''
        returns the list
        '''
        return self.__repo
    
    def __str__(self):
        '''
        returns the list with a nice looking view
        '''
        s = ""
        for i in range(len(self.__repo)):
            s += str(self.__repo[i]) + "\n"
        return s
    
    def __len__(self):
        '''
        overwriting the len function
        '''
        return len(self.__repo)
    
    def writeToFile(self, fileName):
        '''
        write the list in a text file
        input filename
        '''
        f = open(fileName, "w")
        try:
            for a in self.__repo:
                string = str(a.getId()) + "," + a.getImunStatus() + "," + a.getStatus() + "\n"
                f.write(string)
            f.close()
        except Exception as e:
            print("An error ocured-" + str(e))
            
    def readFromFile(self, fileName):
        '''
        reads the list from the text file
        '''
        result = []
        try:
            f = open(fileName, "r")
            line = f.readline().strip()
            while len(line)>0:
                line = line.split(",")
                result.append(Person(int(line[0]),line[1],line[2]))
                line = f.readline().strip()
            f.close()
        except Exception as e:
            print("An error ocured-" + str(e))
        self.__repo = result
        
                
    
    
    
    
    
    