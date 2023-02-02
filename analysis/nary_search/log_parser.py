import csv
from matplotlib import pyplot as plt
import sys

maxInt = sys.maxsize
while True:
    # decrease the maxInt value by factor 10 
    # as long as the OverflowError occurs.

    try:
        csv.field_size_limit(maxInt)
        break
    except OverflowError:
        maxInt = int(maxInt/10)

log = {'N':[],'Time':[]}

with open("vmnway4.csv",newline='') as csvfile:
    csvreader = csv.reader(csvfile,delimiter='|')
    for row in csvreader:
        log['N'].append(int(row[0]))
        log['Time'].append(float(row[1]))
# plt.axline([0, 0], [4.98 * (10 ** 5), 0.1260],color='g')
plt.plot(log['N'],log['Time'])
plt.show()