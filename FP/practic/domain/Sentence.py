'''
Created on Jan 23, 2017

@author: Madalina
'''
class Sentence:
    def __init__(self, sentence):
        self.sentence = sentence
        self.score = self.computeScore()
        self.sentence = self.sentence.split(' ')
        self.sentence = self.toList()
        
    def computeScore(self):
        '''
        Computes the score of a sentence, so counts the letters of that sentence.
        input - 
        output - score
        '''
        
        score = 0
        for letter in self.sentence:
            if letter != ' ':
                score = score + 1
                
        return score
    
    def getScore(self):
        return self.score
        
    def toList(self):
        '''
        Converts a sentence from string to list.
        input - 
        output - the list
        '''
        
        result = []
        
        if len(self.sentence) > 1:
            for i in range(len(self.sentence)):
                result.append([])
                for letter in self.sentence[i]:
                    result[i].append(letter)
        else:
            for letter in self.sentence[0]:
                    result.append(letter)
            
        return result
    
    def __eq__(self, obj):
        '''
        Override of the equal function. Checks if 2 objects of this class are equal.
        '''
        
        if len(self.sentence) != len(obj.sentence):
            return False
        for i in range(len(self.sentence)):
            for j in range(len(self.sentence[i])):
                if self.sentence[i][j] != obj.sentence[i][j]:
                    return False
        return True
    
    def __getitem__(self, i):
        return self.sentence[i]
    
    def __setitem__(self, i, val):
        self.sentence[i] = val
        
    def __len__(self):
        return len(self.sentence)
    
    def __str__(self):
        result = ''
        if len(self.sentence[0]) > 1:
            for word in self.sentence:
                for letter in word:
                    result = result + letter
                result = result + ' '
        else:
            for letter in self.sentence:
                result = result + letter
        return result