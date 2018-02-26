'''
Created on Jan 30, 2017

@author: Cristian
'''
from Ui import *

repo = Repository()

repo.readFile("fila")

controller = Controller(repo)

ui = Ui(controller)

ui.mainMenu()