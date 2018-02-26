'''
Created on Mar 24, 2017

@author: God
'''
from copy import deepcopy
class DirectedGraph:
    """
    A directed graph, represented as two maps,
    one from each vertex to the set of outbound neighbours,
    the other from each vertex to the set of inbound neighbours
    """
    def __init__(self,n):
        """
        Creates a graph with n vertices (numbered from 0 to n-1)
        and no edges
        """
        self._dictOut = {}
        self._dictIn = {}
        self._value = {}
        self.n=n

        for i in range(n):
            self._dictOut[i] = []
            self._dictIn[i] = []
    def addVertex(self,x):
        self._dictOut[x] = []
        self._dictIn[x] = []
    def deleteVertex(self,x):
        for v in self.parseNin(x):
            del self._value[(v,x)]
            self._dictOut[v].remove(x)

        for v in self.parseNout(x):
            del self._value[(x,v)]
            self._dictIn[v].remove(x)

        del self._dictIn[x]
        del self._dictOut[x]
    def addEdge(self,x,y,z):
        """
        Adds an edge from x to y.
        Precondition: there is no edge from x to y
        """
        self._dictOut[x].append(y)
        self._dictIn[y].append(x)
        self._value[(x,y)]=z
    def deleteEdge(self,x,y):
        del self._value[(x,y)]
        delElem(self._dictOut[x],y)
        delElem(self._dictIn[y],x)
    def getCost(self,x,y):
        return self._value[(x,y)]
    def parseX(self):
        #Returns an iterable containing all the vertices
        return self._dictOut.keys()
    def parseNout(self,x):
        #Returns an iterable containing the outbound neighbours of x
        return self._dictOut[x]
    def parseNin(self,x):
        #Returns an iterable containing the inbound neighbours of x
        return self._dictIn[x]
    def isEdge(self,x,y):
        #Returns True if there is an edge from x to y, False otherwise
        return y in self._dictOut[x]
def accessible(g, s):
    """
    Returns the set of vertices of the graph g that are accessible
    from the vertex s
    """
    acc = set()
    acc.add(s)
    list = [s]
    while len(list) > 0:
        x = list[0]
        list = list[1 : ]
        for y in g.parseNout(x):
            if y not in acc:
                acc.add(y)
                list.append(y)
    return acc
def delElem(l,x):
    for i in range(0,len(l)):
        if l[i] == x :
            l.pop(i)
            return