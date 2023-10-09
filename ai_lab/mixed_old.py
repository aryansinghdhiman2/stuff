import networkx as nx
from matplotlib import pyplot as plt
import heapq
from dataclasses import dataclass,field

@dataclass(order=True)
class Node:
    full_cost : int = field(init=False)
    path_cost : int
    index : str
    parent : str | None = field(default=None,compare=False)
    heuristic_cost :int | None = field(default=None,compare=False)

    def __post_init__(self):
        if(self.heuristic_cost is not None):
            self.full_cost = self.path_cost + self.heuristic_cost
        else:
            self.full_cost = None

    def __eq__(self, __value: "Node | str") -> bool:
        if(isinstance(__value,Node)):
            if(self.index == __value.index): return True
        if(isinstance(__value,str)):
            if(self.index == __value):return True
        return False

def dftAStar(graph:nx.Graph,node:Node,opened:list[Node],closed:list[Node]):
    for i in graph.neighbors(node.index):
        if(graph.edges[node.index,i]['weight']>=1):
            if(i in opened):
                child_node = opened.index(i)
                if(opened[child_node].path_cost > node.path_cost + graph.edges[node.index,i]['weight']):
                    opened[child_node].path_cost = node.path_cost + graph.edges[node.index,i]['weight']
                    opened[child_node].full_cost = opened[child_node].path_cost + opened[child_node].heuristic_cost
                    opened[child_node].parent = node.index
            elif(i in closed):
                child_node = closed.index(i)
                if(closed[child_node].path_cost > node.path_cost + graph.edges[node.index,i]['weight']):
                    closed[child_node].path_cost = node.path_cost + graph.edges[node.index,i]['weight']
                    closed[child_node].full_cost = closed[child_node].path_cost + closed[child_node].heuristic_cost
                    closed[child_node].parent = node.index
                    dftAStar(graph,closed[child_node],opened,closed)

def AStarSearch(graph:nx.Graph,index:str,goal:str,heuristic_costs:dict[str,int]) -> list[str]:
    opened :list[Node] = []
    closed :list[Node] = []
    start_node = Node(0,index,None,heuristic_costs[index])
    heapq.heappush(opened,start_node)
    found = False
    while(opened):
        if(found):break
        node = heapq.heappop(opened)
        closed.append(node)
        for neighbour in graph.neighbors(node.index):
            neighbour_node = Node(graph.edges[neighbour,node.index]['weight']+node.path_cost,neighbour,node.index,heuristic_costs[neighbour])
            if(neighbour_node in opened and opened[opened.index(neighbour)].full_cost > neighbour_node.full_cost):
                opened[opened.index(neighbour)].path_cost = neighbour_node.path_cost
                opened[opened.index(neighbour)].full_cost = neighbour_node.full_cost
                opened[opened.index(neighbour)].parent = neighbour_node.parent
                heapq.heapify(opened)
            elif(neighbour_node in closed and closed[closed.index(neighbour)].full_cost > neighbour_node.full_cost):
                closed[closed.index(neighbour)].path_cost = neighbour_node.path_cost
                closed[closed.index(neighbour)].full_cost = neighbour_node.full_cost
                closed[closed.index(neighbour)].parent = neighbour_node.parent
                dftAStar(graph,neighbour_node,opened,closed)
                heapq.heapify(opened)
            elif(neighbour_node not in opened and neighbour_node not in closed):
                heapq.heappush(opened,neighbour_node)
                if(neighbour_node.index==goal): 
                    found = True
                    closed.append(neighbour_node)
                    break
    path : list[str] = []
    i = len(closed)-1
    while(True):
        if(closed[i].index == None):break
        path.insert(0,closed[i].index)
        if(closed[i].parent == None):break
        i = closed.index(closed[i].parent)
    return path



visited = []

def bestfs(graph:nx.Graph,node:Node,goal:str):
    visited.append(node.index)
    if(node.index==goal):
        return
    neighbours = [Node(graph.edges[node.index,i]['weight']+node.path_cost,i) for i in graph.neighbors(node.index)]
    neighbours.sort()
    for neighbour in neighbours:
        if(neighbour.index not in visited):
            bestfs(graph,neighbour,goal)

def dfs(graph:nx.Graph,index:str,goal:str):
    visited.append(index)
    if(index==goal):
        return
    for i in graph.neighbors(index):
        if(graph.edges[index,i]['weight']>=1 and i not in visited):
            dfs(graph,i,goal)

def bfs(graph:nx.Graph,index:str,goal:str):
    queue = [index]

    while(queue):
        curr_index = queue[0]
        for i in graph.neighbors(curr_index):
            if(graph.edges[curr_index,i]['weight']>=1 and i not in visited and i not in queue):
                queue.append(i)
        visited.append(queue.pop(0))
        if(visited[-1]==goal):break

