import numpy as np

class PittsBase:
    @classmethod
    def linear_threshold_gate(cls,dot: int, T: float) -> int:
        '''Returns the binary threshold output'''
        if dot >= T:
            return 1
        else:
            return 0
        
class PittsAND(PittsBase):
    T = 2
    weights = np.array([1,1])

    @classmethod
    def activate(cls,A : int, B : int) -> int:
        return cls.linear_threshold_gate([A,B] @ cls.weights,cls.T)
    
class PittsOR(PittsBase):
    T = 1
    weights = np.array([1,1])

    @classmethod
    def activate(cls,A : int, B : int) -> int:
        return cls.linear_threshold_gate([A,B] @ cls.weights,cls.T)
    
class PittsNOT(PittsBase):
    T = 0
    weights = np.array([-1])

    @classmethod
    def activate(cls,A : int) -> int:
        return cls.linear_threshold_gate([A] @ cls.weights,cls.T)
    
class PittsXOR(PittsBase):

    @classmethod
    def activate(cls, A : int, B : int) -> int:
        return  PittsOR.activate(
                    PittsAND.activate(
                        PittsNOT.activate(A),
                        B
                    )
                    ,
                    PittsAND.activate(
                        A,
                        PittsNOT.activate(B)
                    )
                )

def parity(number : int) -> int:

    bits = list(format(number,'b'))

    if(len(bits) < 4):
        bits = ['0'] * (4 - len(bits)) + bits
    
    bits = list(map(int,bits))

    # par = bits[0]
    # for i in range(1,len(bits)):
    #     par = PittsXOR.activate(par,bits[i])
    # return par

    return PittsXOR.activate(
                PittsXOR.activate(bits[0],bits[1]),
                PittsXOR.activate(bits[2],bits[3])
                )


if(__name__=="__main__"):
    for num in range(0,16):
        print(f"Parity of number {num} ( {bin(num)} ) is {parity(num)}")