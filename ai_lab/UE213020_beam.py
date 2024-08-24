import networkx as nx
import numpy as np

def level_beam(graph:nx.Graph,width:int):
    queue = [0]
    secondary_queue = []
    visited = []
    j = 0
    while(queue):
        for i in graph.neighbors(queue[0]):
            
            if j == width : break
            if i in visited or i in queue or i in secondary_queue: continue

            secondary_queue.append(i)
            j+=1
        
        visited.append(queue[0])
        queue.pop(0)
        if(not queue): 
            queue = secondary_queue.copy()
            secondary_queue.clear()
            j = 0
        
    return visited

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
    test_case_1 = np.matrix([[0, 1, 1, 0, 0, 1, 0, 0, 0, 0], 
                            [1, 0, 1, 1, 0, 0, 0, 0, 0, 0], 
                            [1, 1, 0, 0, 1, 0, 0, 1, 0, 0], 
                            [0, 1, 0, 0, 1, 0, 1, 0, 1, 0], 
                            [0, 0, 1, 1, 0, 1, 1, 0, 0, 0], 
                            [1, 0, 0, 0, 1, 0, 0, 0, 0, 1], 
                            [0, 0, 0, 1, 1, 0, 0, 1, 0, 0], 
                            [0, 0, 1, 0, 0, 0, 1, 0, 0, 0], 
                            [0, 0, 0, 1, 0, 0, 0, 0, 0, 1], 
                            [0, 0, 0, 0, 0, 1, 0, 0, 1, 0]])

    test_case_2 = np.matrix([[0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], 
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
    
    graph = nx.from_numpy_array(test_case_2)

    test_case_choice = int(input("Select Test Case (1 or 2): "))
    test_case = test_case_1
    if(test_case_choice == 1):
        test_case = test_case_1
    elif(test_case_choice == 2):
        test_case = test_case_2
    else:
        print("Invalid Choice")
        exit(1)

    print()
    print("Enter 1 for Beam Search with Level Width")
    print("Enter 2 for Beam Search with Node Width")
    
    algo_choice = int(input("Enter your choice: "))
    algo = level_beam
    if(algo_choice == 1):
        algo = level_beam
    elif(algo_choice == 2):
        algo = node_beam
    else:
        print("Invalid Choice")
        exit(1)

    width = int(input("\nEnter Width: "))

    graph = nx.from_numpy_array(test_case)

    print(f"Path taken: {algo(graph,width)}")