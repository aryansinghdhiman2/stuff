import random

def n_ary_search(num_list,key,n,start,end):
    for i in n:
        cuts= i-1
        cut_loc=[]
        for j in range (1,cuts):
            cut_loc[j]= (j*1000)/i
        for j in range (1,cuts):
            if (key==num_list[cut_loc[j]]):
                return cut_loc[j]
            if(key<num_list[cut_loc[j]]):
                n_ary_search(num_list,key,n,start,cut_loc[j]-1)
            if(j==cuts and key>num_list[cut_loc[j]]):
                n_ary_search(num_list,key,n,j,1000)
            start=cut_loc[j]+1

num_list=[random.randint(1,1200) for i in range(1,1000)]
num_list.sort()
key=random.randint(1,1200)
n=[2,3,4,7,9,11,13,15,17,19,21]
n_ary_search(num_list,key,n,1,1000)
