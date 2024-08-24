from time import time
from random import sample,randint
import csv
from matplotlib import pyplot as plt
def linear_search(data,key):
    for i in range(0,len(data)):
        if(data[i] == key):
            return i
    return -1

def n_way_search(data,key,n,log):
    begin = 0
    end = len(data)-1
    partition_end = int((end-begin)/n)+begin
    partition_begin = begin
    j = 2
    while((begin <= end) and (end - begin > n)):
        if(key == data[partition_end]):
            return partition_end
        elif(key > data[partition_end]):
            partition_begin = partition_end
            partition_end = int(j*(end-begin)/n)+begin
            j+=1
            if(partition_end > end):
                return -1
        else:
            end = partition_end
            begin = partition_begin
            partition_end = int((end-begin)/n)+begin
            j = 2
    if(end < begin):
        return -1
    else:
        log['Linear']+=1
        log['AverageLen']+=end-begin
        ret_val = linear_search(data[begin:end],key)
        if(ret_val == -1):
            return -1
        else:
            return begin + ret_val

def analysis(list_of_n,number_of_itr,length_of_array):
    log = []
    for n in list_of_n:
        log_dict = {'N':n,'Time':0,'Linear':0,'AverageLen':0}
        log.append(log_dict)
    for i in range(0,number_of_itr):
        print(f"Iteration: {i}")
        data = sample(range(0,2*length_of_array+1),length_of_array)
        key = randint(0,2*length_of_array)
        data.sort()
        for n in list_of_n:
            for pair in log:
                if(pair['N']==n):
                    log_dict = pair
                    break
            begin = time()
            placeholder = n_way_search(data,key,n,log_dict)
            end = time()
            for pair in log:
                if(pair['N']==n):
                    pair['Time']+=(end-begin)
                    break
    for pair in log:
        pair['Time'] = pair['Time']/number_of_itr
        pair['AverageLen'] = pair['AverageLen']/number_of_itr
    return log

def logger(log):
    with open("test.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        
        for pair in log:
            csvwriter.writerow([pair['N'],pair['Time'],pair['Linear'],pair['AverageLen']])

def log_plotter(log):
    list_of_n = []
    time_list = []
    for pair in log:
        list_of_n.append(pair['N'])
        time_list.append(pair['Time'])
    plt.plot(list_of_n,time_list)
    plt.show()

def log_plotter_linear(log):
    list_of_n = []
    number_list = []
    for pair in log:
        list_of_n.append(pair['N'])
        number_list.append(pair['Linear'])
    plt.plot(list_of_n,number_list)
    plt.show()

def log_plotter_length(log):
    list_of_n = []
    length_list = []
    for pair in log:
        list_of_n.append(pair['N'])
        length_list.append(pair['AverageLen'])
    plt.plot(list_of_n,length_list)
    plt.show()

def log_plotter_length_time(log):
    list_of_n = []
    length_list = []
    number_list = []
    for pair in log:
        list_of_n.append(pair['N'])
        length_list.append(pair['AverageLen'])
        number_list.append(100*pair['Linear']/1000)
    plt.plot(list_of_n,length_list)
    plt.plot(list_of_n,number_list,color='r')
    plt.grid()
    plt.show()

def sorter(pair):
    return pair['Time']

def minimum_time(log):
    new_log = log.copy()
    new_log.sort(key=sorter)
    print(new_log[0])




log = analysis(range(2,111),1000,10000)
# logger(log)
# minimum_time(log)
# log_plotter(log)
# log_plotter_linear(log)
# log_plotter_length(log)
# log_plotter_length_time(log)