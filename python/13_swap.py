x=int(input("Enter first number: "))
y=int(input('Enter second number: '))

print()
def swap_using_assign(a,b):
    print(f"Numbers before swapping {a} and {b}")
    a,b=b,a
    print(f"Numbers after swapping {a} and {b} after using ','\n")

def swap_using_xor(a,b):
    print(f"Numbers before swapping {a} and {b}")
    xr=a^b
    a=a^xr
    b=b^xr
    print(f"Numbers after swapping {a} and {b} after using XOR method\n")

swap_using_assign(x,y)
swap_using_xor(x,y)

