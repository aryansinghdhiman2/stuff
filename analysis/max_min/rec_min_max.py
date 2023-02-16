from brute_min_max import brute_min_max
from random import sample
from matplotlib import pyplot as plt
from time import time

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

def analysis(array_of_range,number_of_iter):
    log = {
        'Range':[],
        'Time':[],
        'Max':[],
        'Min':[]
    }
    for n in array_of_range:
        log['Range'].append(n)
        max_list = []
        min_list = []
        
        used_time = 0
        print(n)
        for i in range(0,number_of_iter):
            array = sample(range(0,n**2),n)
            begin = time()
            pair = simple_min_max(array)
            end = time()
            used_time+=(end-begin)
            max_list.append(pair[0])
            min_list.append(pair[1])
        log['Time'].append(used_time/number_of_iter)
        log['Max'].append(max_list)
        log['Min'].append(min_list)
    return log

def log_plotter(log):
    plt.plot(log['Range'],log['Time'])
    plt.show()


if(__name__ == "__main__"):
    log = analysis(range(1000,10000,500),1000)
    log_plotter(log)