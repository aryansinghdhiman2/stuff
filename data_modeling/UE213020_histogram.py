import csv
import numpy as np
from matplotlib import pyplot as plt

with open('OnlineRetail.csv', newline='') as f:
    reader = csv.reader(f)
    unitPrice = []
    next(reader)

    for row in reader:
        unitPrice.append(float(row[5]))
    
    plt.hist(unitPrice,bins=10000,facecolor='b',alpha=0.5,edgecolor='black')
    plt.show()