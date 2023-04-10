def reversePairs(nums: list[int]) -> int:
    count=0
    for i in range(0,len(nums)-1):
        for j in range(i+1,len(nums)):
            if(nums[i]>2*nums[j]):
                count+=1
    return count

print(reversePairs([1,3,2,3,1]))