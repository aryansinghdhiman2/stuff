import networkx as nx
visited = []

def dfs(adj_matrix:list[list[int]],index:int,depth:int) -> None:
    if(depth > 0):
        visited.append(index)
        for i in range(len(adj_matrix[index])):
            if(adj_matrix[index][i]==1 and i not in visited):
                dfs(adj_matrix,i,depth-1)

if(__name__=="__main__"):
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
    source = int(input("Enter source vertex: "))

    for i in range(1,5):
        dfs(adj_matrix.tolist(),source,i)
        print(f"Iterative DFS for Depth = {i}: {visited}")
        visited.clear()