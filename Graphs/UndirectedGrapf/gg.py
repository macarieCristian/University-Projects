'''
Created on May 30, 2017

@author: Cristian
'''
class ListGraph:
    def __init__(self,n):
        self.__vertices = {}        
        self.__costs = {}
        self.nr = n
        
    def addEdge(self,v1,v2,cost):
        if v1 not in self.__vertices.keys():
            self.__vertices[v1] = set()
        self.__vertices[v1].add(v2)
        #if v2 not in self.__vertices.keys():
            #self.__vertices[v2] = set()
        #self.__vertices[v2].add(v1) 
        self.__costs[(v1,v2)] = cost
        #self.__costs[(v2,v1)] = cost
            
    def addVertex(self,x):
        if x not in self.__vertices.keys():
            self.__vertices[x] = set()
            
    def parseNeighbours(self,x):
        return self.__vertices[x]
    
    def parseX(self):
        return list(self.__vertices.keys())
    
    def isEdge(self,v1,v2):
        return v1 in self.__vertices[v2]
    
    def get(self):
        return self.__costs
    
    def __len__(self):
        return len(self.__vertices)
    
    def __str__(self):
        s = ''
        for i in self.__vertices.keys():
            if len(self.__vertices[i]) != 0: 
                    s = s + str(i) + ': ' + str(self.__vertices[i]) + '\n'
            else:
                s = s + str(i) + ': -\n'
        return s
    
    def getCost(self,v1,v2):
        return self.__costs[(v1,v2)]
    
    def removeEdge(self,x):
        for i in range(len(self.__vertices)):
            if i in self.__vertices.keys() and x in self.__vertices[i]:
                self.__vertices[i].remove(x)
        del self.__vertices[x]
        
    def loadGraph(self,fileName):
        f = open(fileName,"r")
        line = f.readline().strip().split()
        while len(line) != 0:
            self.addEdge(int(line[0]),int(line[1]),int(line[2]))
            line = f.readline().strip().split()
    
    @staticmethod  
    def readFromFile(fileName):
        '''
        reads a graph from a file
        '''
        f = open(fileName,"r")
        a = f.readline().strip().split()
        n = int(a[0])
        graph = ListGraph(n)
        m = int(a[1])
        for i in range(m):
            line = f.readline().strip().split()
            graph.addEdge(int(line[0]), int(line[1]), int(line[2]))
        f.close()
        return graph
            
    def sort(self):
        l = []
        for i in self.parseX():
            for j in self.parseNeighbours(i):
                l.append((i,j,self.getCost(i, j)))
                
        ok = True
        while(ok):
            ok = False
            for i in range(len(l)-1):
                (x,y,c) = l[i]
                (x1,y1,c1) = l[i+1]
                if(self.getCost(x, y)>self.getCost(x1, y1)):
                    (a,b,cc) = (x,y,c)
                    l[i] = (x1,y1,c1)
                    l[i+1] = (a,b,cc)
                    ok = True
                
        return l
            
    def find_parent(self, parent,i):
        if parent[i] == -1:
            return i
        if parent[i]!= -1:
            return self.find_parent(parent,parent[i])
 
    # A utility function to do union of two subsets
    def union(self,parent,x,y):
        x_set = self.find_parent(parent, x)
        y_set = self.find_parent(parent, y)
        parent[x_set] = y_set

  
  
    # The main function to check whether a given graph
    # contains cycle or not
    def isCyclic(self):
         
        # Allocate memory for creating V subsets and
        # Initialize all subsets as single element sets
        parent = [-1]*(self.nr)
 
        # Iterate through all edges of graph, find subset of both
        # vertices of every edge, if both subsets are same, then
        # there is cycle in graph.
        for i in self.parseX():
            for j in self.parseNeighbours(i):
                x = self.find_parent(parent, i) 
                y = self.find_parent(parent, j)
                if x == y:
                    return True
                self.union(parent,x,y)
            
    def ham(self):
        '''and len(self.parseNeighbours(x))<2 and len(self.parseNeighbours(y))<2'''
        l = self.sort()
        g = ListGraph(6)
        res = []
        #while g.nr != self.nr-1:
        for e in l:
            (x,y,c) = e
            if g.isCyclic() == None:
                if not x in g.parseX() or not y in g.parseX():
                    g.addEdge(x, y, c)
                elif len(g.parseNeighbours(x))<2 and len(g.parseNeighbours(y))<2:
                    g.addEdge(x, y, c)
        return g
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            