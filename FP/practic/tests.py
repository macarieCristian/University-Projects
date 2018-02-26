'''
Created on Jan 23, 2017

@author: mmie2169
'''
import unittest
from controller.Controller import Controller
from repository.Repository import Repository
from domain.Sentence import Sentence
class TestSwap(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
        
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        
    def testSwap(self):        
        repo = Repository()
        
        controller = Controller(repo)
        
        controller._guess = controller.getAll()[0]
        
        assert controller._guess[1] == 'c'
        assert controller._guess[2] == 'r'
        
        controller.swap(0, 1, 0, 2)
        
        assert controller._guess[1] == 'r'
        assert controller._guess[2] == 'c'
        
class testSentence(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
        
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        
    def testSentence(self):
        s = Sentence('Lalala')
        assert s.getScore() == 6
        
        s = Sentence('This is a sentence')
        assert s.getScore() == 15
        
        assert s.sentence == [['T','h','i','s'],['i','s'],['a'],['s','e','n','t','e','n','c','e']]