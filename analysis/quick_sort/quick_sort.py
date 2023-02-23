from sys import maxsize,setrecursionlimit
from matplotlib import pyplot as plt
from random import sample,randint
from time import time
from math import log2
import csv

setrecursionlimit(5000)

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

def randomPartition(array,low,high):
    replaceIndex = randint(low,high)
    temp = array[low]
    array[low]=array[replaceIndex]
    array[replaceIndex]=temp

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

def randomQuicksort(array,low,high):
    count = 0
    if(low<high):
        j = randomPartition(array,low,high+1)
        count1=randomQuicksort(array,low,j-1)
        count2=randomQuicksort(array,j+1,high)
        count+=count1+count2
    count+=1
    return count

def analysis(array_of_range,number_of_iter):
    log ={
        'Range':[],
        'Time':[],
        'Count':[],
        'TimeSort':[],
        'CountSort':[],
        'TimeSortRandom':[],
        'CountSortRandom':[],
        'TimeRandom':[],
        'CountRandom':[]
    }
    for n in array_of_range:
        print(n)
        log['Range'].append(n)

        time_taken = time_taken_sort = 0
        time_taken_sort_random = 0
        time_taken_random = 0
        count_var_sort = count_var = 0
        count_var_sort_random = 0
        count_var_random = 0
        for i in range(0,number_of_iter):
            array = sample(range(0,n**2),n)
            array.append(maxsize)
            duplicateArray = array.copy()

            begin = time()
            count_var+=quickSort(array,0,len(array)-2)
            end = time()
            time_taken += end - begin
            
            beginSorted = time()
            count_var_sort+=quickSort(array,0,len(array)-2)
            endSorted = time()
            time_taken_sort+=endSorted-beginSorted

            beginRandom = time()
            count_var_random+=randomQuicksort(duplicateArray,0,len(array)-2)
            endRandom = time()
            time_taken_random+=endRandom-beginRandom

            beginSortedRandom = time()
            count_var_sort_random+=randomQuicksort(duplicateArray,0,len(array)-2)
            endSortedRandom = time()
            time_taken_sort_random+=endSortedRandom-beginSortedRandom

            array.pop()
            duplicateArray.pop()

            
        log['Time'].append(time_taken/number_of_iter)
        log['Count'].append(count_var/number_of_iter)
        log['TimeSort'].append(time_taken_sort/number_of_iter)
        log['CountSort'].append(count_var_sort/number_of_iter)
        log['TimeRandom'].append(time_taken_random/number_of_iter)
        log['CountRandom'].append(count_var_random/number_of_iter)
        log['TimeSortRandom'].append(time_taken_sort_random/number_of_iter)
        log['CountSortRandom'].append(count_var_sort_random/number_of_iter)
    return log

def log_plotter(log):
    log_list = []
    square_list = []
    
    for n in log['Range']:
        log_list.append(2.74*((n*log2(n))/(10000000)))
    for n in log['Range']:
        square_list.append(4*(n*n)/(10**8))

    plt.plot(log['Range'],log['Time'],color='r',label='QuickSort')
    plt.plot(log['Range'],log_list,label='O(nlogn)')
    plt.plot(log['Range'],log['TimeRandom'],label='Randomized QuickSort')
    plt.plot(log['Range'],log['TimeSortRandom'],label='Randomized QuickSort on sorted array')
    plt.legend(loc='upper center')
    plt.show()
    plt.plot(log['Range'],log['TimeSort'],label='QuickSort on sorted array')
    plt.plot(log['Range'],log['TimeSortRandom'],label='Randomized QuickSort on sorted array')
    plt.plot(log['Range'],square_list,label='O(n^2)')
    plt.legend(loc='upper center')
    plt.show()
    plt.plot(log['Range'],log['Count'],label='Recursion depth of non-randomized QuickSort')
    plt.plot(log['Range'],log['CountSort'],label='Recursion depth of non-randomized QuickSort on sorted array')
    plt.plot(log['Range'],log['CountRandom'],label='Recursion depth of randomized QuickSort')
    plt.plot(log['Range'],log['CountSortRandom'],label='Recursion depth of randomized QuickSort on sorted array')
    plt.plot(log['Range'],log['Range'],label='Linear')
    plt.legend(loc='upper center')
    plt.show()
    plt.plot(log['Range'],log['Time'],color='r',label='QuickSort')
    plt.plot(log['Range'],log_list,label='O(nlogn)')
    plt.plot(log['Range'],log['TimeRandom'],label='Randomized QuickSort')
    plt.plot(log['Range'],log['TimeSortRandom'],label='Randomized QuickSort on sorted array')
    plt.plot(log['Range'],log['TimeSort'],label='QuickSort on sorted array')
    plt.plot(log['Range'],square_list,label='O(n^2)')
    plt.legend(loc='upper center')
    plt.show()

def logger(log):
    with open("quickSort.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        range_tuple = log['Range']
        time_tuple = log['Time']
        count_tuple = log['Count']
        sort_count_tuple = log['CountSort']
        sort_time_tuple = log['TimeSort']

        for i in range(0,len(range_tuple)):
            csvwriter.writerow([range_tuple[i],time_tuple[i],count_tuple[i],sort_time_tuple[i],sort_count_tuple[i]])

if(__name__=="__main__"):
    log = analysis(range(100,1000,250),1000)
    logger(log)
    log_plotter(log)
