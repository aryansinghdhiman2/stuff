import termtables as tt

def knapsack(m,n,elementArray):
    solutionArray = [0]*n
    freeCapacity = m
    for i in range(0,n):
        if(elementArray[i]['weight']>freeCapacity):
            solutionArray[i]=(freeCapacity/elementArray[i]['weight'])
            break
        else:
            solutionArray[i]=1
            freeCapacity -= elementArray[i]['weight']

    return solutionArray

def sortbyratio(element):
        return element['profit']/element['weight']

def sortbyprofit(element):
    return element['profit']

def sortbyweight(element):
    return element['weight']

def rearrange_solution(solutionArray,elementArray,copyArray):
    tempArray = solutionArray.copy()
    for i in range(0,len(elementArray)):
        for j in range(0,len(copyArray)):
            if(elementArray[i]['profit']==copyArray[j]['profit'] and elementArray[i]['weight']==copyArray[j]['weight']):
                tempArray[i]=solutionArray[j]
                break
    return tempArray

def solution_printer(elementArray,ratioSolution,weightSolution,profitSolution):
    profitArray= []
    for i in range(0,len(elementArray)):
        profitArray.append(elementArray[i]['profit'])
    weightArray= []
    for i in range(0,len(elementArray)):
        weightArray.append(elementArray[i]['weight'])
    ratioArray = []
    for i in range(0,len(elementArray)):
        ratioArray.append(round(sortbyratio(elementArray[i]),4))
    
    ratioProfit=0
    for i in range(0,len(elementArray)):
        ratioProfit+=ratioSolution[i]*elementArray[i]['profit']
    weightProfit=0
    for i in range(0,len(elementArray)):
        weightProfit+=weightSolution[i]*elementArray[i]['profit']
    profitProfit=0
    for i in range(0,len(elementArray)):
        profitProfit+=profitSolution[i]*elementArray[i]['profit']
    
    for i in range(0,len(ratioSolution)):
        ratioSolution[i]=round(ratioSolution[i],4)
        weightSolution[i]=round(weightSolution[i],4)
        profitSolution[i]=round(profitSolution[i],4)

    tableString = tt.to_string([['Profit Array',*profitArray],
                                ['Weight Array',*weightArray],
                                ['Ratio Array',*ratioArray],
                                ['Solution by greedy on Ratio',*ratioSolution],
                                ['Solution by greedy on Weight',*weightSolution],
                                ['Solution by greedy on Profit',*profitSolution]])
    print(tableString)

    print(f"Total Profit by Ratio is: {round(ratioProfit,4)}")
    print(f"Total Profit by Weight is: {round(weightProfit,4)}")
    print(f"Total Profit by Profit is: {round(profitProfit,4)}")

def solver(m,n,elementArray,sorter):
    copyArray=elementArray.copy()
    copyArray.sort(key=sorter,reverse=True)
    solutionArray = knapsack(m,n,copyArray)
    solutionArray=rearrange_solution(solutionArray,elementArray,copyArray)
    return solutionArray


if(__name__=='__main__'):
    m = 0
    n = 0
    elementArray = []

    m = int(input("Enter Capacity of Knapsack: "))
    n = int(input("Enter Number of Objects: "))
    print(30*'-')
    for i in range(0,n):
        temp = int(input(f"Enter Profit for Element Number {i}:"))
        temp2 = int(input(f"Enter Weight for Element Number {i}:"))
        elementArray.append({
            'profit':temp,
            'weight':temp2
        })
        print(30*'-')
    
    ratioSolution=solver(m,n,elementArray,sortbyratio)
    weightSolution=solver(m,n,elementArray,sortbyweight)
    profitSolution=solver(m,n,elementArray,sortbyprofit)
    solution_printer(elementArray,ratioSolution,weightSolution,profitSolution)