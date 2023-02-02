import csv
from matplotlib import pyplot as plt
from io import StringIO
from math import log2
log = {'Range':[],'Time':[],'AverageIndex':[],'AverageKey':[]}

with open("bns2.csv",newline='') as csvfile:
    csvreader = csv.reader(csvfile,delimiter='|')
    for row in csvreader:
        log['Range'].append(int(int(row[0]))/2)
        log['Time'].append(float(row[1]))
        tempindex = row[2].strip('[]')
        tempFile = StringIO(tempindex)
        index = []
        newreader = csv.reader(tempFile,delimiter=',')
        # print(newreader)
        for val in newreader:
            for newVal in val:
                index.append(int(newVal))
        final_index = []
        for val in index:
            if(val != -1):
                final_index.append(val)
        averageindex = 0
        for val in final_index:
            averageindex+=val
        averageindex = averageindex/len(final_index)
        log['AverageIndex'].append(averageindex)

        tempkey = row[3].strip('[]')
        tempKeyFile = StringIO(tempkey)
        keys = []
        newreaderkey = csv.reader(tempKeyFile,delimiter=',')
        # print(newreader)
        for val in newreaderkey:
            for newVal in val:
                keys.append(int(newVal))
        averagekey = 0
        for val in keys:
            averagekey+=val
        averagekey = averagekey/len(keys)
        log['AverageKey'].append(averagekey)
# plt.axline([0, 0], [4.98 * (10 ** 5), 0.1260],color='g')
plt.plot(log['Range'],log['Time'],color='g')

#logarithm_tuple = []
#for val in log['Range']:
#    logarithm_tuple.append((10**(-6))*(log2(val))-(4*(10**(-6))))

#plt.plot(log['Range'],logarithm_tuple,color='r')

# plt.plot(log['Range'],log['AverageIndex'],color='r')
# plt.plot(log['Range'],log['AverageKey'])
plt.show()