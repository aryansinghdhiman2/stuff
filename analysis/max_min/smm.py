from time import time
from random import sample,randint,seed
from matplotlib import pyplot as plt
def simple_min_max(arr):
    maximum = minimum = arr[0]
    for i in range(2,len(arr)):
        if(maximum < arr[i]):
            maximum = arr[i]
        if(minimum > arr[i]):
            minimum = arr[i]
    return [maximum,minimum]

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
        for i in range(0,number_of_iter):
            array = sample(range(0,2*n),n)
            begin = time()
            pair = simple_min_max(array)
            end = time()
            used_time+=(end-begin)
            log['Max'].append(pair[0])
            log['Min'].append(pair[1])
        log['Time'].append(used_time)
    return log

def log_plotter(log):
    plt.plot(log['Range'],log['Time'])
    plt.show()


if(__name__=="__main__"):
    seed(time())
    # array = []
    # for i in range(0,250):
    #     array.append(randint(0,500))
    for i in range(0,100):
        array = sample(range(0,500**2),500)
        data = simple_min_max(array)
        print(f"{data[0]},{data[1]}")
    pass