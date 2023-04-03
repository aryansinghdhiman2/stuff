import numpy as np
from sys import maxsize
from matplotlib import pyplot as plt
import networkx as nx
import termtables as tt
newmaxsize = maxsize/2-1

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

def select(processed:list,dist:list):
    minimum = newmaxsize
    index = 0
    for i in range(0,len(processed)):
        if(processed[i]==False):
            if(dist[i]<minimum):
                minimum=dist[i]
                index=i
    return index

def update_distance(selected,processed:list,dist:list,cost:np.matrix):
    for i in range(0,cost.shape[1]):
        if(processed[i]==False):
            if(dist[i]>(dist[selected]+cost[selected,i])):
                dist[i]=dist[selected]+cost[selected,i]

def dijkastra(source,cost:np.matrix):
    n = cost.shape[0]
    processed = [False]*n
    dist=[0]*n
    for i in range(0,n):
        dist[i]=cost[source,i]

    processed[source]=True
    dist[source]=0.0

    for num in range(0,n-1):
        selected = select(processed,dist)
        processed[selected]=True
        update_distance(selected,processed,dist,cost)
    
    return dist


def drawgraph(graph:nx.DiGraph):
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,node_color='red',font_color='white')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels)
    plt.show()

def printSol(distance:list[int],source):
    header=[i for i in range(0,len(distance))]
    header=['']+header
    for i in range(0,len(distance)):
        if(distance[i]==newmaxsize):
            distance[i]='inf'
    distance=[source]+distance
    fin = [header,distance]
    tt.print(fin,style=tt.styles.rounded)

if(__name__ =="__main__"):
    n = int(input("Enter number of nodes: "))
    graph=getInput(n)
    matrix = nx.to_numpy_array(graph,dtype=np.int64,nonedge=newmaxsize)
    layout = nx.spring_layout(nx.to_undirected(graph))
    # drawgraph(graph)
    source=int(input('Enter source vertex: '))
    if(source<0 or source>=n):
        print("Invalid source vertex")
        exit()
    distance=dijkastra(source,matrix)
    printSol(distance,source)
    
    # print('Distance Matrix is: ')
    # for i in range(0,len(distance)):
    #     if(distance[i]==newmaxsize):
    #         distance[i]='infinity'
    # print(distance)


    # adj= [[0,0,0,0,0,0,0,0],
    # [300,0,0,0,0,0,0,0],
    # [1000,800,0,0,0,0,0,0],
    # [0,0,1200,0,0,0,0,0],
    # [0,0,0,1500,0,250,0,0],
    # [0,0,0,1000,0,0,900,1400],
    # [0,0,0,0,0,0,0,1000],
    # [1700,0,0,0,0,0,0,0]]
    # print(f"Source is: {source}")
    # from random import randint
    # source = randint(0,n-1)
    #     n=5
    # adj= cost_matrix = cost_matrix = [
    # [0, 11, 0, 0, 0],
    # [16, 0, 0, 0, 19],
    # [0, 10, 0, 10, 0],
    # [19, 0, 19, 0, 0],
    # [18, 0, 0, 0, 0]
# ]
# matrix=np.matrix(adj,dtype=np.int64)

    # n=8
    # graph = nx.DiGraph()
    # for i in range(0,n):
    #     graph.add_node(i)
    # graph.add_edge(1,0,weight=300)
    # graph.add_edge(2,1,weight=800)
    # graph.add_edge(2,0,weight=1000)
    # graph.add_edge(3,2,weight=1200)
    # graph.add_edge(5,6,weight=900)
    # graph.add_edge(6,7,weight=1000)
    # graph.add_edge(7,0,weight=1700)
    # graph.add_edge(4,3,weight=1500)
    # graph.add_edge(4,5,weight=250)
    # graph.add_edge(5,3,weight=1000)
    # graph.add_edge(5,7,weight=1400)