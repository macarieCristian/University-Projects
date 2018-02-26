'''
Created on Jan 29, 2017

@author: Cristian
'''
from Ui import *

repo = Repository()

repo.readFile("fila")

cont = Controller(repo)

ui = Ui(cont)

ui.mainMenu()