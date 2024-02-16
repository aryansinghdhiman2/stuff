import csv
import numpy as np
import time
start = time.time()
unit = []
with open('OnlineRetail.csv', newline='') as f:
    reader = csv.reader(f)
    ignore = False
    for row in reader:
         if(ignore == True):
              unit.append(float(row[5]))
         ignore = True


mean = np.mean(unit)
std_dev = np.std(unit)
max = np.max(unit)
min = np.min(unit)
print("Mean  Unit Price is :", mean)
print("Standard Deviatoion of Unit Price is :", std_dev)
print("Maximunm Unit Price is :", max)
print("Minimum Unit Price is :", min)
stop = time.time()
print(stop-start)