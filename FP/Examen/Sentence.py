'''
Created on Jan 30, 2017

@author: Cristian
'''

class Sentence():
    '''
    classdocs
    '''


    def __init__(self, string):
        '''
        Constructor
        '''
        self.__sentence = str(string)
        self.__printString = str(self.getGuessSentence())
        
    def getCorrect(self):
        return str(self.__sentence)
    
    def getPrintSentence(self):
        return str(self.__printString)
    
    def setLetterPrint(self,index,value):
        self.__printString[index] = value
        
    def getLetterCorrect(self,index):
        return self.__sentence[index]
        
    def getStringList(self):
        a = self.__sentence.split(" ")
        result = []
        for i in a:
            result.append(list(i))
        return result
    
    def getGuessSentence(self):
        a = self.getStringList()
        result =""
        for i in a:
            x = i[0]
            y = i[-1]
            res = []
            for j in i:
                if (j!=x)and(j!=y):
                    res.append("-")
                else:
                    res.append(j)
            string =""
            for k in res:
                string +=str(k)
            result +=str(string)+" "
        return result
    
    def __str__(self):
        return str(self.__sentence)
        
def test():
    a = Sentence("ana are")
    print(a.getCorrect())
    print(a.getGuessSentence())
#test()