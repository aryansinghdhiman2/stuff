is_prime=True

for i in range(2,101):
    for k in range(2,i):
        if((i%k)==0):
            is_prime=False
            break
    if is_prime:
        print(i,end=' ')
    is_prime=True