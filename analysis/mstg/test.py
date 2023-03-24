import networkx as nx
from matplotlib import pyplot as plt
import numpy as np
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

graph = nx.DiGraph()
graph.add_node(0,subset=0)
graph.add_node(1,subset=1)
graph.add_node(2,subset=1)
graph.add_node(3,subset=1)
graph.add_node(4,subset=1)
graph.add_node(5,subset=2)
graph.add_node(6,subset=2)
graph.add_node(7,subset=2)
graph.add_node(8,subset=3)
graph.add_node(9,subset=3)
graph.add_node(10,subset=3)
graph.add_node(11,subset=4)

graph.add_edge(0,1,weight=9)
graph.add_edge(0,2,weight=7)
graph.add_edge(0,3,weight=3)
graph.add_edge(0,4,weight=2)
graph.add_edge(1,5,weight=4)
graph.add_edge(1,6,weight=2)
graph.add_edge(1,7,weight=1)
graph.add_edge(2,5,weight=2)
graph.add_edge(2,6,weight=7)
graph.add_edge(3,7,weight=11)
graph.add_edge(4,6,weight=11)
graph.add_edge(4,7,weight=8)
graph.add_edge(5,8,weight=6)
graph.add_edge(5,9,weight=5)
graph.add_edge(6,8,weight=4)
graph.add_edge(6,9,weight=3)
graph.add_edge(7,9,weight=5)
graph.add_edge(7,10,weight=6)
graph.add_edge(8,11,weight=4)
graph.add_edge(9,11,weight=2)
graph.add_edge(10,11,weight=5)

layout=nx.multipartite_layout(graph)
labels = nx.get_edge_attributes(graph, "weight")

nx.draw(graph,pos=layout,with_labels=True)
nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels,label_pos=0.35)
plt.show()

path = fgraph(graph,5)

pathList = convert(path)

nx.draw(graph,pos=layout,with_labels=True)
nx.draw_networkx_edges(graph,pos=layout,edgelist=pathList,edge_color='red')
nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels,label_pos=0.35)
plt.show()