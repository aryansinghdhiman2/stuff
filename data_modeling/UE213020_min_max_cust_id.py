import csv
import numpy as np
from matplotlib import pyplot as plt

with open('OnlineRetail.csv', newline='') as f:
    reader = csv.reader(f)
    unitPrice:dict[str,list[float]] = dict()
    next(reader)

    for row in reader:
        if(unitPrice.get(row[6]) == None):
            unitPrice[row[6]] = [float(row[5])]
        else:
            unitPrice[row[6]].append(float(row[5]))
    
    byCustId:dict[str,list[float]] = dict()

    for key in unitPrice:
        byCustId[key] = [np.min(unitPrice[key]),np.max(unitPrice[key])]
    
    for key in byCustId:
        print(f"For Customer: {key}, Minimum Value is: {byCustId[key][0]}, Maximum Value is: {byCustId[key][1]}")
    
    
