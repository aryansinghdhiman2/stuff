import numpy as np
import networkx as nx
import pandas as pd
import matplotlib.pyplot as plt
import math

cost=[]
mst=[]

def prims(EdgeList,vertices):
    myList=[]
    near=[float('inf')]*vertices
    min_cost=0.0
    minimumm_spanning_Tree=[]
    selected_vertex=[]
    
    for node1,node2,cost in EdgeList:
        myList.append(((node1,node2),cost))
    matrix=np.full((vertices,vertices),float('inf'))
    for edge in myList:
        matrix[(edge[0][0])-1,(edge[0][1])-1]=edge[1]
    # print(matrix)
    # finding the first minimum cost edge in the matrix
    min_val = np.min(matrix)
    min_index = np.argmin(matrix)
    first_vertex,second_vertex  = np.unravel_index(min_index, matrix.shape)
    
    min_cost=min_cost+min_val
    minimumm_spanning_Tree.append((first_vertex+1,second_vertex+1))
    selected_vertex.append(first_vertex)
    selected_vertex.append(second_vertex)
    
    for k in range(vertices):
        if matrix[first_vertex][k]<matrix[second_vertex][k]:
            near[k]=first_vertex
        else:
            near[k]=second_vertex
    near[first_vertex]=-1
    near[second_vertex]=-1
    for k in range (1,vertices-1):
        min=float('inf')
        index1=0
        index2=0
        for i in range(vertices):
            if near[i]!=-1 and matrix[i][near[i]]<min:
                min=matrix[i][near[i]]
                index1=i
                index2=near[i]
        min_cost+=min
        selected_vertex.append(index1)
        minimumm_spanning_Tree.append((index1+1,index2+1))
        near[index1]=-1
        for i in range(vertices):
            if near[i]!=-1 and matrix[i][index1]<matrix[i][near[i]]:
                near[i]=index1
    return minimumm_spanning_Tree,cost

            
            
# getting the edges and their costs from the user
print("Enter the number of vertices : ")
vertices=int(input())
add=True
i=1
while(add==True):
    
    print(f"Enter the starting vertex, ending vertex and cost of edge {i} ")
    i+=1
    start=int(input())
    end=int(input())
    Cost=int(input())
    cost.append((start,end,Cost))
    cost.append((end,start,Cost))
    print("Would you like to enter another edge y/n?")
    response=input()
    if response=='y':
        add==True
    else:
        add==False
        break    

mst,minimum_cost=prims(cost,vertices)
print(mst)
print(minimum_cost)
# making graph:
G=nx.Graph()
for edge in cost:
    node1,node2,label=edge
    G.add_edge(node1,node2,label=label)


pos=nx.spring_layout(G)
# print(G.edges(data=True))

nx.draw_networkx_nodes(G,pos,node_color="blue")
nx.draw_networkx_edges(G,pos)
edge_labels = nx.get_edge_attributes(G,'label')
nx.draw_networkx_edge_labels(G, pos,edge_labels=edge_labels , font_color="white")

node_labels = {node: node for node in G.nodes()}
nx.draw_networkx_labels(G, pos, labels=node_labels, font_size=12)
plt.show()   
    
    
    
    
    
    
    
    
