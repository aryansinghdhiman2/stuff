from sys import maxsize

adj= [[0,28,0,0,0,10,0],
      [28,0,16,0,0,0,14],
      [0,16,0,12,0,0,0],
      [0,0,12,0,22,0,18],
      [0,0,0,22,0,25,24],
      [10,0,0,0,25,0,0],
      [0,14,0,18,24,0,0]]
# print(adj)

def replace_with_max(array):
    for i in range(0,len(array)):
        for j in range(0,len(array)):
            if(array[i][j]==0):
                array[i][j]=maxsize

def get_next_edge_node(matrix,near):
    minimum = maxsize
    coordinate = 0
    for j in range(0,matrix.shape[0]):
        if(near[j]!=-1):
            if(matrix[j,near[j]]<minimum):
                coordinate = j
                minimum = matrix[j,near[j]]
    return coordinate

def replace_with_zero(array):
    for i in range(0,len(array)):
        for j in range(0,len(array)):
            if(array[i][j]==maxsize):
                array[i][j]=0

replace_with_max(adj)

from matplotlib import pyplot as plt
import networkx as nx

import numpy as np
mtr = np.matrix(adj)
# print(mtr.shape)
# print(mtr.min())
l,k=np.unravel_index(mtr.argmin(),mtr.shape)
# print([l,k])
# print(mtr[l,k])
tree=[]
minCost=mtr[l,k]
tree.append([l,k,mtr[l,k]])
near=[]
for i in range(0,mtr.shape[0]):
    if(mtr[i,l]<mtr[i,k]):
        near.append(l)
    else:
        near.append(k)
near[k]=near[l]=-1

print(near)

for i in range(1,mtr.shape[0]-1):
    j=get_next_edge_node(mtr,near)
    tree.append([j,near[j],mtr[j,near[j]]])
# print(tree)
    minCost+=mtr[j,near[j]]
    near[j]=-1
    for k in range(0,mtr.shape[0]):
        if((near[k]!=-1) and (mtr[k,near[k]]>mtr[k,j])):
            near[k]=j

replace_with_zero(adj)
graphArray = np.matrix(adj)
graph = nx.from_numpy_array(graphArray)
layout = nx.spring_layout(graph)
# layout = nx.circular_layout(graph)
# layout = nx.kamada_kawai_layout(graph)
# layout = nx.planar_layout(graph)
# layout = nx.shell_layout(graph)
# layout = nx.spectral_layout(graph)
# layout = nx.spiral_layout(graph)

nx.draw(graph,pos=layout,with_labels=True,font_color='white')
labels = nx.get_edge_attributes(graph, "weight")
nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels)

# plt.show()

treeGraph = nx.Graph()

treeGraph.add_weighted_edges_from(tree)
nx.draw(treeGraph,pos=layout,with_labels=True,font_color='white')
treeLabels = nx.get_edge_attributes(treeGraph,"weight")
nx.draw_networkx_edge_labels(treeGraph,pos=layout,edge_labels=treeLabels)
# plt.show()


compGraph = nx.minimum_spanning_tree(graph,algorithm='prim')
nx.draw(compGraph,pos=layout,with_labels=True,font_color='white',node_color='red')
compLabels = nx.get_edge_attributes(treeGraph,"weight")
nx.draw_networkx_edge_labels(compGraph,pos=layout,edge_labels=compLabels)
# plt.show()

print(tree)

def plotter(matrix:np.matrix,tree:np.ndarray):
    graph = nx.from_numpy_array(matrix)
    layout = nx.planar_layout(graph)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,font_color='white')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels)
    plt.show()

    treeGraph=nx.Graph()
    treeGraph.add_weighted_edges_from(tree)
    treeLabels = nx.get_edge_attributes(treeGraph,"weight")
    nx.draw(treeGraph,pos=layout,with_labels=True,font_color='white')
    nx.draw_networkx_edge_labels(treeGraph,pos=layout,edge_labels=treeLabels)
    plt.show()