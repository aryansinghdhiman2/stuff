import termtables as tt
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

def draw(result:list[int]):
    board = [['']*(len(result)) for i in range(len(result))]
    for i in range(len(result)):
        board[i][result[i]]='♕'
    tt.print(board,style=tt.styles.thick)

def queens(k:int,n:int,result:list[int]):
    global count
    for i in range(0,n):
        if(canPlace(k,i,result)):
            result[k]=i
            if(k==n-1): 
                printResult(result)
                # draw(result)
                count+=1
            else: queens(k+1,n,result)

if(__name__=="__main__"):
    n=int(input('Enter Number of Queens: '))
    result=[0]*n
    queens(0,n,result)
    print(f'Number of solutions: {count}')