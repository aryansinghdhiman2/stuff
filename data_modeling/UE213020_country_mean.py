import csv
import numpy as np
from matplotlib import pyplot as plt

with open('OnlineRetail.csv', newline='') as f:
    reader = csv.reader(f)
    unitPrice:dict[str,list[float]] = dict()
    next(reader)

    for row in reader:
        if(unitPrice.get(row[7]) == None):
            unitPrice[row[7]] = [float(row[5])]
        else:
            unitPrice[row[7]].append(float(row[5]))
    
    meanByCountry:dict[str,list[float]] = dict()

    for key in unitPrice:
        meanByCountry[key] = np.mean(unitPrice[key])
    
    plt.barh(list(meanByCountry.keys()),list(meanByCountry.values()),height=0.5)
    plt.show()
    
