import random
import time
import csv
import matplotlib.pyplot as plt
fig = plt.figure()
ax = fig.add_subplot()
ax.set_xlabel('Value of N')
ax.set_ylabel('Time in seconds')


def binarySearch(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)
        else:
            return binarySearch(arr, mid + 1, r, x)
    else:
        return -1


def n_ary(li,n,low,high,key):
    cuts=n-1
    N=high-low
    cut_loc=[]
    if(N<=(cuts+1)):
        k=binarySearch(li,low,high,key)
        return k
    else:
        for i in range(1,cuts+1):
            cut_loc.append(((i*(N+1))//(cuts+1)+low))
        for j in range(0,cuts):
            if(key==li[(cut_loc[j])]):
                return cut_loc[j]
            if(key<li[cut_loc[j]]):
                return n_ary(li,n,low,cut_loc[j],key)
            low=cut_loc[j]
        return n_ary(li,n,cut_loc[-1],high,key)
            
time_list= []
N = []
file = "table.csv"
fields = ['No. of cuts', 'time_lapsed', 'Value_of_i']
with open(file, 'w') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(fields)
    # n=[3,5,7,9,11,15,17]
    n=range(2,14)
    num=10000
    for i in n:
        print(i)
        time_lapse = 0
        for j in range(0,1000): 
            num_list = random.sample(range(1,num+1000), num)
            num_list.sort()
            key= random.randint(1,num+1000)
            start = time.time()
            t=n_ary(num_list,i,0,len(num_list)-1,key)
            stop = time.time()
            time_lapse += (stop - start)
            rows = [str(i), str(time_lapse), str(t)]
            csvwriter.writerow(rows)
        time_lapse1 = time_lapse / 1000
        time_list.append(time_lapse1)
        N.append(i)
ax.plot(N, time_list)
plt.show() 





