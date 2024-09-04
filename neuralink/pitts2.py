import numpy as np
from matplotlib import pyplot as plt

def linear_threshold_gate(dot: int, T: float) -> int:
    '''Returns the binary threshold output'''
    if dot >= T:
        return 1
    else:
        return 0
    
if(__name__ == "__main__"):
    print('—' * 65)
    print("Implementing OR gate using McCulloch-Pitts Artificial Neuron\n")
    input_table = np.array([
        [0,0], # both no
        [0,1], # one no, one yes
        [1,0], # one yes, one no
        [1,1]  # bot yes
    ])
    print(f'input table:\n{input_table}\n')

    weights = np.array([1,1])
    print(f'weights: {weights}\n')

    dot_products = input_table @ weights
    print(f'Dot products: {dot_products}\n')

    T = 1
    for i in range(0,4):
        activation = linear_threshold_gate(dot_products[i], T)
        print(f'Activation: {activation}')

    plt.plot([1,0],[0,1],"black",label="Decision Boundary")
    plt.legend()
    plt.plot(1,1,"go")
    plt.plot(1,0,"go")
    plt.plot(0,1,"go")
    plt.plot(0,0,"ro")
    plt.annotate("(0,0)",[0,0])
    plt.annotate("(1,0)",[1,0])
    plt.annotate("(0,1)",[0,1])
    plt.annotate("(1,1)",[1,1])
    axes = plt.gca()
    plt.show()

    print('—' * 65)
    print("Implementing NOR gate using McCulloch-Pitts Artificial Neuron\n")
    input_table = np.array([
        [0,0], # both no
        [0,1], # one no, one yes
        [1,0], # one yes, one no
        [1,1]  # bot yes
    ])
    print(f'input table:\n{input_table}\n')

    weights = np.array([-1,-1])
    print(f'weights: {weights}\n')

    dot_products = input_table @ weights
    print(f'Dot products: {dot_products}\n')

    T = 0
    for i in range(0,4):
        activation = linear_threshold_gate(dot_products[i], T)
        print(f'Activation: {activation}')

    plt.plot([-1,1],[1,-1],"black",label="Decision Boundary")
    plt.legend()
    plt.plot(1,1,"ro")
    plt.plot(1,0,"ro")
    plt.plot(0,1,"ro")
    plt.plot(0,0,"go")
    plt.annotate("(0,0)",[0,0])
    plt.annotate("(1,0)",[1,0])
    plt.annotate("(0,1)",[0,1])
    plt.annotate("(1,1)",[1,1])
    plt.xlim((-0.5, 1.05))
    plt.ylim((-0.5, 1.05))
    plt.show()

    print('—' * 65)
    print("Implementing NOT gate using McCulloch-Pitts Artificial Neuron\n")
    input_table = np.array([[0],[1]])
    print(f'input table:\n{input_table}\n')

    weights = np.array([-1])
    print(f'weights: {weights}\n')

    dot_products = input_table @ weights
    print(f'Dot products: {dot_products}\n')

    T = 0
    for i in range(0,2):
        activation = linear_threshold_gate(dot_products[i], T)
        print(f'Activation: {activation}')