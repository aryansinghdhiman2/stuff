from random import randint,sample,seed
from time import time
from matplotlib import pyplot as plt
# print(randint(0,10000000))
seed(time())
# list=[]
start = time()
sample(range(0,2000),1000)
end = time()
# print(f'time taken {start-end}')
# print(end)

def time_decor(number_of_loops):
    def second_wrap(func):
        def wrap(*args,**kwargs):
            key_list = []
            begin=time()
            for i in range(0,number_of_loops):
                key_list.append(func(*args,**kwargs))
            end=time()
            result_time = (end-begin)/number_of_loops
            return [result_time,key_list]
        return wrap
    return second_wrap

# rt = time()
def plotter_decor(list_of_range):#To be only used with time_decor decorator
    def second_wrap(time_func):
        time_list = []
        def wrapper(*args,**kwargs):
            for i in list_of_range:
                num = int(i/2)
                dt = sample(range(0,i),num)
                kwargs['data'] = dt
                result = time_func(*args,**kwargs)
                time_list.append(result[0])
                # plt.plot(i,result[0])
        return wrapper
    return second_wrap


# @time_decor(10,rt)
# @plotter_decor([10000])
# @time_decor(1000)
def linear_search(data,key):
    for i in range(0,len(data)):
        if(data[i] == key):
            return i
    return -1






# print(linear_search(sample(range(0,2000000),1000000),(range(0,2000000))))
plotter_decor([1000000])(time_decor(10))(linear_search)(key=randint(0,2000000))
# plt.show()
# print(rt)
