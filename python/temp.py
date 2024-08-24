from matplotlib import pyplot as plt
import numpy as np


for n in [-2, 1, 2, 3]:
    x = np.linspace(-100,100)
    y = x ** n
    plt.plot(x,y)

plt.show()