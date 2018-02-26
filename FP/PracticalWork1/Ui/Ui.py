'''
Created on Mar 24, 2017

@author: God
'''

class Ui:
    def __init__(self, ctrl):
        self._ctrl = ctrl
    def printMenu(self):
        print("\nMenu:")
        print("1  - Print the number of vertices")
        print("2  - Check if there is an edge between two vertices")
        print("3  - Get the in degree and the out degree of a vertex")
        print("4  - Iterate through the set of outbound edges of a vertex")
        print("5  - Iterate through the set of inbound edges of a vertex")
        print("6  - Retrieve the value attached to an edge")
        print("7  - Modify the value attached to an edge")
        print("8  - Add an edge")
        print("9  - Remove an edge")
        print("10 - Add a vertex")
        print("11 - Remove a vertex.")
        print("12 - Print the number of isolated vertices.")
        print("13 - Do a reverse BFS to find the shortest path between 2 vertices.")
        print("14 - Get Path using ford.\n")
    def start(self):
        while(True):
            self.printMenu()
            command = input("Please enter the command: ")
            if int(command) == 1:
                nrVertices = self._ctrl.getNrVertices()
                print("The number of vertices is " + str(nrVertices)+".")
            elif int(command) == 2:
                nrVertices = self._ctrl.getNrVertices()
                vertex1 = self.readVertex("Vertex1 :", self._ctrl.getVertices())
                vertex2 = self.readVertex("Vertex2 :", self._ctrl.getVertices())
                if vertex1 < 0 or vertex1 > nrVertices or vertex2 < 0 or vertex2 > nrVertices:
                    print("Invalid vertices!")
                    continue
                res = self._ctrl.checkForEdge(vertex1,vertex2)
                if res == 0:
                    print("There is an edge from the vertex " + str(vertex1) + " to the vertex " + str(vertex2) + ".")
                else:
                    print("There is no edge from the vertex " + str(vertex1) + " to the vertex " + str(vertex2) + ".")
            elif int(command) == 3:
                nrVertices = self._ctrl.getNrVertices()
                vertex = self.readVertex("Vertex :", self._ctrl.getVertices())
                res = self._ctrl.getDegree(vertex)
                print("In degree: " + str(res[0]))
                print("Out degree: " + str(res[1]))
            elif int(command)== 4:
                nrVertices = self._ctrl.getNrVertices()
                vertex = self.readVertex("Vertex :", self._ctrl.getVertices())
                if vertex < 0 or vertex > nrVertices:
                    print("Invalid vertex!")
                    continue
                res = self._ctrl.getOutboundEdges(vertex)
                for i in res:
                    print(str(vertex)+"->"+str(i))
                if res==[]:
                    print("There are no outbound edges!")
            elif int(command) == 5:
                nrVertices = self._ctrl.getNrVertices()
                vertex = self.readVertex("Vertex :", self._ctrl.getVertices())
                if vertex < 0 or vertex > nrVertices:
                    print("Invalid vertex!")
                    continue
                res = self._ctrl.getInboundEdges(vertex)
                for i in res:
                    print(str(i)+"->"+str(vertex))
                if res==[]:
                    print("There are no inbound edges!")

            elif int(command) == 6:
                dict = self._ctrl.getCost()
                vertex1 = self.readVertex("Vertex1 :", self._ctrl.getVertices())
                vertex2 = self.readVertex("Vertex2 :", self._ctrl.getVertices())
                if (vertex1,vertex2) in dict.keys():
                    cost = dict[(vertex1,vertex2)]
                    print("The cost is: " + str(cost))
                else:
                    print("There edge doesn't exist!")
            elif int(command) == 7:
                dict = self._ctrl.getCost()
                vertex1 = self.readVertex("Vertex1 :", self._ctrl.getVertices())
                vertex2 = self.readVertex("Vertex2 :", self._ctrl.getVertices())
                newCost  = int(input("New cost: "))
                if (vertex1,vertex2) in dict.keys():
                    dict[(vertex1,vertex2)] = newCost
                else:
                    print("There edge doesn't exist!")
            elif int(command) == 8:
                vertex1 = self.readVertex("Vertex1 :", self._ctrl.getVertices())
                vertex2 = self.readVertex("Vertex2 :", self._ctrl.getVertices())
                cost  = int(input("The cost: "))
                res = self._ctrl.addEdge(vertex1,vertex2,cost)
                if res == 1:
                    print("Edge already exists!")
                else:
                    print("Edge added successfully!")
            elif int(command) == 9:
                vertex1 = self.readVertex("Vertex1 :", self._ctrl.getVertices())
                vertex2 = self.readVertex("Vertex2 :", self._ctrl.getVertices())
                res = self._ctrl.deleteEdge(vertex1,vertex2)
                if res == 1:
                    print("Edge doesn't exist!")
                else:
                    print("Edge deleted successfully!")
            elif int(command) == 10:
                vertex = int(input("Enter vertex number: "))
                res = self._ctrl.addVertex(vertex)
                if res == 1:
                    print("Vertex already exists!")
                else:
                    print("Vertex added successfully!")
            elif int(command) == 11:
                vertex  = int(input("Vertex: "))
                res = self._ctrl.deleteVertex(vertex)
                if res == 1:
                    print("Vertex doesn't exist!")
                else:
                    print("Vertex deleted successfully!")
            elif int(command) == 12:
                res=self._ctrl.CountIsolatedVertices()
                print("The number of isolated vertices is "+ str(res) +".")
            elif int(command) == 13:
                vertex1 = self.readVertex("Vertex1 :", self._ctrl.getVertices())
                vertex2 = self.readVertex("Vertex2 :", self._ctrl.getVertices())

                res = self._ctrl.getOutboundEdges(vertex1)
                if res == []:
                    print("Can't reach vertex 1!")
                    continue
                res = self._ctrl.getInboundEdges(vertex2)
                if res == []:
                    print("There are no inbound edges to vertex 2!")
                    continue
                cale,dict = self._ctrl.BFS(vertex1,vertex2)

                print(cale)
                print (dict)

            elif int(command) == 14:
                vertex1 = self.readVertex("Vertex1 :", self._ctrl.getVertices())
                vertex2 = self.readVertex("Vertex2 :", self._ctrl.getVertices())

                print(self._ctrl.getPath(vertex1,vertex2))

            else:
                print("You decided to terminate the program !")
                break
                    
    def readVertex(self, msg, keys):
        x = int(input(msg).strip())
        while x not in keys and x != "c":
            print ("That vertex does not exist!")
            x = x = int(input(msg).strip())
        if x == "c":
            return -1
        return x
                    

        