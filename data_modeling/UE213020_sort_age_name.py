import numpy as np

num = int(input("Enter number of tuples: "))

inp:list[tuple] = []

for i in range(num):
    row = input("Enter Pairs: ").split(',')
    row[1] = int(row[1])
    row[2] = int(row[2])
    inp.append(tuple(row))

nimp = np.array(inp,dtype="O,i,i")

print(np.sort(nimp))

# inp = [('Tom',19,80),
#         ('John',20,90),
#         ('Jony',17,91),
#         ('Jony',17,93),
#         ('Json',21,85)]