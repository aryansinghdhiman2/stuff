inp_list = [1,2,3,[2,3]]


if(any([isinstance(i,list) for i in inp_list])):
    print("Has Sublist")
else: print("No Sublist")