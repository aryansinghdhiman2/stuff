def part(array:list[int],low,high):
    key = array[0]
    i=low
    j=high

    while(i<=j):
        while(i<=j and array[i]<=key):
            i+=1
        while(i<=j and array[j]>=key):
            j-=1
        if(i<j):
            temp=array[i]
            array[i]=array[j]
            array[j]=temp
    array[0]=array[j]
    array[j]=key

    return j

def quick(array,low,high):
    if(low<high):
        j = part(array,low,high)
        quick(array,low,j-1)
        quick(array,j+1,high)