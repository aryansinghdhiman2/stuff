num=int(input("Enter number for which you want factorial: "))
fac=1
for i in range(1,num+1):
    fac*=i

print(f"Factorial of the number is {fac}")