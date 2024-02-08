import numpy as np

def hotEncode(arr:np.ndarray):
    
    hot = np.zeros((arr.size,arr.max()),int)

    for index,val in enumerate(arr):
        hot[index][val-1] = 1

    return hot

print(hotEncode(np.array([2, 3, 5, 2, 2, 1])))
