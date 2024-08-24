import networkx as nx
from matplotlib import pyplot as plt
from sys import maxsize

def getMin(graph:nx.DiGraph,node:int,cost:list[int]):
    mini = maxsize
    least = node
    for r in graph.neighbors(node):
        if(graph[node][r]['weight']+cost[r]<mini):
            mini=graph[node][r]['weight']+cost[r]
            least=r
    return least

def fgraph(graph:nx.DiGraph,layers:int):
    cost = [0]*len(graph)
    decision = [i for i in range(0,len(graph))]
    path = [0]*layers
    for j in range(len(graph)-2,-1,-1):
        r = getMin(graph,j,cost)
        cost[j]=graph[j][r]['weight']+cost[r]
        decision[j]=r
    path[0]=0
    path[layers-1]=len(graph)-1
    
    for j in range(1,layers):
        path[j]=decision[path[j-1]]
    return path

def convert(path:list[int]):
    pathList = []
    for i in range(0,len(path)-1):
        pathList.append([path[i],path[i+1]])
    return pathList

def getInput():
    n = int(input('Enter number of nodes: '))
    graph = nx.DiGraph()
    number_of_layers=int(input('Enter number of layers: '))
    i=0
    while(i<n):
        layer=int(input(f'Enter layer number for {i}: '))
        if(layer>=number_of_layers):
            print("Invalid")
            continue
        graph.add_node(i,subset=layer)
        i+=1

    print("Enter Edges: ")
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
    
    return graph,number_of_layers

def drawgraph(graph:nx.DiGraph):
    layout=nx.multipartite_layout(graph)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,node_color='red',font_color='white')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels,label_pos=0.39)
    plt.show()

def drawFinalGraph(graph:nx.DiGraph,pathList:list[int]):
    layout=nx.multipartite_layout(graph)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,font_color='white',node_color='red')
    nx.draw_networkx_edges(graph,pos=layout,edgelist=pathList,edge_color='red')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels,label_pos=0.39)
    plt.show()

if(__name__=="__main__"):
    # graph,layers=getInput()
    graph = nx.DiGraph()
    graph.add_node(0,subset=0)
    graph.add_node(1,subset=1)
    graph.add_node(2,subset=1)
    graph.add_node(3,subset=2)
    graph.add_node(4,subset=2)
    graph.add_node(5,subset=2)
    graph.add_node(6,subset=3)
    graph.add_node(7,subset=3)
    graph.add_node(8,subset=4)

    graph.add_edge(0,1,weight=5)
    graph.add_edge(0,2,weight=2)
    graph.add_edge(1,5,weight=3)
    graph.add_edge(1,3,weight=3)
    graph.add_edge(2,5,weight=8)
    graph.add_edge(2,4,weight=5)
    graph.add_edge(2,3,weight=6)
    graph.add_edge(3,6,weight=1)
    graph.add_edge(3,7,weight=4)
    graph.add_edge(4,6,weight=6)
    graph.add_edge(4,7,weight=2)
    graph.add_edge(5,6,weight=6)
    graph.add_edge(5,7,weight=2)
    graph.add_edge(6,8,weight=7)
    graph.add_edge(7,8,weight=3)
    layers=5
    drawgraph(graph)
    pathList=convert(fgraph(graph,layers))
    drawFinalGraph(graph,pathList)


    # graph = nx.DiGraph()
    # graph.add_node(0,subset=0)
    # graph.add_node(1,subset=1)
    # graph.add_node(2,subset=1)
    # graph.add_node(3,subset=2)
    # graph.add_node(4,subset=2)
    # graph.add_node(5,subset=2)
    # graph.add_node(6,subset=3)
    # graph.add_node(7,subset=3)
    # graph.add_node(8,subset=4)

    # graph.add_edge(0,1,weight=5)
    # graph.add_edge(0,2,weight=2)
    # graph.add_edge(1,5,weight=3)
    # graph.add_edge(1,3,weight=3)
    # graph.add_edge(2,5,weight=8)
    # graph.add_edge(2,4,weight=5)
    # graph.add_edge(2,3,weight=6)
    # graph.add_edge(3,6,weight=1)
    # graph.add_edge(3,7,weight=4)
    # graph.add_edge(4,6,weight=6)
    # graph.add_edge(4,7,weight=2)
    # graph.add_edge(5,6,weight=6)
    # graph.add_edge(5,7,weight=2)
    # graph.add_edge(6,8,weight=7)
    # graph.add_edge(7,8,weight=3)