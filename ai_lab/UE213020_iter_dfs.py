import networkx as nx
import numpy as np

visited = []

def getInput(n:int):
    graph = nx.Graph()
    graph.add_nodes_from(range(0,n))
    print('Get ready to enter edges: [Note that index of nodes starts from 0]')
    print("Enter Edges in order of source weight destination")
    while(True):
        cont = int(input('Enter 0 if you want to enter more edges else enter 1: '))
        if(cont):
            break
        source = int(input('Source: '))
        destination = int(input('Destination: '))

        if((source >= n or destination >= n) or (source==destination)):
            print("Invalid")
            continue

        if(graph.has_edge(source,destination)):
            print("Already Exists")
        else: graph.add_edge(source,destination)
    
    return graph


def dfs(adj_matrix:list[list[int]],index:int,depth:int) -> None:
    if(depth > 0):
        visited.append(index)
        for i in range(len(adj_matrix[index])):
            if(adj_matrix[index][i]==1 and i not in visited):
                dfs(adj_matrix,i,depth-1)


graph = nx.Graph()
graph.nodes(21)
graph.add_edge(0,1)
graph.add_edge(0,2)
graph.add_edge(0,3)
graph.add_edge(0,4)
graph.add_edge(1,5)
graph.add_edge(1,6)
graph.add_edge(1,7)
graph.add_edge(2,7)
graph.add_edge(2,8)
graph.add_edge(2,9)
graph.add_edge(3,9)
graph.add_edge(3,10)
graph.add_edge(3,11)
graph.add_edge(4,11)
graph.add_edge(5,12)
graph.add_edge(5,13)
graph.add_edge(5,14)
graph.add_edge(6,15)
graph.add_edge(6,7)
graph.add_edge(7,15)
graph.add_edge(7,16)
graph.add_edge(8,16)
graph.add_edge(8,17)
graph.add_edge(9,17)
graph.add_edge(9,18)
graph.add_edge(10,18)
graph.add_edge(11,19)
graph.add_edge(11,20)

adj_matrix = nx.to_numpy_array(graph)
dfs(adj_matrix.tolist(),0,4)

print(visited)