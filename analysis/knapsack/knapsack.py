def knapsack(m,n,elementArray):
    solutionArray = [0]*n
    freeCapacity = m
    for i in range(0,n):
        if(elementArray[i]['weight']>freeCapacity):
            solutionArray[i]=freeCapacity/elementArray[i]['weight']
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

def solver(m,n,elementArray,sorter):
    elementArray.sort(key=sorter,reverse=True)
    solutionArray = knapsack(m,n,elementArray)
    print(solutionArray)
    totalProfit = 0
    for i in range(0,len(elementArray)):
        totalProfit+=solutionArray[i]*elementArray[i]['profit']
    print(totalProfit)
    return totalProfit


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
    
    print(30*'-')
    print("\nGreedy on ratio")
    solver(m,n,elementArray,sortbyratio)

    print(30*'-')
    print("\nGreedy on profit")
    solver(m,n,elementArray,sortbyprofit)

    print(30*'-')
    print("\nGreedy on weight")
    solver(m,n,elementArray,sortbyweight)
    # print(knapsack(m,n,elementArray))
    