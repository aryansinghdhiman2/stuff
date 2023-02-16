from sys import maxsize
from matplotlib import pyplot as plt
from random import sample
from time import time
from math import log2
import csv
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

def analysis(array_of_range,number_of_iter):
    log ={
        'Range':[],
        'Time':[],
        'Count':[]
    }
    for n in array_of_range:
        print(n)
        log['Range'].append(n)

        time_taken = count_var = 0 
        for i in range(0,number_of_iter):
            array = sample(range(0,n**2),n)
            array.append(maxsize)
            begin = time()
            count_var+=quickSort(array,0,len(array)-2)
            end = time()
            array.pop()
            time_taken += end - begin
            
        log['Time'].append(time_taken/number_of_iter)
        log['Count'].append(count_var/number_of_iter)
    return log

def log_plotter(log):
    log_list = []
    for n in log['Range']:
        log_list.append(2.74*((n*log2(n))/(10000000)))
    plt.plot(log['Range'],log['Time'],color='r',label='Quick Sort')
    plt.plot(log['Range'],log_list,label='O(nlogn)')
    plt.legend(loc='upper center')
    plt.show()
    plt.plot(log['Range'],log['Count'],label='Depth of recursion')
    plt.legend(loc='upper center')
    plt.show()

def logger(log):
    with open("quickSort.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        range_tuple = log['Range']
        time_tuple = log['Time']
        count_tuple = log['Count']

        for i in range(0,len(range_tuple)):
            csvwriter.writerow([range_tuple[i],time_tuple[i],count_tuple[i]])

if(__name__=="__main__"):
    log = analysis(range(1000,5000,1000),1000)
    logger(log)
    log_plotter(log)
