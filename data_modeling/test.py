# from matplotlib import pyplot as plt
# import numpy as np
# import seaborn as sns

# def f(t): 
#     return np.exp(-t) * np.cos(2*np.pi*t) 
# t1 = np.arange(0.0, 5.0, 0.1) 
# t2 = np.arange(0.0, 5.0, 0.02) 
# plt.figure(1) # Called implicitly
# # for multiple figures 
# # plt.subplot(331) # 2 rows, 1 column, 1st plot 
# plt.subplot(6,6,(15,16))
# plt.plot(t1, f(t1), 'bo',t2, f(t2), 'k') 
# plt.subplot(339) # 2 rows, 1 column, 2nd plot 
# plt.plot(t2, np.cos(2*np.pi*t2), 'r--') 
# plt.show() 

# times = range(8)
# co2 = [250, 265, 272, 260, 300, 320, 389,403]
# plt.plot(times, co2)
# plt.plot(times, co2, 'b--')
# plt.title("Concentration of CO2 versus time")
# plt.ylabel("[CO2 Gas]")
# plt.xlabel("Time (decade)")
# plt.show()

# temp = [14.1, 15.5, 16.3, 18.1, 17.3, 19.1, 20.2, 22.4]
# plt.plot(times, co2, 'b--', times, temp, 'r*-')
# plt.savefig("co2_temp.pdf")
# plt.show()

# fig, ax1 = plt.subplots()
# times = range(8)
# co2 = [250, 265, 272, 260, 300, 320, 389, 410]
# ax1.plot(times, co2, "b--")
# ax1.set_ylabel("[CO2]")
# ax2 = ax1.twinx()
# temp = [14.1, 15.5, 16.3, 18.1, 17.3, 19.1, 20.2, 20.8]
# ax2.plot(times, temp, "r*-")
# ax2.set_ylabel("Temp (degC)")
# plt.show()

# plt.subplot(2, 2, 1)
# x = range(0, 10, 1)
# plt.plot(x)
# plt.subplot(2, 2, 2)
# y = range(10, 0, -1)
# plt.plot(y)
# plt.subplot(2, 2, (3,4))
# z = [4] * 10
# plt.plot(z)
# plt.show()

# mu, sigma = 70, 10 
# x = mu + sigma * np.random.randn(10000) 
# # the histogram of the data 
# n, bins, patches = plt.hist(x, 50,density=True, facecolor='b', alpha=0.2) 
# plt.xlabel('Smarts') 
# plt.ylabel('Probability') 
# plt.title('Histogram of IQ') 
# plt.text(60, .045, '$\mu=70,\ \sigma=10$', color='r') #TeX equations 
# plt.axis([30, 100, 0, 0.05]) 
# plt.grid(True) 
# plt.show() 
# print(n, bins,patches)

# rng = np.random.RandomState(0)
# x = np.linspace(0, 10, 500)
# y = np.cumsum(rng.randn(500, 6), 0)
# plt.plot(x, y)
# plt.legend('ABCDEF', ncol=2, loc='upper left');
# plt.show()

# sns.set_theme()

# plt.plot(x, y)
# plt.legend('ABCDEF', ncol=2, loc='upper left')
# plt.show()

# iris = sns.load_dataset("iris")
# iris.head()
# sns.pairplot(iris, hue='species', height=2.5)
# plt.show()

# tips = sns.load_dataset('tips')
# tips.head()
# tips['tip_pct'] = 100 * tips['tip'] / tips['total_bill']

# grid = sns.FacetGrid(tips, row="sex", col="time", margin_titles=True)
# grid.map(plt.hist, "tip_pct", bins=np.linspace(0, 40, 15))
# plt.show()

# with sns.axes_style(style='ticks'):
#     g = sns.catplot(x="day", y="total_bill", hue="sex", data=tips, kind="box")
#     g.set_axis_labels("Day", "Total Bill");
#     plt.show()


# array = [1,2,3,1]

# plt.hist(array,bins=2,density=False,facecolor='b',alpha=0.5,edgecolor='black')
# plt.show()

# from datetime import datetime
# import csv
# import numpy as np
# from matplotlib import pyplot as plt
# import seaborn as sns
# import pandas

# class Sales:
#     def __init__(self,year:int,month:int) -> None:
#         self.year = year
#         self.month = month
#         self.sales = 0
#     def __eq__(self, other: "Sales") -> bool:
#         if(self.year == other.year and self.month == other.month):
#             return True
#         else: return False


# sns.set_theme()


# with open('OnlineRetail.csv', newline='') as f:
#     reader = csv.reader(f)
#     sales: list[Sales] = []
#     next(reader)
#     dt = datetime.now()

#     for row in reader:
#         try:
#             dt = datetime.strptime(row[4].split(' ')[0],"%d-%m-%Y")
#         except:
#             dt = datetime.strptime(row[4].split(' ')[0],"%m/%d/%Y")

#         sale = Sales(dt.year,dt.month)

#         try:
#             sales[sales.index(sale)].sales+=1
#         except:
#             sale.sales+=1
#             sales.append(sale)

#         # if sale not in sales:
#         #     sale.sales+=1
#         #     sales.append(sale)
#         # else:
#         #     sales[sales.index(sale)].sales+=1
    
#     # pandas.DataFrame.from_dict(sale)


#     # sns.barplot(dsales)
#     # plt.show()

import numpy as np
from numpy.random import randn

arr = randn(5,5)

print(arr)
print(arr > 0)
print(arr[arr > 0].shape)