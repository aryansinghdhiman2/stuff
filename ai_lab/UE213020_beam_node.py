import networkx as nx
import numpy as np

def node_beam(graph:nx.Graph,width:int):
    queue = [0]
    visited = []
    
    while(queue):
        j = 0
        for i in graph.neighbors(queue[0]):
            
            if j == width : break
            if i in visited or i in queue: continue
            
            queue.append(i)
            j+=1
        
        visited.append(queue[0])
        queue.pop(0)
    return visited

if(__name__=="__main__"):
    adj_matrix = np.matrix([[0, 1, 1, 0, 0, 1, 0, 0, 0, 0], 
                            [1, 0, 1, 1, 0, 0, 0, 0, 0, 0], 
                            [1, 1, 0, 0, 1, 0, 0, 1, 0, 0], 
                            [0, 1, 0, 0, 1, 0, 1, 0, 1, 0], 
                            [0, 0, 1, 1, 0, 1, 1, 0, 0, 0], 
                            [1, 0, 0, 0, 1, 0, 0, 0, 0, 1], 
                            [0, 0, 0, 1, 1, 0, 0, 1, 0, 0], 
                            [0, 0, 1, 0, 0, 0, 1, 0, 0, 0], 
                            [0, 0, 0, 1, 0, 0, 0, 0, 0, 1], 
                            [0, 0, 0, 0, 0, 1, 0, 0, 1, 0]])

    # adj_matrix = np.matrix([[0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], 
    #                         [1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0], 
    #                         [0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0], 
    #                         [0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
    #                         [0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0], 
    #                         [0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
    #                         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
    #                         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0], 
    #                         [1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1], 
    #                         [0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0], 
    #                         [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1], 
    #                         [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0]])

    graph = nx.from_numpy_array(adj_matrix)
    print(node_beam(graph,1))
    print(node_beam(graph,2))
    print(node_beam(graph,3))