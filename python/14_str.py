string=input("Enter a string: ")

lis=list(string)
lis.sort()
string=''.join(lis)

print(f"Your string sorted in alphabetical order is : {string}")