'''
Created on Feb 28, 2017

@author: Cristian
'''
from GrafDataStructure import *

class Ui():
    
    def __init__(self,graph):
        
        self.__graph = graph
        
    @staticmethod
    def printMenu():
        string = "\tThe menu:\n"
        string +="1 - Get the number of vertices;\n"
        string +="2 - Given two vertices, find out if there is an edge between them;\n"
        string +="3 - Get the in degree and the out degree of a specified vertex;\n"
        string +="4 - Provide an iterator for the set of outbound edges (the target vertexes);\n"
        string +="5 - Provide an iterator for the set of inbound edges (the sorce vertexes);\n"
        string +="6 - Get the cost of an existing edge;\n"
        string +="7 - Set the cost of an existing edge;\n"
        string +="8 - Add or remove an existing vertex;\n"
        string +="9 - Add or remove an existing edge;\n"
        string +="10 - Save to file;\n"
        string +="11 - Load from file;\n"
        string +="12 - Find the lowest length path;\n"
        string +="13 - Find the lowest cost path between two vertices;\n"
        string +="14 - Find the highest cost path between two vertices;\n"
        string +="15 - Find a hamiltonian cycle in the graph;\n"
        string +="0 - Exit!"
        print(string)
        
    @staticmethod
    def printGraph(graph):
        '''
        prints the 3 dictionaries
        '''
        print("\n\nThe Out Dict:  "+str(graph.getDictOut()))
        print("The In Dict:  "+str(graph.getDictIn()))
        print("The Cost Dict:  "+str(graph.getDictCost())+"\n\n")
    
    def mainMenu(self):
        stop = False
        while stop==False:
            #Ui.printGraph(self.__graph)
            Ui.printMenu()
            command = input("Enter the command: ")
            if command=="0":
                stop = True
            elif command=="1":
                n = len(self.__graph.parseX())
                print("\nThe graph has %d vertices.\n" %(n))
            elif command=="2":
                try:
                    ver = False
                    x = int(input("Enter the first vertex: "))
                    y = int(input("Enter the second vertex: "))
                    ver = self.__graph.isEdge(x,y)
                except Exception as e:
                    print("Error:  "+str(e))
                if ver==False:
                    print("\nThere is no edge between %d and %d\n"%(x,y))
                else:
                    c = self.__graph.getCost(x,y)
                    print("\nThere is an edge between %d and %d with cost %d\n"%(x,y,c))
            elif command=="3":
                x = int(input("Enter the vertex:"))
                print("\nThe in degree of %d is %d"%(x,len(self.__graph.parseNin(x))))
                print("The out degree of %d is %d\n"%(x,len(self.__graph.parseNout(x))))
            elif command=="4":
                x = int(input("Enter the vertex: "))
                if not x in self.__graph.parseX():
                    print("\nThe vertex %d does not exists.\n"%x)
                else:
                    string = ""
                    for i in self.__graph.parseNout(x):
                        string +=str(i)+" "
                    string +="\n"
                    print("\nThe list of outbound edges:\n"+string)
            elif command=="5":
                x = int(input("Enter the vertex: "))
                if not x in self.__graph.parseX():
                    print("\nThe vertex %d does not exists.\n"%x)
                else:
                    string = ""
                    for i in self.__graph.parseNin(x):
                        string +=str(i)+" "
                    string +="\n"
                    print("\nThe list of inbound edges:\n"+string)
            elif command=="6":
                x = int(input("Enter the first vertex: "))
                y = int(input("Enter the second vertex: "))
                if (not(x in self.__graph.parseX())) or (not(y in self.__graph.parseX())):
                    print("One or both the verteces does not exists")
                else:
                    if self.__graph.isEdge(x,y):
                        print("\nThe cost of the edge (%d,%d) is: %d\n"%(x,y,self.__graph.getCost(x,y)))
                    else:
                        print("\nThere is no edge (%d,%d)\n"%(x,y))
            elif command=="7":
                x = int(input("Enter the first vertex: "))
                y = int(input("Enter the second vertex: "))
                if (not(x in self.__graph.parseX())) or (not(y in self.__graph.parseX())):
                    print("One or both the verteces does not exists")
                else:
                    cost = int(input("Enter the new cost: "))
                    if self.__graph.isEdge(x,y):
                        self.__graph.setCost(x,y,cost)
                        print("\nThe cost of the edge (%d,%d) is now: %d\n"%(x,y,self.__graph.getCost(x,y)))
                    else:
                        print("\nThere is no edge (%d,%d)\n"%(x,y))
            elif command=="8":
                print("1 - Add vertex;\n2 - Remove vertex;\n")
                sc = input("Enter the command: ")
                if sc=="1":
                    try:
                        x = int(input("Enter the vertex number: "))
                        self.__graph.addVertex(x)
                    except Exception as e:
                        print("Error:  "+str(e))
                elif sc=="2":
                    try:
                        x = int(input("Enter the vertex: "))
                        self.__graph.removeVertex(x)
                    except Exception as e:
                        print("Error:  "+str(e))
                else:
                    print("Invalid command!")
            elif command=="9":
                print("1 - Add edge;\n2 - Remove edge;\n")
                sc = input("Enter the command; ")
                if sc=="1":
                    try:
                        x = int(input("Enter the first vertex: "))
                        y = int(input("Enter the second vertex: "))
                        cost = int(input("Enter the cost: "))
                        self.__graph.addEdge(x,y,cost)
                    except Exception as e:
                        print("Error:  "+str(e))
                elif sc=="2":
                    try:
                        x = int(input("Enter the first vertex: "))
                        y = int(input("Enter the second vertex: "))
                        self.__graph.removeEdge(x,y)
                    except Exception as e:
                        print("Error:  "+str(e))
                else:
                    print("Invalid command!")
            elif command=="10":
                fileName = input("Enter the file name: ").strip()
                FinalGraph.writeToFile(fileName,self.__graph)
            elif command=="11":
                fileName = input("Enter the file name: ").strip()
                self.__graph = FinalGraph.readFromFile(fileName)
            elif command=="12":
                start = int(input("Enter the start vertex: "))
                target = int(input("Enter the destination vertex: "))
                l = self.__graph.BFSR(start, target)
                print(l)
            elif command=="13":
                try:
                    s = int(input("Enter the start vertex: "))
                    t = int(input("Enter the target vertex: "))
                    maxLen = int(input("Enter the max length: "))
                    #maxLen = 3*len(self.__graph.parseX())
                    dist = self.__graph.bellman(s, maxLen)
                    '''
                    if t in dist[maxLen]:
                            print (self.__graph.getMinCostWalk(dist, s, t, maxLen), dist[maxLen][t])
                    else:
                        print("\nNu!\n")
                    '''
                    for i in range(maxLen+1):
                        if t in dist[i]:
                            print (self.__graph.getMinCostWalk(dist, s, t, i), dist[i][t])
                            #break
                    
                except Exception as e:
                        print("Error:  "+str(e))
            elif command=="14":
                try:
                    s = int(input("Enter the start vertex: "))
                    t = int(input("Enter the target vertex: "))
                    l = []
                    l = self.__graph.topoSort()
                    result = self.__graph.getMaxCostPath(l, s, t) 
                    print(result)
                except Exception as e:
                    print("Error:  "+str(e))
            elif command=="15":
                print(self.__graph.hamiltoneanCycle())
            else:
                print("Invalid command!")
                    
                    
                
                
                
                    
                
            
            
