def activity(start:list[int],finish:list[int],index:int):
    m=index+1
    while(m<len(start) and start[m]<finish[index]):
        m+=1
    if(m<len(start)):
        return [m]+activity(start,finish,m)
    else: return []
    
def createLists():
    start=[0]
    finish=[0]

    n=int(input("Enter number of activities: "))
    for i in range(0,n):
        print(f'Enter Activity {i}: ')
        s = int(input('Enter Start Time: '))
        f = int(input('Enter Finish Time: '))
        start.append(s)
        finish.append(f)
    return [start,finish]

def adjust_selection(selection:list[int]):
    for i in range(0,len(selection)):
        selection[i]-=1
    return selection

def sort_index(base:list[int],index:list[int]):
    for i in range(0,len(index)):
        index[i]=base[index[i]]

if(__name__=='__main__'):
    start,finish = createLists()
    index = [-1]+[i for i in range(1,len(start))]
    finish,start,index = zip(*sorted(zip(finish,start,index)))
    solution=activity(start,finish,0)
    sort_index(index,solution)
    print("Selected Activities are: ")
    print(adjust_selection(solution))

    # start = [0,5, 4, 3, 2, 1]
    # finish = [0,9, 8, 7, 6, 5]
    # start = [0,1, 3, 0, 5, 8, 5, 6, 2, 4, 3, 7, 2, 9, 11, 10]
    # finish = [0,2, 4, 6, 7, 9, 9, 8, 5, 7, 6, 11, 4, 10, 13, 12]
    # start = [0,1, 3, 2, 5, 7, 6, 8]
    # finish = [0,2, 4, 5, 7, 9, 8, 10]
    
