import csv
from matplotlib import pyplot as plt
log = {'Range':[],'Time':[]}

with open("linear_search.csv",newline='') as csvfile:
    csvreader = csv.reader(csvfile,delimiter='|')
    for row in csvreader:
        log['Range'].append(int(int(row[0])/2))
        log['Time'].append(float(row[1]))
# plt.axline([0, 0], [4.98 * (10 ** 5), 0.1260],color='g')
plt.plot(log['Range'],log['Time'])
plt.show()