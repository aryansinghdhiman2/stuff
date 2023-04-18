def LongestCommonSubsquence(first:str,second:str):
    character = [([0]*(len(second)+1)) for i in range(len(first)+1)]
    arrow = [(['↑']*(len(second)+1)) for i in range(len(first)+1)]
    for i in range(1,len(character)):
        for j in range(1,len(character[i])):
            if(first[i-1]==second[j-1]):
                data=character[i-1][j-1]+1
                character[i][j]=data
                arrow[i][j]='↖'
            elif(character[i-1][j]>=character[i][j-1]):
                character[i][j]=character[i-1][j]
                arrow[i][j]='↑'
            else:
                character[i][j]=character[i][j-1]
                arrow[i][j]='←'
    return [character,arrow]

def printLCS(arrow:list[str],first,i,j):
    if(i==-1 or j==-1):
        return
    if(arrow[i][j]=='↖'):
        printLCS(arrow,first,i-1,j-1)
        print(first[i-1],end='')
    elif(arrow[i][j]=='↑'):
        printLCS(arrow,first,i-1,j)
    else: printLCS(arrow,first,i,j-1)

def getInput():
    first = str(input('Enter First String: '))
    second = str(input('Enter Second String: '))
    return first,second

if(__name__=='__main__'):
    first,second=getInput()
    char,arrow=LongestCommonSubsquence(first,second)
    print(f"Length of LCS is: {char[-1][-1]}")
    printLCS(arrow,first,len(first),len(second))
    print()




# def printMatrix(character:list[list:int],arrow:list[list:str]):
#     result =[]
#     for i in range(0,len(character)):
#         intermed = []
#         for j in range(0,len(character[i])):
#             intermed.append(str(character[i][j])+' '+arrow[i][j])
#         result.append(intermed)
#     import termtables
#     termtables.print(result)