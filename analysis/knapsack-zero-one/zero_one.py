import termtables
def knapsack(profitArray:list[int],weightArray:list[int],numberOfObjects:int,capacityOfKnapsack:int):
    decisionTable = [[0]*(capacityOfKnapsack+1) for i in range(0,numberOfObjects+1)]
    for i in range(1,numberOfObjects+1):
        for j in range(1,capacityOfKnapsack+1):
            if weightArray[i] <= j:
                decisionTable[i][j] = max(decisionTable[i-1][j - weightArray[i]] + profitArray[i],decisionTable[i-1][j])
            else:
                decisionTable[i][j] = decisionTable[i-1][j]
    return decisionTable

def printResult(decisionTable:list[list[int]],weightArray:list[int],numberOfObjects:int,capacityOfKnapsack:int):
    i = numberOfObjects
    j = capacityOfKnapsack
    resultArray = [0]*numberOfObjects
    while( i>0 and j>=0):
        if decisionTable[i][j] == decisionTable[i-1][j]:
            i= i-1
        else:
            resultArray[i-1]=1
            j = j-weightArray[i]
            i = i-1
    header = ['X'+str(k+1) for k in range(0,numberOfObjects)]
    resultArray=[[header],[resultArray]]
    # termtables.print(decisionTable,style=termtables.styles.rounded)
    termtables.print(resultArray)
    print(f"Maximum Profit is: {decisionTable[-1][-1]}")

def getInput():
    numberOfObjects = int(input('Enter Number of Objects: '))
    capacityOfKnapsack = int(input('Enter Capacity of Knapsack: '))
    pArray = list(map(int,input('Enter Profit Array: ').strip().split()))
    wArray = list(map(int,input('Enter Weight Array: ').strip().split()))
    profitArray = [0]+pArray
    weightArray = [0]+wArray
    return [profitArray,weightArray,numberOfObjects,capacityOfKnapsack]

if(__name__=='__main__'):
    inputInfo=getInput()
    decisionTable=knapsack(*inputInfo)
    printResult(decisionTable,inputInfo[1],inputInfo[2],inputInfo[3])