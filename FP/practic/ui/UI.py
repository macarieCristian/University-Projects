'''
Created on Jan 23, 2017

@author: Madalina
'''
import copy
class UI:
    def __init__(self, controller):
        self._controller = controller
        self.guess = self._controller.getGuess()
        self.correct = self._controller.getCorrect()
        self.score = self.correct.getScore()
        self.undo = 0
        self.index = -1
      
    def mainMenu(self):
        print('Hello!')
        while self.score > 0 and self.isCorrect() == False:
            self.printResult()
            text = input('Give command: ')
            text = text.split()
            if len(text) == 0:
                print('Invalid input.')
            elif text[0].strip() == 'swap' and len(text) == 6:
                ok = self.validate(text)
                if ok == True:
                    self.undo = copy.deepcopy(self.guess.sentence)
                    self.index = 0
                    self.score = self.score - 1
                    self._controller.swap(text[1], text[2], text[4], text[5])
                else:
                    print('Invalid input.')
            elif text[0] == 'undo' and len(text) == 1:
                if self.index == -1:
                    print('There are no operations to undo.')
                else:
                    self.guess.sentence = copy.deepcopy(self.undo)
                    self.index = -1
                    print('There last operation has been undone.')
            else:
                print('Invalid input.')
                
        if self.isCorrect() == True:
            self.printResult()
            print('You won! Your score is ' + str(self.score))
        else:
            print('Game over!')
        
    def printResult(self):
        result = str(self.guess) + ' [score is: ' + str(self.score) + '] \n'
        
        print(result)
        
    def validate(self, text):
        '''
        Checks if the numbers entered for the swap are valid (not outside the sentence or first or last letter of word
        input - text, a list of the form ['swap', number of 1st word, number of 1st letter, '-', number of 1st word,
        number of 1st letter]
        output - True if ok, False otherwise
        '''
        
        try:
            
            text[1] = int(text[1].strip())
            text[2] = int(text[2].strip())
            text[4] = int(text[4].strip())
            text[5] = int(text[5].strip())
        except:
            return False
        
        if len(self.guess[0]) == 1:
            if text[1] != 0 or text[4] != 0:
                return False
            if text[2] < 1 or text[2] > len(self.guess) - 2:
                print('3')
                return False
            if text[5] < 1 or text[5] > len(self.guess) - 2:
                print('4')
                return False
            
            return True
                
        if text[1] < 0 or text[1] > len(self.guess) - 1:
            return False
        if text[4] < 0 or text[4] > len(self.guess) - 1:
            return False
        if text[2] < 1 or text[2] > len(self.guess[text[1]]) - 2:
            return False
        if text[5] < 1 or text[5] > len(self.guess[text[4]]) - 2:
            return False
        
        return True
        
    def isCorrect(self):
        if self.guess == self.correct:
            return True
        
        return False