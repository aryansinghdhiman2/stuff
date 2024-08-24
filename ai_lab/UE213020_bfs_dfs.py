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

def bfs(adj_matrix:list[list[int]],start_index:int) -> list[int]:
    queue = [start_index]

    while(queue):
        curr_index = queue[0]
        for i in range(len(adj_matrix[curr_index])):
            if(adj_matrix[curr_index][i]==1 and i not in visited and i not in queue):
                queue.append(i)
        visited.append(queue.pop(0))

def dfs(adj_matrix:list[list[int]],index:int):
    visited.append(index)
    for i in range(len(adj_matrix[index])):
        if(adj_matrix[index][i]==1 and i not in visited):
            dfs(adj_matrix,i)

if(__name__=="__main__"):
    # n = int(input("Enter number of nodes: "))
    # graph = getInput(n)

    # adj_matrix = nx.to_numpy_array(graph,dtype=np.int64,nonedge=0)

    # start_index = int(input("Enter start index: "))

    # choice = int(input("Enter 0 for BFS, 1 for DFS: "))

    graph = nx.Graph()
    graph.add_nodes_from(range(0,10))
    graph.add_edge(0,1)
    graph.add_edge(0,2)
    graph.add_edge(1,3)
    graph.add_edge(1,4)
    graph.add_edge(2,5)
    graph.add_edge(4,6)
    graph.add_edge(5,6)
    graph.add_edge(5,7)
    graph.add_edge(6,8)
    graph.add_edge(7,8)
    graph.add_edge(7,9)
    start_index = 0

    adj_matrix = nx.to_numpy_array(graph,dtype=np.int64,nonedge=0)
    bfs(adj_matrix.tolist(),start_index)
    print(visited)
    visited.clear()
    dfs(adj_matrix.tolist(),start_index)
    print(visited)

        # graph = nx.Graph()
    # graph.add_nodes_from(range(0,9))
    # graph.add_edge(0,1)
    # graph.add_edge(0,2)
    # graph.add_edge(1,2)
    # graph.add_edge(2,5)
    # graph.add_edge(1,3)
    # graph.add_edge(3,4)
    # graph.add_edge(4,6)
    # graph.add_edge(4,5)
    # graph.add_edge(6,7)
    # graph.add_edge(7,5)
    # graph.add_edge(5,8)