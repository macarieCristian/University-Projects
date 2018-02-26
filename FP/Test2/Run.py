'''
Created on Jan 13, 2017

@author: Cristian
'''

from Ui import *

repo1 = BusRepository()
repo2 = RouteRepository()

repo1.readFromFile("Bus")
repo2.readFromFile("Route")

controller = Controller(repo1,repo2)

ui = Ui(controller)

ui.menu()

repo1.writeToFile("Bus")
repo2.writeToFile("Route")