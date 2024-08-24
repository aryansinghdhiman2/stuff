class SuperList(list):
    def __len__(self):
        return 1000

sl=SuperList([1,2,3,4,5,6])
sl.append(9)
print(sl[1])
print(sl)
print(len(sl))