from time import time
from random import sample,randint
import csv
from matplotlib import pyplot as plt

def linear_search(data,key):
    for i in range(0,len(data)):
        if(data[i] == key):
            return i
    return -1

def n_way_search(data,key,n):
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
        return begin + linear_search(data[begin:end],key)

def analysis(list_of_n,number_of_itr,length_of_array):
    log = {
        'N':[],
        'Time':[],
        'Indexes':[],
        'Keys':[]
    }
    for n in list_of_n:
        print(f'{n}')
        extra_time_1 = extra_time_2 = extra_time_diff = 0
        key_list = []
        index_list = []
        begin = time()
        for i in range(0,number_of_itr):
            extra_time_1 = time()
            data = sample(range(0,2*length_of_array+1),length_of_array)
            key = randint(0,2*length_of_array)
            data.sort()
            key_list.append(key)
            extra_time_2 = time()
            extra_time_diff += (extra_time_2-extra_time_1)

            index_list.append(n_way_search(data,key,n))
        end = time()
        total_time = ((end - begin)-extra_time_diff)/number_of_itr
        log['N'].append(n)
        log['Time'].append(total_time)
        log['Keys'].append(key_list)
        log['Indexes'].append(index_list)
    return log

def logger(log):
    with open("n_way_search.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        range_tuple = log['N']
        index = log['Indexes']
        keys = log['Keys']
        time_tuple = log['Time']

        for i in range(0,len(range_tuple)):
            csvwriter.writerow([range_tuple[i],time_tuple[i],index[i],keys[i]])

def log_plotter(log):
    plt.plot(log['N'],log['Time'])
    plt.show()

log = analysis(range(2,14),1000,1000)
# logger(log)
log_plotter(log)