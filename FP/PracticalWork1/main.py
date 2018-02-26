'''
Created on Mar 24, 2017

@author: God
'''
# ia aprox 16 secunde sa citeasca fisieru de 1m

from Repository.Repository import Repository
from Controller.Controller import Controller
from Ui.Ui import Ui

repo = Repository("graph10k.txt")
ctrl = Controller(repo)
ui = Ui(ctrl)
ui.start()