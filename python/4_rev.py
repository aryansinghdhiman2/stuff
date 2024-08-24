inp=int(input("Enter number you want reversed: "))

li=[]
print("Reverse of the digits is : ",end='')
while inp>0:
    digit=inp%10
    inp=inp//10
    print(digit,end='')




