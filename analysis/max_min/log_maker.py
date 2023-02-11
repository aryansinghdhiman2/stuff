from brute_min_max import brute_min_max
from simple_min_max import simple_min_max
from rec_min_max import rec_min_max
from time import time
from random import sample,randint,seed
from matplotlib import pyplot as plt

# def logs_plotter(logs):
#     for log in logs:
#         plt.plot(log['Range'],log['Time'])
#     plt.show()

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
    plt.plot(log['Range'],log['TimeBrute'])
    plt.plot(log['Range'],log['TimeSimple'])
    plt.plot(log['Range'],log['TimeRec'])
    plt.show()

if(__name__ == "__main__"):
    array_of_range = range(1000,10000,500)
    number_of_iterations = 1000

    log = analyse(array_of_range,number_of_iterations)
    log_plotter(log)

    # logs_plotter(logs)


