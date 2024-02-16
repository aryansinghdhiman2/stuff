import csv
import numpy as np
import time

start = time.time()

with open('OnlineRetail.csv', newline='') as f:
    reader = csv.reader(f)
    unitPrice = []
    next(reader)

    for row in reader:
        unitPrice.append(float(row[5]))

    unitPrice = np.array(unitPrice)
    print(f"{unitPrice.mean()}")
    print(f"{unitPrice.std()}")
    print(f"{unitPrice.min()}")
    print(f"{unitPrice.max()}")

stop = time.time()
print()
print(stop-start)


