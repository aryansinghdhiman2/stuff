import csv
import numpy as np

with open('OnlineRetail.csv', newline='') as f:
    reader = csv.reader(f)
    unitPrice = []
    next(reader)

    for row in reader:
        unitPrice.append(float(row[5]))

    unitPrice = np.array(unitPrice)
    print(f"Mean of Unit Price is:{unitPrice.mean()}")
    print(f"Standard Deviation of Unit Price is:{unitPrice.std()}")
    print(f"Minimum of Unit Price is:{unitPrice.min()}")
    print(f"Maximum of Unit Price is:{unitPrice.max()}")


    