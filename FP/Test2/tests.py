'''
Created on Jan 13, 2017

@author: Cristian
'''
import unittest
from Ui import *
from bus import *
from Route import *

class TestAll(unittest.TestCase):


    def setUp(self):
        self.bus = Bus(1,1,"mercedes",3)
        self.route = Route(1,10)
        self.busRepo = BusRepository()
        self.ruteRepo = RouteRepository()
        self.controller = Controller(self.busRepo,self.ruteRepo)
        
    def testComputeKm(self):
        self.assertEqual(self.controller.computeKm(self.bus.getId(), self.route.getRouteCode()),30)