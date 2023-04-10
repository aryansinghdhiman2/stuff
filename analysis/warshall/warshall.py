import numpy as np
from sys import maxsize
from matplotlib import pyplot as plt
import networkx as nx
import termtables as tt
newmaxsize = maxsize/4-1

def warshall(cost:np.matrix):
    allCost = cost.copy()
    for k in range(0,allCost.shape[0]):
        for i in range(0,allCost.shape[0]):
            for j in range(0,allCost.shape[1]):
                if(allCost[i,j]>allCost[i,k]+allCost[k,j]):
                    allCost[i,j]=allCost[i,k]+allCost[k,j]
    return allCost

def getInput(n:int):
    graph = nx.DiGraph()
    print('Get ready to enter edges: [Note that index of nodes starts from 0]')
    print("Enter directedEdges in order of source weight destination")
    while(True):
        cont = int(input('Enter 0 if you want to enter more edges else enter 1: '))
        if(cont):
            break
        source = int(input('Source: '))
        destination = int(input('Destination: '))
        weight = int(input('Weight: '))

        if((source >= n or destination >= n) or (source==destination)):
            print("Invalid")
            continue

        if(graph.has_edge(source,destination)):
            print("Already Exists")
        else: graph.add_edge(source,destination,weight=weight)
    
    return graph

def drawgraph(graph:nx.DiGraph):
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,node_color='red',font_color='white')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels)
    plt.show()

def printSolution(allCost:np.matrix):
    sol=allCost.tolist()
    # print(*sol)
    for i in range(0,len(sol)):
        for j in range(0,len(sol[i])):
            if(sol[i][j]==newmaxsize):
                sol[i][j]='inf'
    header = [i for i in range(0,allCost.shape[0])]
    header=[f'A^{len(sol)}']+header
    for i in range(0,allCost.shape[0]):
        sol[i]=[i]+sol[i]
    # print(sol)
    tt.print(sol,header=header,style=tt.styles.rounded)


if(__name__ =="__main__"):
    # n = int(input("Enter number of nodes: "))
    # graph=getInput(n)
    n=6
    graph=nx.DiGraph()
    for i in range(0,n):
        graph.add_node(i)
    graph.add_edge(0,3,weight=14)
    graph.add_edge(0,1,weight=43)
    graph.add_edge(1,3,weight=23)
    graph.add_edge(2,4,weight=24)
    graph.add_edge(2,5,weight=35)
    graph.add_edge(3,4,weight=42)
    graph.add_edge(5,0,weight=34)
    matrix = nx.to_numpy_array(graph,dtype=np.int64,nonedge=newmaxsize)
    layout = nx.spring_layout(nx.to_undirected(graph))
    for i in range(0,matrix.shape[0]):
        matrix[i,i]=0
    drawgraph(graph)
    allCost=warshall(matrix)
    printSolution(allCost)

# sol=[[0, 9, 4, 6], [1, 5, 9, 2], [2, 3, 7, 9]]
    # graph = nx.DiGraph()
    # graph.add_edge(0,1,weight=4)
    # graph.add_edge(1,0,weight=6)
    # graph.add_edge(0,2,weight=11)
    # graph.add_edge(2,0,weight=3)
    # graph.add_edge(1,2,weight=2)
        # graph = nx.DiGraph()
    # n=6
    # for i in range(0,n):
    #     graph.add_node(i)
    # graph.add_edge(0,3,weight=14)
    # graph.add_edge(0,1,weight=43)
    # graph.add_edge(1,3,weight=23)
    # graph.add_edge(2,4,weight=24)
    # graph.add_edge(2,5,weight=35)
    # graph.add_edge(3,4,weight=42)
    # graph.add_edge(5,0,weight=34)