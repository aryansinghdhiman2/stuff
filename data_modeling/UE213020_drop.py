import numpy as np

def drop(array:np.ndarray):
    return array[~np.isnan(array)]
    
array = np.array([1,2,3,np.nan,5,6,7,np.nan])

array = drop(array)

print(array)