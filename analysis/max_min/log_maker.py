from time import time
from random import sample,randint,seed
from matplotlib import pyplot as plt
import csv

def brute_min_max(arr):
    maximum = minimum = arr[0]
    for i in range(1,len(arr)):
        if(maximum < arr[i]):
            maximum = arr[i]
        if(minimum > arr[i]):
            minimum = arr[i]
    return [maximum,minimum]

def simple_min_max(arr):
    maximum = minimum = arr[0]
    for i in range(1,len(arr)):
        if(maximum < arr[i]):
            maximum = arr[i]
        elif(minimum > arr[i]):
            minimum = arr[i]
    return [maximum,minimum]


def rec_min_max(array,low,high):
    count = 0
    if(low == high):
        minimum = maximum = array[low]
        count+=1
        return [maximum,minimum,count]
    else:
        if(low == (high-1)):
            if(array[low]<array[high]):
                maximum = array[high]
                minimum = array[low]
            else:
                maximum = array[low]
                minimum = array[high]
            count+=1
            return [maximum,minimum]
        else:
            mid = (low + high)//2
            maximum1 = minimum1 = 0
            maximum2 = minimum2 = 0

            maximum1,minimum1,count1 = rec_min_max(array,low,mid)
            maximum2,minimum2,count2 = rec_min_max(array,mid+1,high)

            if(maximum1 > maximum2):
                maximum = maximum1
            else:
                maximum = maximum2
            
            if(minimum1 < minimum2):
                minimum = minimum1
            else:
                minimum = minimum2
            count = count1 + count2 + 1
            return [maximum,minimum,count]

def analyse(array_of_range,number_of_iter):
    log = {
        'Range':[],
        'TimeBrute':[],
        'TimeSimple':[],
        'TimeRec':[],
        'Max':[],
        'Min':[]
    }
    
    for n in array_of_range:
        print(n)

        log['Range'].append(n)
        max_list = []
        min_list = []

        simpleTime = bruteTime = recTime = 0
        for i in range(0,number_of_iter):
            array = sample(range(0,n**2),n)
            bruteBegin = time()
            maximumBrute,minimumBrute = brute_min_max(array)
            bruteEnd = time()
            bruteTime += (bruteEnd - bruteBegin)

            simpleBegin = time()
            maximumSimple,minimumSimple = simple_min_max(array)
            simpleEnd = time()
            simpleTime += (simpleEnd - simpleBegin)
            if(maximumBrute!=maximumSimple or minimumBrute!=minimumSimple):
                print("Error1")
                exit()
            
            recBegin = time()
            maximumRec,minimumRec = rec_min_max(array,0,(len(array)-1))
            recEnd = time()
            recTime += (recEnd - recBegin)
            if(maximumBrute!=maximumRec or minimumBrute!=minimumRec):
                print("Error2")
                exit()            
            max_list.append(maximumBrute)
            min_list.append(minimumBrute)
        
        bruteTime = bruteTime/number_of_iter
        simpleTime = simpleTime/number_of_iter
        recTime = recTime/number_of_iter

        log['TimeBrute'].append(bruteTime)
        log['TimeSimple'].append(simpleTime)
        log['TimeRec'].append(recTime)

        log['Max'].append(max_list)
        log['Min'].append(min_list)

    return log

def log_plotter(log):
    plt.plot(log['Range'],log['TimeBrute'],color='r',label="Brute")
    plt.plot(log['Range'],log['TimeSimple'],color='b',label="Simple")
    plt.plot(log['Range'],log['TimeRec'],color='g',label="Recursive")
    plt.plot([0,10000],[0,0.00362])
    plt.legend(loc="upper center")
    plt.show()
    plt.plot(log['Range'],log['RecCount'],label='Depth of recursion')
    plt.show()

def logger(log):
    with open("min_max.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        range_tuple = log['Range']
        brute = log['TimeBrute']
        simple = log['TimeSimple']
        rec = log['TimeRec']
        max_tuple = log['Max']
        min_tuple = log['Min']

        for i in range(0,len(range_tuple)):
            csvwriter.writerow([range_tuple[i],brute[i],simple[i],rec[i],max_tuple[i],min_tuple[i]])

if(__name__ == "__main__"):
    array_of_range = range(1000,10000,250)
    number_of_iterations = 1000
    log = analyse(array_of_range,number_of_iterations)
    logger(log)
    log_plotter(log)


