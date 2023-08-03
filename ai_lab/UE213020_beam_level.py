import networkx as nx
import numpy as np

def in_upper_level(node:int,current_level:int,levels:dict[int:list[int]]):
    for k,v in levels.items():
        if(node in v and k <= current_level):
            return True
    return False

def level_beam(graph:nx.Graph,width:int,levels:dict[int:list[int]]):
    queue = [0]
    secondary_queue = []
    visited = []
    current_level = 0
    j = 0
    while(queue):
        for i in graph.neighbors(queue[0]):
            
            if j == width : break
            if i in visited or i in queue or i in secondary_queue: continue
            if in_upper_level(i,current_level,levels): continue

            secondary_queue.append(i)
            j+=1
        
        visited.append(queue[0])
        queue.pop(0)
        if(not queue): 
            queue = secondary_queue.copy()
            secondary_queue.clear()
            current_level+=1
            j = 0
        
    return visited

if(__name__=="__main__"):
    # adj_matrix = np.matrix([[0, 1, 1, 0, 0, 1, 0, 0, 0, 0], 
    #                         [1, 0, 1, 1, 0, 0, 0, 0, 0, 0], 
    #                         [1, 1, 0, 0, 1, 0, 0, 1, 0, 0], 
    #                         [0, 1, 0, 0, 1, 0, 1, 0, 1, 0], 
    #                         [0, 0, 1, 1, 0, 1, 1, 0, 0, 0], 
    #                         [1, 0, 0, 0, 1, 0, 0, 0, 0, 1], 
    #                         [0, 0, 0, 1, 1, 0, 0, 1, 0, 0], 
    #                         [0, 0, 1, 0, 0, 0, 1, 0, 0, 0], 
    #                         [0, 0, 0, 1, 0, 0, 0, 0, 0, 1], 
    #                         [0, 0, 0, 0, 0, 1, 0, 0, 1, 0]])

    adj_matrix = np.matrix([[0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], 
                        [1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0], 
                        [0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0], 
                        [0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
                        [0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0], 
                        [0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0], 
                        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
                        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0], 
                        [1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1], 
                        [0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0], 
                        [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1], 
                        [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0]])

    graph = nx.from_numpy_array(adj_matrix)
    a = nx.single_source_dijkstra_path_length(graph,0)
    levels = dict()
    for k,v in a.items():
        if v not in levels.keys():
            levels[v]=[k]
        else: levels[v].append(k)
    
    print(level_beam(graph,1,levels))
    print(level_beam(graph,2,levels))
    print(level_beam(graph,3,levels))
