global count
count=0
def canPlace(k:int,i:int,result:list[int]):
    for j in range(0,k):
        if(result[j]==i or abs(result[j]-i)==abs(j-k)):
            return False
    return True

def printResult(result:list[int]):
    temp = result.copy()
    for i in range(0,len(temp)):
        temp[i]+=1
    print(temp)

def queens(k:int,n:int,result:list[int]):
    global count
    for i in range(0,n):
        if(canPlace(k,i,result)):
            result[k]=i
            if(k==n-1): 
                printResult(result)
                count+=1
            else: queens(k+1,n,result)

n=int(input('Enter Number of Queens: '))
k=0
result=[0]*n
queens(k,n,result)
print(f'Number of solutions: {count}')