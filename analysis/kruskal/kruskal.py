import numpy as np
import heapq
from sys import maxsize
from matplotlib import pyplot as plt
import networkx as nx

class undirectedEdge():
    def __init__(self,source:int,destination:int,weight:int):
        self.source = source
        self.destination = destination
        self.weight = weight
    
    def __eq__(self, __o:'undirectedEdge') -> bool:
        if(self.source == __o.source and self.destination == __o.destination):
            return True
        elif(self.source == __o.destination and self.destination == __o.source):
            return True
        else: return False

    def __lt__(self,__o:'undirectedEdge') -> bool:
        if(self.weight < __o.weight):
            return True
        else: return False

    def convertToList(self)->list[int]:
        return [self.source,self.destination,self.weight]
    
    def arrange(self):
        if(self.source>self.destination):
            temp = self.destination
            self.destination = self.source
            self.source = temp
        else: pass

def replace_with_maxsize(matrix:np.matrix):
    for i in range(0,matrix.shape[0]):
        for j in range(0,matrix.shape[1]):
            if(matrix[i,j]==0):
                matrix[i,j]=maxsize

def replace_with_zeroes(matrix:np.matrix):
    for i in range(0,matrix.shape[0]):
        for j in range(0,matrix.shape[1]):
            if(matrix[i,j]==maxsize):
                matrix[i,j]=0

def create_edge_list(n:int)->list[undirectedEdge]:
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
        exist = False
        for ele in edge_list:
            if(ele==edge):
                print("Already Exists")
                exist = True
                break
        if(not exist):
            edge_list.append(edge)
    
    return edge_list
        
def create_cost_matrix(n,edge_list:list[undirectedEdge])->np.matrix:
    matrix = np.matrix(np.zeros((n,n),dtype=np.int64))

    for edge in edge_list:
        matrix[edge.source,edge.destination] = edge.weight
        matrix[edge.destination,edge.source] = edge.weight

    return matrix



def graph_plotter(matrix:np.matrix):
    graph = nx.from_numpy_array(matrix)
    # layout = nx.kamada_kawai_layout(graph)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,font_color='white',node_color='red')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels)
    plt.show()
    return layout

def tree_plotter(matrix:np.matrix,tree:np.ndarray):
    graph = nx.from_numpy_array(matrix)
    # layout = nx.kamada_kawai_layout(graph)
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
    plt.show()

def find_parent(parent:list[int],i:int)->int:
    if(parent[i]==-1):
        return i
    else: return find_parent(parent,parent[i])

def union(parent:list[int],edge:undirectedEdge):
    edge.arrange()
    parent[edge.destination]=edge.source

def kruskal(edge_list:list[undirectedEdge],cost_matrix:np.matrix):
    n = cost_matrix.shape[0]
    heapq.heapify(edge_list)
    parent = [-1]*n
    i = 0
    minCost = 0
    tree = np.full((cost_matrix.shape[0]-1,3),fill_value=[-1,-1,-1])
    while((i<n-1) and edge_list):
        edge=heapq.heappop(edge_list)
        j = find_parent(parent,edge.source)
        k = find_parent(parent,edge.destination)

        if(j!=k):
            tree[i]=edge.convertToList()
            minCost+=cost_matrix[edge.source,edge.destination]
            union(parent,edge)
            tree_plotter(cost_matrix,tree)
            i+=1
    if(i!=n-1):
        print("No MST")
        return -1
    else: return {'Cost':minCost,'Tree':tree}

if(__name__=="__main__"):
    n = int(input("Enter number of nodes: "))
    edge_list=create_edge_list(n)
    matrix=create_cost_matrix(n,edge_list)
    layout = nx.spring_layout(nx.from_numpy_array(matrix))
    graph_plotter(matrix)
    replace_with_maxsize(matrix)
    kruskal(edge_list,matrix)
    replace_with_zeroes(matrix)
    plt.show()