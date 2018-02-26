'''
Created on May 30, 2017

@author: Cristian
'''
from gg import*


graph = ListGraph(6)
graph.loadGraph("a")

print(str(graph))

print(len(graph.parseNeighbours(1)))

print(graph.sort())

print(graph.isCyclic())

print(graph.ham())