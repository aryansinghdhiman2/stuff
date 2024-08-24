lis=[1,2,34,5,43,18,7]
print(lis)

rem=int(input('Enter Number which you want removed from the list:'))
print('Deleting using remove() method')
lis.remove(rem)
print(lis)

rem=int(input('Enter Number which you want removed from the list: '))
print("Removing using pop() and index() method")
pos=lis.index(rem)
lis.pop(pos)
print(lis)

print("Deleting entire list")
lis.clear()
print(lis)
