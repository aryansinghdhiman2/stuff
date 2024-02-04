num = int(input("Enter number of lists: "))
inp = []
for i in range(num):
    inp_list = [int(i) for i in input(f"Enter list {i+1}: ").split(",")]
    inp.append(inp_list)

sum_list = []

for l in inp:
    sum_list.append(sum(l))

print(f"List with max value is {inp[sum_list.index(max(sum_list))]}")