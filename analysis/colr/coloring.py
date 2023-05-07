import numpy as np
import networkx as nx
from matplotlib import pyplot as plt
import randomcolor as rc
global count
count=0
global graphDrawCount
graphDrawCount=3

def drawGraph(decision:list[int]):
    colorMap = []
    for i in decision:
        colorMap.append(*rc.RandomColor(i/23).generate(luminosity='dark'))
    # print(colorMap)
    layout=nx.kamada_kawai_layout(graph)
    nx.draw(graph,node_color=colorMap,with_labels=True,font_color='white',pos=layout,node_size=1000)
    plt.show()

def nextVal(k:int,
            numberOfColors:int,
            numberofNodes:int,
            adjacencyMatrix:np.matrix,
            decision:list[int]):
    while(True):
        decision[k]=(decision[k]+1)%(numberOfColors+1)
        if(decision[k]==0): return
        j=0
        while(j<numberofNodes):
            if((adjacencyMatrix[k,j]!=0) and decision[k]==decision[j]):
                break
            j+=1
        if(j==numberofNodes):
            return

def mColoring(k:int,
            numberOfColors:int,
            numberofNodes:int,
            adjacencyMatrix:np.matrix,
            decision:list[int]):
    while(True):
        nextVal(k,numberOfColors,numberofNodes,adjacencyMatrix,decision)
        if(decision[k]==0):return
        if(k==numberofNodes-1):
            print(decision)
            global graphDrawCount
            if(graphDrawCount):
                drawGraph(decision)
                graphDrawCount-=1
            global count
            count+=1
        else:mColoring(k+1,numberOfColors,numberofNodes,adjacencyMatrix,decision)

if(__name__=='__main__'):
    numberOfNodes=int(input("Enter Number of Nodes: "))
    graph=nx.Graph()
    while(True):
        i=int(input("Enter 1 if you want to enter edge else 0: "))
        if(i==0):
            break
        edges=list(map(int,input("Enter Edge: ").strip().split()))
        graph.add_edge(*edges)
    colors=int(input("Enter Number of Colors: "))

    decision=[0]*numberOfNodes
    adjadency=nx.to_numpy_array(graph)
    mColoring(0,colors,numberOfNodes,adjadency,decision)
    print(f'Number of Ways of Coloring are: {count}')

# k=0
# numberOfColors=2
# nodes=5

# graph = nx.Graph()
# graph.add_edge(1,2)
# graph.add_edge(2,3)
# graph.add_edge(3,4)
# graph.add_edge(4,1)
# graph.add_edge(4,5)
# graph.add_edge(1,5)
# adj=nx.to_numpy_array(graph)
# decision = [0]*nodes

# mColoring(k,numberOfColors,nodes,adj,decision)
# print(f'Number of colorings are: {count}')
