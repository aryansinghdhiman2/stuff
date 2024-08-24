from multiprocessing.reduction import duplicate
from os import dup


some_list=['a','b','c','b','d','m','n','n','m','b']

#Method 1
# copy_of_list=some_list.copy()
# i=0
# while i < len(some_list):
#     count=0
#     k=0
#     while k<len(some_list):
#         if(some_list[i]==some_list[k]):
#             count+=1
#         k+=1
#     if(count==1):
#         copy_of_list.remove(some_list[i])
#     i+=1

# list_with_duplicates=copy_of_list.copy()

# count=0
# for i in copy_of_list:
#     for k in copy_of_list:
#         if(i==k):
#             count+=1
#     j=0
#     while j<(count-1):
#         copy_of_list.remove(i)
#         j+=1
#     count=0

# print(copy_of_list)

#Method 2
duplicate=[]
for i in some_list:
    if(some_list.count(i)>1):
        if i not in duplicate:
            duplicate.append(i)

print(duplicate)





