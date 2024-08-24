import numpy as np
import math

def generateWindows(array:np.ndarray,win_size:int,stride:int):
    window = np.zeros((int(math.ceil((array.size - win_size)/stride)) + 1,win_size),dtype=array.dtype)

    index = 0
    i = 0
    while i < window.shape[0]:

        if(index+win_size > array.size):
            window[i] = np.concatenate((array[index:array.size],np.zeros((index+win_size-array.size))))
        else:
            window[i] = array[index:index+win_size]
        i+=1
        index = index + stride

    return window

print(generateWindows(np.arange(15),7,3))