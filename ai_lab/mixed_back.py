import networkx as nx
from matplotlib import pyplot as plt
import numpy as np
def drawgraph(graph:nx.Graph):
    layout = nx.spiral_layout(graph)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,node_color='blue',font_color='white')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels)
    plt.show()

visited = []
def dfs(graph:nx.Graph,index:str,goal:str):
    visited.append(index)
    if(index==goal):
        return
    for i in graph.neighbors(index):
        if(graph.edges[index,i]['weight']>=1 and i not in visited):
            dfs(graph,i,goal)

if(__name__=="__main__"):
    graph:nx.Graph = nx.from_numpy_array(np.array([[ 0,  6,  3,  1,  0,  0,  0,  0,  0,  0], 
                                [ 6,  0,  2,  6,  3,  4,  0,  0,  0,  0],
                                [ 3,  2,  0,  0,  4,  5,  0,  0,  0,  0],
                                [ 1,  6,  0,  0,  7,  8,  9,  0,  0,  0],
                                [ 0,  3,  4,  7,  0,  6,  9,  9,  0,  0],
                                [ 0,  4,  5,  8,  6,  0,  8,  9,  0,  0],
                                [ 0,  0,  0,  9,  9,  8,  0, 11, 12, 14],
                                [ 0,  0,  0,  0,  9,  9, 11,  0, 14, 15],
                                [ 0,  0,  0,  0,  0,  0, 12, 14,  0,  0],
                                [ 0,  0,  0,  0,  0,  0, 14, 15,  0,  0]]))

    # drawgraph(graph)
    
    dfs(graph,0,9)
    print(visited)