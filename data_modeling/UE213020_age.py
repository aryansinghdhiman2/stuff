import numpy as np

# dates = ['2003-02-10', '2003-03-01', '2003-03-23', '2003-04-14', '2003-05-06', '2003-05-28', '2003-06-18', '2003-07-10', '2003-08-01', '2003-08-23']

dates = ['2003-02-10', '2003-06-12', '2003-10-12', '2004-02-11', '2004-06-12', '2004-10-11', '2005-02-10', '2005-06-12', '2005-10-12', '2005-02-10']

dates = [np.datetime64(i) for i in dates]
today = np.datetime64('Today')
for date in dates:
    k = np.timedelta64()
    age = int((today - date).astype('timedelta64[Y]'))
    label = ''
    
    match(age):
        case(18):
            label = 'First'
        case(19):
            label = 'Second'
        case(20):
            label = 'Third'
        case(21):
            label = 'Fourth'
    
    print(f"DOB: {date}, age: {age}, label: {label}")


