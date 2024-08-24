def highest_even(li):
    high=0
    for item in li:
        high=item if ((item%2==0) and (item>high)) else high
    return high

print(highest_even([10,2,3,4,8,11]))