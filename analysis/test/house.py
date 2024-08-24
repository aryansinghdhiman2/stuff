import networkx as nx
from sys import maxsize
import numpy as np


def getInput():
    correctInput=False
    while(not correctInput):
        n =int(input('Enter number of intersections: '))
        if(n<=0 or n>20):
            print("Invalid, Enter Again")
        else: correctInput=True
    print(f'House no.s start from 0 to {n-1}')
    global newmaxsize
    newmaxsize=maxsize/n-1
    graph = nx.Graph()
    graph.add_nodes_from([i for i in range(0,n)])
    # graph = nx.Graph()
    while(True):
        i=int(input('Enter 0 if you want to continue else enter 1: '))
        if(i): break
        src, dest, weight = list(map(int, input('Enter: ').split()))
        if(src>=n or src<0 or dest>=n or dest<0 or weight>200 or weight<0):
            print('Invalid Input')
            continue
        graph.add_edge(src,dest,weight=weight)
    return graph

def warshall(cost:np.matrix):
    allCost = cost.copy()
    for k in range(0,allCost.shape[0]):
        for i in range(0,allCost.shape[0]):
            for j in range(0,allCost.shape[1]):
                if(allCost[i,j]>allCost[i,k]+allCost[k,j]):
                    allCost[i,j]=allCost[i,k]+allCost[k,j]
    return allCost

def process(allCost:np.matrix):
    averages=[0]*allCost.shape[0]
    for i in range(0,allCost.shape[0]):
        for j in range(0,allCost.shape[1]):
            # if(allCost[i,j]>=newmaxsize):
            #     continue
            averages[i]+=allCost[i,j]
        averages[i]=averages[i]/allCost.shape[1]
    mini=newmaxsize
    vertex=0
    i=0
    while(i<len(averages)):
        if(mini>averages[i]):
            mini=averages[vertex]
            vertex=i
        i+=1
    return [vertex,averages[vertex]]

if(__name__=='__main__'):
    graph=getInput()
    matrix=nx.to_numpy_array(graph,nonedge=newmaxsize,dtype=np.int64)
    for i in range(0,matrix.shape[0]):
        matrix[i,i]=0
    allCost=warshall(matrix)
    vertex,avgDistance=process(allCost)
    print(f'Pump should be placed at {vertex}: ')
    print(f'Average distance from {vertex} is: {avgDistance}')

# src = int(input('Enter source house: '))
# dest = int(input('Enter destination house: '))
# weight = int(input('Enter distance between houses: '))