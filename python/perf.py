from time import time
def performance(func):
    def wrap(*args,**kwargs):
        t1=time()
        result = func(*args,**kwargs)
        t2=time()
        print(f"Time taken is {t2-t1} s")
        return result
    return wrap

@performance
def long_time():
    for i in range(10000000):
        i*5
    return i
print(long_time())