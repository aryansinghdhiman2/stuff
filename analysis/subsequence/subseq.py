def LongestCommonSubsquence(first:str,second:str):
    character = [([0]*len(second)) for i in range(len(first))]
    arrow = [(['↑']*len(second)) for i in range(len(first))]
    for i in range(1,len(first)):
        for j in range(1,len(second)):
            if(first[i]==second[j]):
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
        print(first[i])
    elif(arrow[i][j]=='↑'):
        printLCS(arrow,first,i-1,j)
    else: printLCS(arrow,first,i,j-1)

char,arrow=LongestCommonSubsquence('ABCBDAB','BDCABA')
printLCS(arrow,'ABCBDAB',len('ABCBDAB')-1,len('BDCABA')-1)