dice:dict[int,list] = dict()

for i in range(1,7):
    for j in range(1,7):
        new_tuple = (i,j)
        if i+j in dice:
            dice[i+j].append(new_tuple)
        else: dice[i+j] = [new_tuple]

for key,val in dice.items():
    print(f"Number of combinations that add upto {key} are {len(val)}")