'''
Created on Feb 28, 2017

@author: Cristian
'''

class EdgeProp():
    '''
    a class designed to store the cost for the edges
    '''
    def __init__(self):
        self._dictCost = {}
        
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
        
        

class DoubleDictionary():
    '''
    A directed graph represented as 2 dictionaries 
        one for the inbound neighbours and the other one
        for the outbound neighbours
    '''


    def __init__(self, n):
        '''
        Creates a graph with n vertices (numbered from 0 to n-1)
        and no edges
        '''
        self._dictOut = {}
        self._dictIn = {}
        self._verticeNum = n
        for i in range(self._verticeNum):
            self._dictOut[i] = []
            self._dictIn[i] = []
            
    def parseX(self):  
        '''
        returns an iterable with all the vertices
        '''
        return self._dictOut.keys()
    
    def parseNin(self,x):
        '''
        returns an iterable with all the in neighbours of the x vertice
        '''
        return self._dictIn[x]
    
    def parseNout(self,x):
        '''
        returns an iterable with all the out neighbours of the x vertice
        '''
        return self._dictOut[x]
        
    def isEdge(self,x,y):
        '''
        verify if the (x,y) is an edge
        '''
        if (x in self.parseX()) and (y in self.parseX()):
            return y in self._dictOut[x]
        else:
            raise Exception("The one or both of the vertices does not exist")
    
    def verticesNum(self):
        '''
        returns the number of vertices in the graph
        '''
        return self._verticeNum
    
    
    
