def LongestCommonSubsquence(first:str,second:str):
    
    character = [([0]*len(first))]*len(second)
    arrow = [([0]*len(first))]*len(second)
    for i in range(0,len(first)):
        for j in range(0,len(second)):
            if(first[i]==second[i]):
                character[i][j]=character[i-1][j-1]+1
    pass