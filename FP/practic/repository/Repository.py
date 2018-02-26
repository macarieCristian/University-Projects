'''
Created on Jan 23, 2017

@author: Madalina
'''
from domain.Sentence import Sentence
class Repository:
    def __init__(self):
        self._objects = []
        self._loadFromFile()
        
    def _loadFromFile(self):
        '''
        Loads the sentences from the file.
        '''
        
        file = open('input.txt', 'r')
        text = file.readline()
        while text != '':
            s = Sentence(text.strip())
            self._objects.append(s)
            text = file.readline()
        file.close()
    
    def getSentence(self):
        return self._sentence
    
    def getAll(self):
        return self._objects
        
    def __str__(self):
        result = ''
        for obj in self._objects:
            result = result + str(obj) + '\n'
        
        return result
    
    def __len__(self):
        return len(self._objects)