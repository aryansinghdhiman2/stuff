import numpy as np
from matplotlib import cm, pyplot as plt
from matplotlib.colors import ListedColormap

class Neuron:
    # weight = np.array([
    #     [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    #     [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 1, 0, 0, 0, 0]
    # ])
    weight = np.array([
        [ 1,  1,  1,  1, 1, 1,  1,  1,  1,  1],
        [ 1,  1,  1,  1, 1, 1,  1,  1,  1,  1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1],
        [-1, -1, -1, -1, 1, 1, -1, -1, -1, -1]
    ])
    T = 30

    @classmethod
    def linear_threshold_gate(cls,dot: int) -> int:
        '''Returns the binary threshold output'''
        if dot >= cls.T:
            return 1
        else:
            return 0
        
    @classmethod
    def activate(cls,inp : np.ndarray) -> int:
        return cls.linear_threshold_gate(np.sum(cls.weight * inp))


def showT():
    cmap = ListedColormap(["white","black"])
    plt.title("The Letter T")
    plt.imshow(Neuron.weight,cmap=cmap)
    plt.show()

def showResult(input : np.ndarray):
    cmap : ListedColormap = None
    if(Neuron.activate(input) == 1):
        plt.title("Input resembles letter T")
        cmap = ListedColormap(["white","black"])
    else: 
        plt.title("Input does not resemble T")
        cmap = ListedColormap(["white","red"])

    plt.imshow(input,cmap=cmap)
    plt.show()

if(__name__ == "__main__"):

    showT()

    inp1 = np.array([
        [1, 1, 0, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 0, 1, 1, 0, 1],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0]
    ])

    showResult(inp1)

    inp2 = np.array([
        [1, 0, 1, 1, 0, 1, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 0, 0, 1, 1],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0]
    ])

    showResult(inp2)

    inp3 = np.array([
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    ])

    showResult(inp3)
    
    inp4 = np.array([
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    ])

    showResult(inp4)