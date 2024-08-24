num=int(input("Enter number upto which you want fibonacci series: "))

a=0
b=1
c=0
lis=[a,b]
while True:
    c=a+b
    if(c>num):
        break
    a=b
    b=c
    lis.append(c)

print(lis)