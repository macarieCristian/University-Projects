'''
Created on May 29, 2017

@author: Cristian
'''
class UndirectedGraph:

    def __init__(self, vertices):
        self._edges = {}
        self._dictCost = {}
        
        for vertex in vertices:
            self._edges[vertex] = []
                
    def isEdge(self, v1, v2):
        return v2 in self._edges[v1]
            
            
    def addEdge(self, v1, v2): 
        self._edges[v1].append(v2)
        self._edges[v2].append(v1)
        
    
    def parseEdges(self, v):   
        vList = [] 
        for vertex in self._edges[v]:
            vList.append(vertex)
        
        return vList
                        
    def parseVertices(self):
        vList = [] 
        for v in self._edges.keys():
            vList.append(v)
        
        return vList
    
    def parseEdges(self):
        '''
        return an iterable with all the edges
        '''
        return self._dictCost.keys()
        
    def getCost(self,x,y):
        '''
        returns the cost of an edge
        '''
        return self._dictCost[(x,y)]
    
    def setCost(self,x,y,value):
        '''
        set the new cost fot an edge
        '''
        self._dictCost[(x,y)] = value
        
        
    @staticmethod
    def readFromFile(fileName):
        '''
        reads a graph from a file
        '''
        f = open(fileName,"r")
        a = f.readline().strip().split()
        n = int(a[0])
        graph = UndirectedGraph(n)
        m = int(a[1])
        for i in range(m):
            line = f.readline().strip().split()
            graph.addEdge(int(line[0]), int(line[1]), int(line[2]))
        f.close()
        return graph
        