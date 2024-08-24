from time import time
from random import sample,randint
from matplotlib import pyplot as plt
import csv

def binary_search(data,key):
    begin = 0
    end = len(data)-1
    while(end >= begin):
        mid = int((begin + end)/2)
        if(data[mid]==key):
            return mid
        elif(key>data[mid]):
            begin = mid+1
        else:
            end = mid-1
    return -1

def log_joiner(log_1,log_2):
    log_1['Range']=log_1['Range']+log_2['Range']
    log_1['Index']=log_1['Index']+log_2['Index']
    log_1['Time']=log_1['Time']+log_2['Time']
    log_1['Keys']=log_1['Keys']+log_2['Keys']

def log_plotter(log):
    plt.plot(log['Range'],log['Time'])
    plt.show()

def logger(log):
    with open("binary_search_2.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        range_tuple = log['Range']
        index = log['Index']
        keys = log['Keys']
        time_tuple = log['Time']

        for i in range(0,len(range_tuple)):
            csvwriter.writerow([range_tuple[i],time_tuple[i],index[i],keys[i]])

def analysis(range_of_data,number_of_iter):
    log = {'Range':[],
            'Index':[],
            'Keys':[],
            'Time':[]
    }
    for data_len in range_of_data:
        print(data_len)
        log['Range'].append(data_len/2)

        index_list = []
        key_list = []
        begin = time()

        extra_time_1 = extra_time_2 = extra_diff = 0
        for i in range(0,number_of_iter):
            extra_time_1 = time()
            data = sample(range(0,data_len),int(data_len/2))
            data.sort()
            key = randint(0,data_len)
            key_list.append(key)
            extra_time_2 = time()
            extra_diff = extra_diff +(extra_time_2 - extra_time_1)
            index_list.append(binary_search(data,key))
        end = time()
        final_time = ((end - begin)-extra_diff)/number_of_iter
        log['Time'].append(final_time)
        log['Index'].append(index_list)
        log['Keys'].append(key_list)
    return log

if(__name__=="__main__"):
    log = {'Range':[],
            'Index':[],
            'Keys':[],
            'Time':[]
        }
    log_joiner(log,analysis(range(1000,10000,500),1000))
    log_joiner(log,analysis(range(10000,100000,5000),1000))
    log_joiner(log,analysis(range(100000,1000000,50000),500))
    log_joiner(log,analysis(range(1000000,2000000,100000),500))
    logger(log)
    log_plotter(log)
