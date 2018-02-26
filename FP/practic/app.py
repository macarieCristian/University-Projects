'''
Created on Jan 23, 2017

@author: Madalina
'''
from repository.Repository import Repository
from controller.Controller import Controller
from ui.UI import UI

repo = Repository()
controller = Controller(repo)
ui = UI(controller)

ui.mainMenu()