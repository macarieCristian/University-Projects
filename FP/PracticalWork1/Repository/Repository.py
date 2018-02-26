'''
Created on Mar 24, 2017

@author: God
'''

from Domain.DirectedGraph import *

class Repository:
    
    def __init__(self, fileName):
        self._graph = 0
        self.readGraph(fileName)
        
    def readGraph(self,fileName):
        file = open(fileName)
        firstLine = file.readline()
        l = firstLine.split()
        n = int(l[0])
        m = int(l[1])
        self._graph = DirectedGraph(n)
        newLine = file.readline()
        for i in range(0,m-1):
            l = newLine.split()
            self._graph.addEdge(int(l[0]), int(l[1]), int(l[2]))
            newLine = file.readline()
            
    def getGraph(self):
        return self._graph
    
    def addVertex(self,v):
        self._graph.addVertex(v)
        
    def deleteVertex(self,v):
        self._graph.deleteVertex(v)
        
    def addEdge(self,v1,v2,c):
        self._graph.addEdge(v1,v2,c)
        
    def deleteEdge(self,v1,v2):
        self._graph.deleteEdge(v1,v2)
            
        
        