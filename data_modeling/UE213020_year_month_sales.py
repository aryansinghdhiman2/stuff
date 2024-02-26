from datetime import datetime
import csv
from matplotlib import pyplot as plt
import pandas

month_dict = {1 : "January", 2 : "February", 3 : "March", 4 : "April", 
              5 : "May" , 6 : "June", 7 : "July", 8 : "August", 
              9 : "September", 10 : "October" ,11 : "November",12 : "December"}

with open('OnlineRetail.csv', newline='') as f:
    reader = csv.reader(f)
    sales: dict[int,dict[int,int]] = dict()
    next(reader)
    dt = datetime.now()

    for row in reader:
        try:
            dt = datetime.strptime(row[4].split(' ')[0],"%d-%m-%Y")
        except:
            dt = datetime.strptime(row[4].split(' ')[0],"%m/%d/%Y")

        if(sales.get(dt.year) == None):
            sales[dt.year] = dict()
        
        if(sales[dt.year].get(dt.month) == None):
            sales[dt.year][dt.month] = 1
        else: 
            sales[dt.year][dt.month] += 1
    
    df = pandas.DataFrame.from_dict(sales,orient='index')
    df.rename(columns=month_dict,inplace=True)
    df.plot.bar()
    plt.show()

    