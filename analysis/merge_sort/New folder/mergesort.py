# import sys
# sys.setrecursionlimit(2000)
import random
from timeit import default_timer as timer
import matplotlib.pyplot as plt
import csv
from math import log2
def merge(arr,low,mid,high):
	L = []
	R = []

	for i in range(low,mid+1):
		L.append(arr[i])

	for i in range(mid+1,high+1):
		R.append(arr[i])

	i = j = 0
	k=low

	#Copy data to temp arrays L[] and R[]
	while i < len(L) and j < len(R):
		if L[i] <= R[j]:
			arr[k] = L[i]
			i += 1
		else:
			arr[k] = R[j]
			j += 1
		k += 1

	#Checking if any element was left
	while i < len(L):
		arr[k] = L[i]
		i += 1
		k += 1

	while j < len(R):
		arr[k] = R[j]
		j += 1
		k += 1

def merge_sort(arr,low,high):
	if (high>low):
		mid=low+(high-low)//2
		merge_sort(arr,low,mid)
		merge_sort(arr,mid+1,high)
		merge(arr,low,mid,high)


# li=[1,6,3,9,5,4,7,0,77,54,98,1,2,4]
# merge_sort(li,0,len(li)-1)
# print(li)

n_list=[]
time_list=[]
time_sort_list =[]
file= "mergeq.csv"
columns=['total_time','value_n']
with open(file,'w') as csvfile:
    writer=csv.writer(csvfile)
    writer.writerow(columns)


    for n in range (1000,10000,1000):
        print(n)
        n_list.append(n)
        time_taken=0
        time_sort = 0
        for i in range(1,200):
            num_list=random.sample(range(1,2*n),n)
            start= timer()
            merge_sort(num_list,0,len(num_list)-1)
            end= timer()
            time_taken= time_taken + (end-start)
            start= timer()
            merge_sort(num_list,0,len(num_list)-1)
            end= timer()
            time_sort= time_sort + (end-start)
            #time_list.append(time_taken)
            rows=[str(time_taken),str(n)]
            writer.writerow(rows)
        total_time=time_taken/200
        time_list.append(total_time)
        time_sort_list.append(time_sort/200)

    # last_n= n-1
    # last_time=total_time
    log_list = []
    for n in n_list:
        log_list.append(3.3*n*log2(n)/(10**7))
    plt.plot(n_list,time_list,label='Merge Sort on unsorted array')
    plt.plot(n_list,log_list,color='r',label='O(nlogn)')
    plt.legend()
    plt.show()
    plt.plot(n_list,log_list,color='r',label='O(nlogn)')
    plt.plot(n_list,time_sort_list,label='Merge Sort on sorted array')
    plt.legend()
    # x=[0,last_n]
    # y=[0,last_time]
    # plt.plot(x,y)
    plt.xlabel("list size")
    plt.ylabel("time taken")
    plt.show()


