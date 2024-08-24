import csv
from matplotlib import pyplot as plt
import sys
maxInt = sys.maxsize
from io import StringIO
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
    temp = ''
    for row in csvreader:
        if(int(row[0])<21):
            log['N'].append(int(row[0]))
            log['Time'].append(float(row[1]))
            temp = row[2].strip('[]')
# plt.axline([0, 0], [4.98 * (10 ** 5), 0.1260],color='g')
tempIo = StringIO(temp)
read=csv.reader(tempIo,delimiter=',')
number = 0
for val in read:
    number=len(val)
print(number)
tickArray = []
for num in log['N']:
    if(num%2==0):
        tickArray.append(num)
plt.xticks(tickArray)
thing=plt.plot(log['N'],log['Time'])
# ax=thing[0].axes
# ax.fmt_xdata
# 1+1
plt.show()