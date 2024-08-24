# def decorator(*args, **kwargs):
#     print("Inside decorator")
     
#     def inner(func):
         
#         # code functionality here
#         print("Inside inner function")
#         print("I like", kwargs['like'])
         
#         func()
         
#     # returning inner function   
#     return inner
 
# @decorator(like = "geeksforgeeks")
# def my_func():
#     print("Inside actual function")
# from time import time
# from random import sample
# begin = time()
# for i in range(0,1000):
#     data = sample(range(0,100000),5000)
# end = time()
# print((end - begin)/1000)

# from matplotlib import pyplot as plt

# plt.plot([3,2],[2,3])
# # plt.plot(2,3,'bo',linewidth=2)
# plt.show()

# import csv
# with open('eggs.csv', 'w', newline='') as csvfile:
#     spamwriter = csv.writer(csvfile, delimiter=' ',
#                             quotechar='|', quoting=csv.QUOTE_MINIMAL)
#     spamwriter.writerow(['Spam'] * 5 + ['Baked Beans'])
#     spamwriter.writerow(['Spam', 'Lovely Spam', 'Wonderful Spam'])

from matplotlib import get_backend
from matplotlib import pyplot
print(get_backend())
pyplot.plot([0,0],[1,1])
pyplot.show()