import numpy as np

def localMaxima(array:np.ndarray):
    mask = np.diff(np.sign(np.diff(array)))
    mask = np.argwhere(mask < 0) + 1
    return mask


print(localMaxima(np.array([1, 3, 7, 1, 2, 6, 0, 1])).flatten())