class FinalGraph(DoubleDictionary,EdgeProp):
    
    def __init__(self,n):
        '''
        creates a graph representation where the edges have costs associated to them
        '''
        DoubleDictionary.__init__(self, n)
        EdgeProp.__init__(self)
        
    def getDictOut(self):
        '''
        returns the out dict
        '''
        return self._dictOut
    
    def getDictIn(self):
        '''
        returns the in dict
        '''
        return self._dictIn
    
    def getDictCost(self):
        '''
        returns the cost dict
        '''
        return self._dictCost
        
    def addVertex(self,x):
        '''
        ads a vertex to the graph
        '''
        if x in self.parseX():
            raise Exception("This vertex already exists")
        self._dictOut[x] = []
        self._dictIn[x] = []
        self._verticeNum +=1
    
    '''    
    def removeVertex(self,x):
        ''''''
        remove a vertex from the graph 
        also the funct will remove all the edges associated with the x vertex
        ''''''
        if x in self.parseX():
            for v in self.parseNin(x):
                self.removeEdge(v, x)
                self._dictOut(v).pop(self._dictOut(v).index(x))
            self._dictIn.pop(x)
            for v in self.parseNout(x):
                self.removeEdge(x, v)
                self._dictIn(v).pop(self._dictIn(v).index(x))
            self._dictOut.pop(x)
            self._verticeNum -=1
        else:
            raise Exception("The vertex %d does not exists"%x)
    '''    
        
    def removeVertex(self,x):
        '''
        remove a vertex from the graph 
        also the funct will remove all the edges associated with the x vertex
        '''
        if x in self.parseX():
            self._dictOut.pop(x)
            self._dictIn.pop(x)
            self._verticeNum -=1
            for v in self.parseX():
                if x in self.parseNin(v):
                    self._dictIn[v].pop(self._dictIn[v].index(x))
                if x in self.parseNout(v):
                    self._dictOut[v].pop(self._dictOut[v].index(x))
            ok = False
            while ok==False:
                ok = True
                for (a,b) in self._dictCost:
                    if (a==x) or (b==x):
                        self._dictCost.pop((a,b))
                        ok=False
                        break
        else:
            raise Exception("The vertex %d does not exists"%x)
    
    def addEdge(self,x,y,cost):
        '''
        add edge from x to y ,there should not be already an edge
        '''
        if (x,y) in self.parseEdges():
            raise Exception("There is already an edge between (%d,%d)"%(x,y))
        self._dictOut[x].append(y)
        self._dictIn[y].append(x)
        self._dictCost[(x,y)] = cost
        
    def removeEdge(self,x,y):
        '''
        removes the edge (x,y)
        '''    
        if (x,y) in self.parseEdges():
            self._dictCost.pop((x,y))
            self._dictOut[x].pop(self._dictOut[x].index(y))
            self._dictIn[y].pop(self._dictIn[y].index(x))
        else:
            raise Exception("The edge (%d,%d) does not exists"%(x,y))

    @staticmethod
    def readFromFile(fileName):
        '''
        reads a graph from a file
        '''
        f = open(fileName,"r")
        a = f.readline().strip().split()
        n = int(a[0])
        graph = FinalGraph(n)
        m = int(a[1])
        for i in range(m):
            line = f.readline().strip().split()
            graph.addEdge(int(line[0]), int(line[1]), int(line[2]))
        f.close()
        return graph
    
    @staticmethod
    def writeToFile(fileName,graph):
        '''
        saves a graph to a file
        '''
        m = len(graph.getDictCost())
        f = open(fileName,"w")
        string = str(graph.verticesNum())+" "+str(m)+"\n"
        f.write(string)
        for (a,b) in graph.getDictCost():
            string = str(a)+" "+str(b)+" "+str(graph.getDictCost()[(a,b)])+"\n"
            f.write(string)
        f.close()
        
    
   
    def BFS(self,start,end):

        if start == end:
            return (None, 0)
        
        q = []
        prev = {}
        dist = {}
        visited = set()
        
        q.append(start)
        visited.add(start)
        dist[start] = 0
        
        while len(q) > 0:
            x = q.pop(0)
            if x == end:
                break
            for y in self.parseNout(x):
                if not y in visited:
                    q.append(y)
                    visited.add(y)
                    dist[y] = dist[x] + 1
                    prev[y] = x
        
        if not(end in visited):
            return ("No path between given start and end", "")
        
        path_min = []
        node = prev[end]
        path_min.append(end)
        while node != start:
            path_min.append(node)
            node = prev[node]
        path_min.append(start)
        path_min.reverse()
        return (path_min, dist[end])
    
    
    def BFSR(self,start,end):
        '''
        returns the lowest length path from start to end using the BFS backward
        '''

        if start == end:
            return (None, 0)
        
        q = []
        next = {}
        dist = {}
        visited = set()
        
        q.append(end)
        visited.add(end)
        dist[end] = 0
        
        while len(q) > 0:
            x = q.pop(0)
            if x == start:
                break
            for y in self.parseNin(x):
                if not y in visited:
                    q.append(y)
                    visited.add(y)
                    dist[y] = dist[x] + 1
                    next[y] = x
        if not(start in visited):
            return ("No path between given start and end")
        
        path_min = []
        node = next[start]
        path_min.append(start)
        while node != end:
            path_min.append(node)
            node = next[node]
        path_min.append(end)
        return (path_min, dist[start])
    '''               
    def ceva(self):
        
        for i in self.parseX():
            for j in self.parseX():
                print(self.BFSR(i,j))
    '''    
        
    def bellman(self, start, maxLen):
        initMap = {start : 0}
        dist = [initMap]
        
        for k in range(1, maxLen+1):
            prevMap = dist[k-1]
            currMap = {}
            for y in prevMap:
                for x in self.parseNout(y):
                    if x not in currMap or currMap[x]>prevMap[y]+self.getCost(y,x) :
                        currMap[x] = prevMap[y]+self.getCost(y,x)
            dist.append(currMap)

        '''
        for y in self.parseX():
            for x in self.parseNin(y):
                value = 9999999999999
                for k in range(len(dist)-1,0,-1):
                    if (y in dist[k]) and (dist[k][y] < value):
                        v = dist[k][y]
                 
                for k in range(len(dist)-1,0,-1):
                    if x in dist[k]:
                        if (dist[k][x] + self.getCost(x,y) < v):
                            raise Exception("Negative cycles!")
                        break
    '''
        return dist
    
    def getMinCostWalk(self, dist, start, target, length):
        walk = []
        currVertex = target
        currLength = length
        while currLength > 0:
            walk.insert(0, currVertex)
            for prevVertex in self.parseNin(currVertex):
                if prevVertex in dist[currLength-1] and (
                        dist[currLength-1][prevVertex]
                        + self.getCost(prevVertex, currVertex)
                        == dist[currLength][currVertex]):
                    currVertex = prevVertex
                    break
            currLength = currLength - 1
        walk.insert(0, start)
        return walk
        
        
        
        
        ###############################################
        
    def topoSortDFS(self, v, sorted1, fullyProcessed, inProcess):

        inProcess.add(v)
        for y in self.parseNin(v):
            if y in inProcess:
                return False
            if y not in fullyProcessed:
                ok = self.topoSortDFS(y,sorted1,fullyProcessed,inProcess)
                if not ok:
                    return False
        inProcess.remove(v)
        sorted1.append(v)
        fullyProcessed.add(v)
        return True
        
    def topoSort(self):
        '''
            the Depth First Search
        '''

        topoSorted = []
        fullyProcessed = set()
        inProcess = set()
        for v in self.parseX():
            if not(v in fullyProcessed):
                ok = self.topoSortDFS(v,topoSorted,fullyProcessed,inProcess)
                if not ok:
                    raise Exception("Not a DAG!\n")
            
        return topoSorted
        
        
        
        
        
    def getMaxCostPath(self,topoSorted,s,end):
        '''
            returns a list with the path of highest cost 
            input: a topologicaly sorted list , the start vertex , the target vertex
            output: the path list
        '''
        dist = {}
        prev = {}   
        i = 0
        while (topoSorted[i] != s):
            i += 1
        topoSorted = topoSorted[i+1:len(topoSorted)]
        dist[s] = 0
        prev[s] = -1    
            
        for x in topoSorted:
            if len(self.parseNin(x)) == 0:
                dist[x] = 0
            else:
                for y in self.parseNin(x):
                    if y in topoSorted or y == s:
                        if x not in dist.keys() or (dist[x] < dist[y] + self.getCost(y,x)):
                            dist[x] = dist[y] + self.getCost(y,x)
                            prev[x] = y
    
        pathMax = []
        vertex = end
        while vertex != s:
            if not vertex in prev.keys():
                raise Exception("There is no path between %d and %d"%(s,end))
            pathMax.append(vertex)
            vertex = prev[vertex]
        if vertex != s:
            raise Exception("There is no path between %d and %d"%(s,end))
        pathMax.append(s)
        pathMax.reverse()
        return pathMax
        
        
        
        
        
    def hamiltoneanCycle(self):
        '''Returns a Hamiltonean cycle in g, if one exists, as a list of vertices,
        with the first and the last vertex on the list being equal (the length of
        the returned list will be n+1).
        Returns None if no Hamiltonean cycle exists in g.'''
        
        start_vertex = None
    
        
        for x in self.parseX():
            start_vertex = x
            break
        
        sol = []
    
        self.dfs([ start_vertex ], sol)
        
        if( sol == [] ):
            return "No hamiltonian cycle!"
        
        return sol

    def dfs(self, current_path, solution):
        '''
        the dfs function will put the hamiltonean cycle in solution if one exists
        '''
        current_node = current_path[-1]
        
        if( len( current_path ) == self.verticesNum() ):
            if( current_path[ 0 ] in self.parseNout( current_node ) and solution == [] ):
                for it in current_path:
                    solution.append( it )
                solution.append( current_path[ 0 ] )
            return
        
        for v in self.parseNout( current_node ):
            if ( v not in current_path ):
                current_path.append( v )
                self.dfs(current_path, solution)
                current_path.pop()
        
        
        
    def ham(self):
        lis = []
        for a in self.parseEdges():
            lis.append(a)
            
        ok = True
        while(ok):
            ok = False
            for i in range(len(lis)-1):
                (x,y) = lis[i]
                (x1,y1) = lis[i+1]
                if(self.getCost(x, y)>self.getCost(x1, y1)):
                    (a,b) = (x,y)
                    lis[i] = (x1,y1)
                    lis[i+1] = (a,b)
                    ok = True
                    ''' sorted list of edges'''
                    
        res = []
        visited = []
        for i in range(len(lis)):
            (x,y) = lis[i]
            nx = 0
            ny = 0
            for j in range(len(res)):
                (a,b) = res[j]
                if a == x or b == x:
                    nx +=1
                if a == y or b == y:
                    ny +=1
                    
                    
            if(nx<2 and ny<2):
                res.append((x,y))
        
        
        
        
        
        print(lis)
        print(res)
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
    
            