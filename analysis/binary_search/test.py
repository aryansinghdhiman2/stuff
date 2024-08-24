import random
import time
import csv
import matplotlib.pyplot as plt
import numpy as np
from matplotlib import get_backend

# print(get_backend())
def binary_search(list, key):
    left = 0
    right = len(list) - 1
    while left <= right:
        mid = (left + right) // 2
        if list[mid] == key:
            return mid
        elif list[mid] < key:
            left = mid + 1
        else:
            right = mid - 1
    return -1


time_arr = []
N = []
file = "databin.csv"
fields = ['Index', 'time_taken', 'N']
with open(file, 'w') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(fields)

    for n in range(10000, 100000, 500):
        time_taken = 0
        for j in range(1, 1000):
            list = [random.randrange(1, n+500) for i in range(1, n)]
            list.sort()
            key = random.randint(1, n+500)
            start = time.time()
            index = binary_search(list, key)
            stop = time.time()
            time_taken += (stop-start)
            rows = [str(index), str(time_taken), str(n)]
            csvwriter.writerow(rows)
        time_lapse1 = time_taken/1000
        time_arr.append(time_lapse1)
        N.append(n)

plt.plot(N, time_arr)
plt.show()