import numpy as np

def linear_threshold_gate(dot: int, T: float) -> int:
    '''Returns the binary threshold output'''
    if dot >= T:
        return 1
    else:
        return 0
    
if(__name__ == "__main__"):

    print("Implementing McCulloch-Pitts Artificial Neuron")
    np.random.seed(seed=0)
    I = np.random.choice([0,1], 3)# generate random vector I, sampling from {0,1}
    W = np.random.choice([-1,1], 3) # generate random vector W, sampling from {-1,1} 
    print(f'Input vector:{I}, Weight vector:{W}')

    dot = I @ W
    print(f'Dot product: {dot}')

    T = 1
    activation = linear_threshold_gate(dot, T)
    print(f'Activation when T=1: {activation}')

    T = 3
    activation = linear_threshold_gate(dot, T)
    print(f'Activation when T=3: {activation}')

    print("\pitn"+35*"—")
    print("Implementing AND gate using McCulloch-Pitts Artificial Neuron")
    input_table = np.array([
        [0,0], # both no
        [0,1], # one no, one yes
        [1,0], # one yes, one no
        [1,1]  # bot yes
    ])
    print(f'input table:\n{input_table}')

    weights = np.array([1,1])
    print(f'weights: {weights}')

    dot_products = input_table @ weights
    print(f'Dot products: {dot_products}')

    T = 2
    for i in range(0,4):
        activation = linear_threshold_gate(dot_products[i], T)
        print(f'Activation: {activation}')
