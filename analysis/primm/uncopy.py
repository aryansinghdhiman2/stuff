import numpy as np
from sys import maxsize
from matplotlib import pyplot as plt
import networkx as nx

class undirectedEdge():
    def __init__(self,source,destination,weight):
        self.source = source
        self.destination = destination
        self.weight = weight
    def arrange(self):
        if(self.source>self.destination):
            temp = self.destination
            self.destination = self.source
            self.source = temp
        else: pass

def replace_with_maxsize(matrix):
    for i in range(0,matrix.shape[0]):
        for j in range(0,matrix.shape[1]):
            if(matrix[i,j]==0):
                matrix[i,j]=maxsize

def replace_with_zeroes(matrix:np.matrix):
    for i in range(0,matrix.shape[0]):
        for j in range(0,matrix.shape[1]):
            if(matrix[i,j]==maxsize):
                matrix[i,j]=0

def create_edge_list(n):
    edge_list = []
    print('Get ready to enter edges: [Note that index of nodes starts from 0]')
    print("Enter edges in order of source weight destination")
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

        edge = undirectedEdge(source,destination,weight)
        edge.arrange()
        exist = 0
        for ele in edge_list:
            if(ele==edge):
                print("Already Exists")
                exist = 1
                break
        if(not exist):
            edge_list.append(edge)
    
    return edge_list
        
def create_cost_matrix(n,edge_list):
    matrix = np.matrix(np.zeros((n,n),dtype=np.int64))

    for edge in edge_list:
        matrix[edge.source,edge.destination] = edge.weight
        matrix[edge.destination,edge.source] = edge.weight

    return matrix

def get_next_edge_node(matrix,near):
    minimum = maxsize
    coordinate = 0
    for j in range(0,matrix.shape[0]):
        if(near[j]!=-1):
            if(matrix[j,near[j]]<minimum):
                coordinate = j
                minimum = matrix[j,near[j]]
    return coordinate

def graph_plotter(matrix):
    graph = nx.from_numpy_array(matrix)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,font_color='white',node_color='red')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels)
    plt.show()

def tree_plotter(matrix,tree):
    graph = nx.from_numpy_array(matrix)
    nx.draw(graph,pos=layout,with_labels=True,font_color='white',edge_color='white',node_color='red')

    treeCopy = np.copy(tree)
    remove_indices = []
    for i in range(0,treeCopy.shape[0]):
        if(treeCopy[i,2]==-1):
            remove_indices.append(i)
    treeCopy=np.delete(treeCopy,remove_indices,axis=0)

    treeGraph=nx.Graph()
    treeGraph.add_weighted_edges_from(treeCopy)
    treeLabels = nx.get_edge_attributes(treeGraph,"weight")
    nx.draw(treeGraph,pos=layout,with_labels=True,font_color='white',node_color='red')
    nx.draw_networkx_edge_labels(treeGraph,pos=layout,edge_labels=treeLabels)
    plt.show()\

def primm(matrix):
    #Get edge with minimum cost
    l,k=np.unravel_index(matrix.argmin(),matrix.shape)
    minimumCost = matrix[l,k]

    #initialize tree and add first minimum edge to it
    tree = np.full((matrix.shape[0]-1,3),fill_value=[-1,-1,-1])
    tree[0]=[l,k,matrix[l,k]]
    tree_plotter(matrix,tree)
    #initialze near array which specifies neighbour
    near = np.full(matrix.shape[0],fill_value=-1,dtype=int)
    for i in range(0,matrix.shape[0]):
        if(matrix[i,l]<matrix[i,k]):
            near[i]=l
        else:
            near[i]=k
    near[l]=near[k]=-1
    
    #add edges to the tree
    for i in range(1,matrix.shape[0]-1):
        j=get_next_edge_node(matrix,near)
        tree[i]=[j,near[j],matrix[j,near[j]]]
        minimumCost+=matrix[j,near[j]]
        near[j]=-1
        for k in range(0,matrix.shape[0]):
            if((near[k]!=-1) and (matrix[k,near[k]]>matrix[k,j])):
                near[k]=j
        #display added edge
        tree_plotter(matrix,tree)
    
    return {'Cost':minimumCost,'Tree':tree}

if(__name__=="__main__"):
    n = int(input("Enter number of nodes: "))
    edge_list=create_edge_list(n)
    matrix=create_cost_matrix(n,edge_list)
    layout = nx.spring_layout(nx.from_numpy_array(matrix))
    graph_plotter(matrix)
    replace_with_maxsize(matrix)
    result=primm(matrix)
    replace_with_zeroes(matrix)
    plt.show()



# adj= [[0,28,0,0,0,10,0],
#     [28,0,16,0,0,0,14],
#     [0,16,0,12,0,0,0],
#     [0,0,12,0,22,0,18],
#     [0,0,0,22,0,25,24],
#     [10,0,0,0,25,0,0],
#     [0,14,0,18,24,0,0]]
# matrix=np.matrix(adj,dtype=np.int64)


    # adj= [[0, 0, 3, 0, 0],    
    #     [0, 0, 10, 4, 0],    
    #     [3, 10, 0, 2, 6],    
    #     [0, 4, 2, 0, 1],    
    #     [0, 0, 6, 1, 0]];   
    # matrix=np.matrix(adj,dtype=np.int64)
