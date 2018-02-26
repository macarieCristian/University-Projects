'''
Created on Mar 5, 2017

@author: Cristian
'''
from Ui import *
'''
graph = FinalGraph(10)
graph.addEdge(0,1,4)
graph.addEdge(0,2,4)
graph.addEdge(0,3,4)
graph.addEdge(0,0,4)
graph.addEdge(1,0,4)
graph.addEdge(2,0,4)
'''

graph = FinalGraph.readFromFile("GraphSave")

graph.ham()

ui = Ui(graph)

ui.mainMenu()