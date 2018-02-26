'''
Created on Jan 28, 2017

@author: Cristian
'''
from Ui import *

repo = Repository()

controller = Controller(repo)

ui = Ui(controller)

ui.mainMenu()

