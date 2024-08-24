from time import time
from random import sample,randint
from matplotlib import pyplot as plt
import csv

def linear_search(data,key):
    for i in range(0,len(data)):
        if(data[i] == key):
            return i
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
    with open("linear_search_fin.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        range_tuple = log['Range']
        index = log['Index']
        keys = log['Keys']
        time_tuple = log['Time']

        for i in range(0,len(range_tuple)):
            csvwriter.writerow([range_tuple[i],time_tuple[i],index[i],keys[i]])

def analysis(array_of_range,number_of_iter):
    log = {'Range':[],
            'Index':[],
            'Keys':[],
            'Time':[]
    }
    for range_of_sample_data in array_of_range:
        print(range_of_sample_data)
        log['Range'].append(int(range_of_sample_data/2))

        index_list = []
        key_list = []
        begin = time()

        extra_time_1 = extra_time_2 = extra_diff = 0
        for i in range(0,number_of_iter):
            extra_time_1 = time()
            data = sample(range(0,range_of_sample_data),int(range_of_sample_data/2))
            key = randint(0,range_of_sample_data)
            key_list.append(key)
            extra_time_2 = time()
            extra_diff = extra_diff +(extra_time_2 - extra_time_1)
            index_list.append(linear_search(data,key))
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
