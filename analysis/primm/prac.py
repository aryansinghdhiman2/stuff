import numpy as np
from sys import maxsize
def getNext(matrix:np.matrix,near:np.ndarray):
    minimum = maxsize
    coordinate = 0
    for i in range(0,matrix.shape[0]):
        if(near[i]!=-1):
            if(matrix[i,near[i]]<minimum):
                minimum=matrix[i,near[i]]
                coordinate=i
    return coordinate

def primm(matrix:np.matrix):
    l,k = np.unravel_index(matrix.argmin(),matrix.shape)
    minimumCost = matrix[l,k]

    tree=np.full((matrix.shape[0]-1,3),fill_value=[-1,-1,-1])
    tree[0]=[l,k,matrix[l,k]]

    near = np.full(matrix.shape,fill_value=-1)
    
    for i in range(0,matrix.shape[0]):
        if(matrix[i,l]<matrix[i,k]):
            near[i]=l
        else:
            near[i]=k
    near[l]=near[k]=-1

    for i in range(1,matrix.shape[0]-1):
        j = getNext(matrix,near)
        tree[i]=[j,near[j],matrix[j,near[j]]]
        near[j]=-1
        minimumCost+=matrix[j,near[j]]
        for k in range(0,near.shape):
            if((near[k]!=-1) and (matrix[k,j]<matrix[k,near[j]])):
                near[k]=j
    return minimumCost