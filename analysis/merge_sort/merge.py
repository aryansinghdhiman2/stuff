from matplotlib import pyplot as plt
from random import sample
from time import time
from math import log2
def merge(array,low,mid,high):
    h = low
    j = mid + 1
    b = []
    while((h<=mid) and (j<=high)):
        if(array[h]<=array[j]):
            b.append(array[h])
            h+=1
        else:
            b.append(array[j])
            j+=1
    if(h>mid):
        for k in range(j,high+1):
            b.append(array[k])
    else:
        for k in range(h,mid+1):
            b.append(array[k])
    
    for i in range(low,high+1):
        array[i]=b[i-low]

def mergeSort(array,low,high):
    if(low<high):
        mid = int((low+high)/2)
        mergeSort(array,low,mid)
        mergeSort(array,mid+1,high)

        merge(array,low,mid,high)


def analysis(array_of_range,number_of_iter):
    log ={
        'Range':[],
        'Time':[],
        'Count':[]
    }
    for n in array_of_range:
        print(n)
        log['Range'].append(n)

        time_taken = 0 
        for i in range(0,number_of_iter):
            array = sample(range(0,n**2),n)
            begin = time()
            mergeSort(array,0,len(array)-1)
            end = time()
            time_taken += end - begin
            
        log['Time'].append(time_taken/number_of_iter)
    return log

def log_plotter(log):
    log_list = []
    for n in log['Range']:
        log_list.append(2.64*((n*log2(n))/(10000000)))
    plt.plot(log['Range'],log['Time'],color='r',label='Merge Sort')
    plt.plot(log['Range'],log_list,label='O(nlogn)')
    plt.legend(loc='upper center')
    plt.show()

if(__name__ == "__main__"):
    log_plotter(analysis(range(1000,20000,1000),1000))
