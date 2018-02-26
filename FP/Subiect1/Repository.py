'''
Created on Jan 28, 2017

@author: Cristian
'''
from Question import Question

class Repository():
    '''
    class for repository
    '''


    def __init__(self):
        '''
        Constructor
        '''
        self.__list = []
        
    def getAll(self):
        return self.__list
    
    def getElement(self,index):
        return self.__list[index]
    
    def writeToFile(self,fileName):
        
        try:
            f = open(fileName,"w")
            for a in self.__list:
                string = str(a.getId())+","+a.getText()+","+a.getA1()+","+a.getA2()+","+a.getA3()+","+a.getCorrect()+","+a.getDifficulty()+"\n"
                f.write(string)
            f.close()
        except Exception as e:
            print("Error "+str(e))
            
    def readFile(self,fileName):
        result = []
        try:
            f = open(fileName,"r")
            line = f.readline().strip()
            while len(line)>0:
                line = line.split(",")
                result.append(Question(int(line[0]),line[1],line[2],line[3],line[4],line[5],line[6]))
                line = f.readline().strip()
            f.close()
        except Exception as e:
            print("Error "+str(e))
        self.__list = result
        
    def addQuestion(self,object):
        '''
        this method adds a question to the list
        input the data for a question
        '''
        self.__list.append(object)
        
    def __len__(self):
        return len(self.__list)
    
    def __str__(self):
        string = ""
        for a in self.__list:
            string +=str(a)+"\n"
        return string
    
    def removeAll(self):
        self.__list.clear()
        
def testAdd():
    a = Repository()
    obj = Question(1, "Da?", "Nu", "a2"," a3", "Nu", "easy")
    a.addQuestion(obj)
    assert len(a)==1
testAdd()