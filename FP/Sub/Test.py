'''
Created on Jan 9, 2017

@author: Cristian
'''
import unittest
from Ui import *

class TestAll(unittest.TestCase):


    def setUp(self):
        self.person = "k"
        '''
        self.book = Book(1,'Amintiri din copilarie', 'naspa', 'Ionut Cercel')
        self.client = Client(1, 'Andrei Mafeotul')
        self.rental = Rental(1,2,3, Date(10,11,2016), Date(20,11,2016), Date(25,11,2016))
        self.undoList = UndoController()
        self.bookList = BookRepository()
        self.clientList = ClientRepository()
        self.rentalList = RentalRepository()
        self.bookController = BookController(self.bookList, self.undoList)
        '''