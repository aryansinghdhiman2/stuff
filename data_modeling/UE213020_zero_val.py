import numpy as np

def hasZeroVals(arr:np.ndarray) -> bool:
    z = np.zeros(arr.shape)
    if True in (arr == z): return True
    else: return False


if(__name__ == "__main__"):
    num = int(input("Enter Number of Rows: "))
    inp = []
    for i in range(num):
        inp.append([int(j) for j in input("Enter Row: ").split(',')])
    if hasZeroVals(np.array(inp)):
        print("Contains Zero Values")
    else: print("Does not contain zero values") 