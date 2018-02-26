'''
Created on Mar 24, 2017

@author: God
'''
from Domain.DirectedGraph import accessible


class Controller:
    def __init__(self, repo):
        self._repo = repo
    def getNrVertices(self):
        graph = self._repo.getGraph()
        vertices = graph.parseX()
        return len(vertices)
    def checkForEdge(self,v1,v2):
        graph = self._repo.getGraph()
        v1Out = graph.parseNout(v1)
        for i in v1Out:
            if i == v2:
                return 0
        return 1
    def getDegree(self, v):
        graph = self._repo.getGraph()
        vIn = graph.parseNin(v)
        vOut = graph.parseNout(v)
        return (len(vIn),len(vOut))
    def getOutboundEdges(self,v):
        graph = self._repo.getGraph()
        return graph.parseNout(v)
    def getInboundEdges(self,v):
        graph = self._repo.getGraph()
        return graph.parseNin(v)
    def getCost(self):
        graph = self._repo.getGraph()
        return graph._value;
    def getVertices(self):
        graph = self._repo.getGraph()
        return graph._dictOut.keys()
    def addVertex(self,v):
        graph = self._repo.getGraph()
        if v in graph._dictOut.keys():
            return 1
        else:
            self._repo.addVertex(v)
    def deleteVertex(self,v):
        graph = self._repo.getGraph()
        if not v in graph._dictOut.keys():
            return 1
        else:
            self._repo.deleteVertex(v)
    def addEdge(self,v1,v2,c):
        graph = self._repo.getGraph()
        if (v1,v2) in graph._value.keys():
            return 1
        else:
            self._repo.addEdge(v1,v2,c)
            return 0
    def deleteEdge(self,v1,v2):
        graph = self._repo.getGraph()
        if not (v1,v2) in graph._value.keys():
            return 1
        else:
            self._repo.deleteEdge(v1,v2)
            return 0

    def CountIsolatedVertices(self):
        graph = self._repo.getGraph()
        count=0
        for v in graph._dictOut.keys():
            if len(graph._dictOut[v])==0:
                if len(graph._dictIn[v])==0:
                    count+=1
        return count

    def BFS(self, end, start):
        g = self._repo.getGraph()

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
#validez cu previous daca nu are parinte
            for y in g.parseNin(x):
                if y not in visited:
                    q.append(y)
                    visited.add(y)
                    dist[y] = dist[x] + 1
                    prev[y] = x

        minPath = []
        node = prev[end]
        minPath.append(end)
        while node != start:
            minPath.append(node)
            node = prev[node]
        minPath.append(start)
        minPath.reverse()
        return (minPath, dist[end])

    def Ford2(self,start ,end):
        g = self._repo.getGraph()

        dist = [-1] * (int(g.n) + 1)
        prev = [-1] * (int(g.n) + 1)


        dist[start] = 0
        changed = True
        while changed :
            changed = False
            for x in g.parseX():
                for y in g.parseNout(x):
                    if dist[y] > dist[x] + g.getCost(x, y):
                        dist[y] = dist[x] + g.getCost(x, y)
                        prev[y] = x
                        changed = True
        return [dist, prev]


    def Ford(self, start, end):
        g = self._repo.getGraph()
        distance = [-1] * (int(g.n) + 1)
        predecesor = [-1] * (int(g.n) + 1)

        for vertex in g.parseX():
            for v2 in g.parseNout(vertex):
                distance[int(vertex)] = float('Inf')
                distance[int(v2)] = float('Inf')
                predecesor[int(v2)] = None
                predecesor[int(vertex)] = None

        distance[start] = 0

        for parc in range(int(g.n)):
            for i in g.parseX():
                for j in g.parseNout(i):

                    if distance[int(i)] + int(g.getCost(i, j)) < distance[int(j)]:
                        distance[int(j)] = distance[int(i)] + int(g.getCost(i, j))
                        predecesor[int(j)] = int(i)

        for i in g.parseX():
            for j in g.parseNout(i):
                if distance[int(i)] + int(g.getCost(i, j)) < distance[int(j)]:
                    print("Negative cycles detected")
                    return None

        return [distance, predecesor]

    def getPath(self, start, end):
        preList = self.Ford2(start, end)
        if preList == None:
            return
        preList = preList[1]
        path = []
        if start > end:
            start, end = end, start

        while end != None:
            for i, e in list(enumerate(preList)):
                if i == end:
                    path.append([e, i])
                    end = e

        return list(reversed(path))[1:]
