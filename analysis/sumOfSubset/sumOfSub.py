global count
count=0
def sumOfSubset(k:int,
                currentSum:int,
                remainingSum:int,
                decision:list[int],
                weight:list[int],
                target:int):
    decision[k]=1
    if(currentSum+weight[k]==target):
        global count
        count+=1
        print(decision[0:k+1])
    
    elif(currentSum+weight[k]+weight[k+1]<=target):
        sumOfSubset(k+1,
                    currentSum+weight[k],
                    remainingSum-weight[k],
                    decision,
                    weight,
                    target)
    if((currentSum+remainingSum-weight[k]>=target) and (currentSum+weight[k+1]<=target)):
        decision[k]=0
        sumOfSubset(k+1,
                    currentSum,
                    remainingSum-weight[k],
                    decision,
                    weight,
                    target)

if(__name__=='__main__'):
    weight=list(map(int,input("Enter Number Array: ").strip().split()))
    target=int(input("Enter Sum Target: "))
    decision = [0]*len(weight)
    remainingSum=0
    for w in weight:
        remainingSum+=w
    sumOfSubset(0,0,remainingSum,decision,weight,target)
    print(f"Number of Subsets are: {count}")
    # n=6
    # weight=[5,10,12,13,15,18]
    # target=30
    # decision=[0]*n
    # currentSum=0
    # remainingSum = 0
    # for w in weight:
    #     remainingSum+=w
    
    # sumOfSubset(0,currentSum,remainingSum,decision,weight,target)
    # n = int(input("Enter Number of Integers: "))