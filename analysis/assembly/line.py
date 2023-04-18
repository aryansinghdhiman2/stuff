def fastestWay(assemblyTime:list[list[int]],
               transistionTime:list[list[int]],
               entryTime:list[int],
               exitTime:list[int],
               numberOfStations:int):
    finish=[[],[]]
    decision=[[],[]]
    finish[0].append(entryTime[0]+assemblyTime[0][0])
    finish[1].append(entryTime[1]+assemblyTime[1][0])

    for j in range(1,numberOfStations):
        if(finish[0][j-1]+assemblyTime[0][j]<=finish[1][j-1]+transistionTime[1][j-1]+assemblyTime[0][j]):
            finish[0].append(finish[0][j-1]+assemblyTime[0][j])
            decision[0].append(0)
        else:
            finish[0].append(finish[1][j-1]+transistionTime[1][j-1]+assemblyTime[0][j])
            decision[0].append(1)
        if(finish[1][j-1]+assemblyTime[1][j]<=finish[0][j-1]+transistionTime[0][j-1]+assemblyTime[1][j]):
            finish[1].append(finish[1][j-1]+assemblyTime[1][j])
            decision[1].append(1)
        else:
            finish[1].append(finish[0][j-1]+transistionTime[0][j-1]+assemblyTime[1][j])
            decision[1].append(0)

    if(finish[0][numberOfStations-1]+exitTime[0]<=finish[1][numberOfStations-1]+exitTime[1]):
        finish[0].append(finish[0][numberOfStations-1]+exitTime[0])
        decision[0].append(0)
        finish[1].append(finish[0][numberOfStations-1]+exitTime[0])
        decision[1].append(0)
    else:
        finish[0].append(finish[1][numberOfStations-1]+exitTime[1])
        decision[0].append(1)
        finish[1].append(finish[1][numberOfStations-1]+exitTime[1])
        decision[1].append(1)
    return [finish,decision]

def printStations(decision:list[list[int]],finish:list[list[int]],numberOfStations:int):
    i = decision[0][-1]
    decision[0].pop()
    decision[1].pop()
    print(f"Line {i} Station {numberOfStations-1}")
    for j in range(numberOfStations-2,-1,-1):
        k=decision[i][j]
        i=k
        print(f"Line {i} Station {j}")
    print(f"Minimum time for job is: {finish[0][-1]}")


def getInput():
    numberOfStations = int(input('Enter Number of Stations: '))
    assemblyTime=[[],[]]
    transitionTime=[[],[]]
    assemblyTime[0]=list(map(int, input("Enter Assembly Time for Line 0: ").strip().split()))
    assemblyTime[1]=list(map(int, input("Enter Assembly Time for Line 1: ").strip().split()))
    transitionTime[0]=list(map(int, input("Enter Transition Time for Line 0: ").strip().split()))
    transitionTime[1]=list(map(int, input("Enter Transition Time for Line 1: ").strip().split()))
    entryTimeZero=int(input('Entry Time for Line 0: '))
    entryTimeOne=int(input('Entry Time for Line 1: '))
    entryTime=[entryTimeZero,entryTimeOne]
    exitTimeZero=int(input('Exit Time for Line 0: '))
    exitTimeOne=int(input('Exit Time for Line 1: '))
    exitTime=[exitTimeZero,exitTimeOne]
    return [assemblyTime,transitionTime,entryTime,exitTime,numberOfStations]

if(__name__=='__main__'):
    assemblyTime,transitionTime,entryTime,exitTime,numberOfStations=getInput()
    finish,decision=fastestWay(assemblyTime,transitionTime,entryTime,exitTime,numberOfStations)
    printStations(decision,finish,numberOfStations)


# a = [[7,9,3,4,8,4], [8,5,6,4,5,7]] 
# t = [[2,3,1,3,4], [2,1,2,2,1]]
# n = len(a[0])
# e1 = 2
# e2 = 4
# x1 = 3
# x2 = 2


# assemblyTime = [[7,9,3,4,8,4],[8,5,6,4,5,7]]
# transitionTime=[[2,3,1,3,4],[2,1,2,2,1]]
# entryTime = [2,4]
# exitTime = [3,2]
# numberOfStations=6

# finsh,decision=fastestWay(assemblyTime,transitionTime,entryTime,exitTime,numberOfStations)
# printStations(decision,numberOfStations)