def dfs_iter(graph:nx.Graph,node:Node,goal:str,depth:int) -> None:
    if(depth > 0):
        visited.append(node.index)
        if(node.index==goal):
            return
        neighbours = [Node(graph.edges[node.index,i]['weight'],i) for i in graph.neighbors(node.index)]
        neighbours.sort()
        for neighbour in neighbours:
            if(neighbour.index not in visited):
                dfs_iter(graph,neighbour,goal,depth-1)

def level_beam(graph:nx.Graph,start:str,goal:str,width:int = 2):
    queue = [start]
    secondary_queue = []
    visited = []
    j = 0
    while(queue):
        neighbours = [Node(graph.edges[queue[0],i]['weight'],i) for i in graph.neighbors(queue[0])]
        neighbours.sort()
        for neighbour in neighbours:
            
            if j == width : break
            if neighbour.index in visited or neighbour.index in queue or neighbour.index in secondary_queue: continue

            secondary_queue.append(neighbour.index)
            j+=1
        
        visited.append(queue[0])
        if(visited[-1] == goal):break
        queue.pop(0)
        if(not queue): 
            queue = secondary_queue.copy()
            secondary_queue.clear()
            j = 0
        
    return visited

def node_beam(graph:nx.Graph,start:str,goal:str,width:int = 2):
    queue = [start]
    visited = []
    
    while(queue):
        j = 0
        neighbours = [Node(graph.edges[queue[0],i]['weight'],i) for i in graph.neighbors(queue[0])]
        neighbours.sort()
        for neighbour in neighbours:
            
            if j == width : break
            if neighbour.index in visited or neighbour.index in queue: continue
            
            queue.append(neighbour.index)
            j+=1
        
        visited.append(queue[0])
        if(visited[-1] == goal):break
        queue.pop(0)
    return visited

def drawgraph(graph:nx.Graph):
    layout = nx.circular_layout(graph)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw(graph,pos=layout,with_labels=True,node_color='blue',font_color='white')
    nx.draw_networkx_edge_labels(graph,pos=layout,edge_labels=labels,rotate=False)
    plt.show()

if(__name__=="__main__"):
    graph = nx.Graph()
    graph.add_node('A')
    graph.add_node('B')
    graph.add_node('C')
    graph.add_node('D')
    graph.add_node('E')
    graph.add_node('F')
    graph.add_node('G')
    graph.add_node('H')
    graph.add_node('I')
    graph.add_node('J')

    graph.add_edge('A','B',weight=6)
    graph.add_edge('A','C',weight=3)
    graph.add_edge('A','D',weight=1)
    graph.add_edge('B','C',weight=2)
    graph.add_edge('B','D',weight=6)
    graph.add_edge('B','E',weight=3)
    graph.add_edge('B','F',weight=4)
    graph.add_edge('C','E',weight=4)
    graph.add_edge('C','F',weight=5)
    graph.add_edge('D','E',weight=7)
    graph.add_edge('D','F',weight=8)
    graph.add_edge('D','G',weight=9)
    graph.add_edge('E','F',weight=6)
    graph.add_edge('A','B',weight=6)
    graph.add_edge('E','G',weight=9)
    graph.add_edge('E','H',weight=9)
    graph.add_edge('F','G',weight=8)
    graph.add_edge('F','H',weight=9)
    graph.add_edge('G','H',weight=11)
    graph.add_edge('G','I',weight=12)
    graph.add_edge('G','J',weight=14)
    graph.add_edge('H','I',weight=14)
    graph.add_edge('H','J',weight=15)

    heuristic_costs: dict[str,int] = {
        'A':15,
        'B':13,
        'C':13,
        'D':12,
        'E':10,
        'F':9,
        'G':7,
        'H':6,
        'I':5,
        'J':0
    }
    dfs(graph,'A','J')
    print(f"Depth First Search from A: {visited}")
    visited.clear()
    bestfs(graph,Node(0,'A'),'J')
    print(f"Best First Search from A: {visited}")
    visited.clear()
    for i in range(1,5):
        dfs_iter(graph,Node(0,'A'),'J',i)
        print(f"Iterative DFS from A for Depth = {i}: {visited}")
        visited.clear()
    visited.clear()
    bfs(graph,'A','J')
    print(f"Breadth First Search from A : {visited}")
    print(f"Beam Search with Level Width = 2 from A:{level_beam(graph,'A','J')}")
    print(f"Beam Search with Node Width = 2 from A:{node_beam(graph,'A','J')}")
    print(f"A* Search from A: {AStarSearch(graph,'A','J',heuristic_costs)}")
    drawgraph(graph)