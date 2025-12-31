import numpy as np

class Neuron:
    weight = np.array([1,1,1])
    
    def __init__(self) -> None:
        self.carry = 0

    def activate(self, inp:np.ndarray) -> int:
        inp = np.append(inp,self.carry)
        self.carry = 0

        match np.sum(inp * self.weight):
            case 0:
                return 0
            case 1:
                return 1
            case 2:
                self.carry = 1
                return 0
            case 3:
                self.carry = 1
                return 1
    
    def hasCarry(self) -> bool:
        return self.carry == 1

if(__name__=="__main__"):
    num1 = int(input("Enter Number 1: "))
    num2 = int(input("Enter Number 2: "))

    num1 = [int(i) for i in list(bin(num1)[2:])]
    num2 = [int(i) for i in list(bin(num2)[2:])]

    if(len(num1)<len(num2)):
        num1 = [0] * (len(num2)-len(num1)) + num1
    elif(len(num2)<len(num1)):
        num2 = [0] * (len(num1)-len(num2)) + num2
    
    neuron = Neuron()
    output = []
    for i,_ in reversed(list(enumerate(num1))):
        output = [neuron.activate(np.array([num1[i],num2[i]]))] + output
    if(neuron.hasCarry()):
        output = [1] + output

    output = [str(i) for i in output]
    
    answer = int("".join(output),2)

    print(f"The sum is {answer}")




        