'''
Created on Jan 9, 2017

@author: Cristian
'''
from Ui import *

repo = Repository()

repo.readFromFile("Persons")

controller = Controller(repo)

ui = Ui(controller)

ui.menu()

repo.writeToFile("Persons")