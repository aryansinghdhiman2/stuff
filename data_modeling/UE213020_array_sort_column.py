import numpy as np

array = np.random.randint(0,10,(5,5))


def sortByColumn(array:np.ndarray):
    return np.sort(array,0)

print(f"Original array is \n{array}")
print(f"Sorted Array is \n{sortByColumn(array)}")