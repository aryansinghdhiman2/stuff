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
    with open("linear_search.csv",'w',newline='') as csvfile:
        csvwriter = csv.writer(csvfile,delimiter='|')
        # for range,index,keys,time in log['Range'],log['Index'],log['Keys'],log['Time']:
        #     csvwriter.writerow(range,index,keys,time)
        range_tuple = log['Range']
        index = log['Index']
        keys = log['Keys']
        time_tuple = log['Time']

        for i in range(0,len(range_tuple)):
            csvwriter.writerow([range_tuple[i],time_tuple[i],index[i],keys[i]])


log = {'Range':[],
            'Index':[],
            'Keys':[],
            'Time':[]
    }

def analysis(range_of_data,number_of_iter):
    log = {'Range':[],
            'Index':[],
            'Keys':[],
            'Time':[]
    }
    for data_len in range_of_data:
        print(data_len)
        log['Range'].append(data_len)
        # log['Keys'].append(key)

        index_list = []
        key_list = []
        begin = time()

        extra_time_1 = extra_time_2 = extra_diff = 0
        for i in range(0,number_of_iter):
            extra_time_1 = time()
            data = sample(range(0,data_len),int(data_len/2))
            key = randint(0,data_len)
            key_list.append(key)
            extra_time_2 = time()
            extra_diff = extra_diff +(extra_time_2 - extra_time_1)
            index_list.append(linear_search(data,key))
        end = time()
        final_time = ((end - begin)-extra_diff)/number_of_iter
        log['Time'].append(final_time)
        log['Index'].append(index_list)
        log['Keys'].append(key_list)
    # plt.show()
    return log

# lg = analysis([100000,10000],100)
# # print(lg['Time'])
# plt.show()

log_joiner(log,analysis(range(1000,1500,100),1000))
log_joiner(log,analysis(range(1500,2000,100),1000))
logger(log)
log_plotter(log)