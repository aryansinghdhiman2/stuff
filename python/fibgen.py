def fib_gen(num):
    a=0
    b=1
    for i in range(0,num+1):
        yield a
        c=a
        a=b
        b+=c

class FibGen():
    current=a=0
    b=1
    def __init__(self,num):
        self.num=num
    def __iter__(self):
        return self
    def __next__(self):
        if(self.current==0):
            self.current+=1
            return 0
        elif(self.current==1):
            self.current+=1
            return 1
        elif(self.current<=self.num):
            c=self.a+self.b
            self.a,self.b=self.b,c
            self.current+=1
            return c
        raise StopIteration


gen=FibGen(20)
gen_2=fib_gen(20)

for i in gen:
    print(i,end=' ')

print()
for i in gen_2:
    print(i,end=' ')
