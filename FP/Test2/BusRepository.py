'''
Created on Jan 13, 2017

@author: Cristian
'''
from bus import Bus

class BusRepository():
    '''
    class for the repository
    '''


    def __init__(self):
        '''
        Constructor for the repository
        '''
        self.__repo = []
    
    def findId(self, Id):
        '''
        returns the index or -1 otherwise
        '''
        for i in range(len(self.__repo)):
            if self.__repo[i].getId()==Id:
                return i
        return -1
    
    def getElement(self, index):
        '''
        returns the element on the position index in the repo list
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
                string = str(a.getId()) + "," + str(a.getRouteCode()) + "," + a.getModel() + "," + str(a.getTimeUsed()) + "\n"
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
                result.append(Bus(int(line[0]),int(line[1]),line[2],int(line[3])))
                line = f.readline().strip()
            f.close()
        except Exception as e:
            print("Error=" + str(e))
        self.__repo = result