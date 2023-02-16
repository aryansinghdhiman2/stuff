import sys

def partition(array,low,high):
    key = array[low]
    i = low
    j = high

    while(i<=j):
        while(i<=j and array[i]<=key):
            i+=1
        while(i<=j and array[j]>=key):
            j-=1
        if(i<j):
            temp=array[i]
            array[i]=array[j]
            array[j]=temp
    array[low]=array[j]
    array[j]=key
    return j
    
def quickSort(array,low,high):
    count = 0
    if(low<high):
        j = partition(array,low,high+1)
        count1=quickSort(array,low,j-1)
        count2=quickSort(array,j+1,high)
        count+=count1+count2
    count+=1
    return count


arr = [1,4,3,7,2,8]
arr.append(sys.maxsize) #infinity
quickSort(arr,0,len(arr)-2)
arr.pop() #remove inf
print(arr)