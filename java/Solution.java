class Solution {
    private static int searchHigh(int[] nums,int high,int low,int target)
    {
        if(high >= nums.length || low < 0 || low >= nums.length || high < 0)
        {
            return -1;
        }  

        int middle = (high + low) / 2;

        if(nums[middle] == target)
        {
            var nextHigh = searchHigh(nums, high, middle+1, target);
            if(nextHigh == -1)
                return middle;
            else return nextHigh;
        }
        else if(nums[middle]>target)
        {
            return searchHigh(nums, middle -1, low, target);
        }
        else return -1;
    }
    private static int searchLow(int[] nums,int high,int low,int target)
    {
        if(high >= nums.length || low < 0 || low >= nums.length || high < 0)
        {
            return -1;
        }  

        int middle = (high + low) / 2;

        if(nums[middle] == target)
        {
            var nextLow = searchLow(nums, middle - 1, low, target);
            if(nextLow == -1)
                return middle;
            else return nextLow;
        }
        else if(nums[middle]<target)
        {
            return searchLow(nums, high, middle + 1, target);
        }
        else return -1;
    }
    private static int[] search(int[] nums,int high,int low,int target)
    {
        if(high >= nums.length || low < 0 || low >= nums.length || high < 0)
        {
            return new int[] {-1,-1};
        }
        int middle = (high + low) / 2;
        
        if(nums[middle]==target)
        {
            var nextLow = searchLow(nums, middle - 1, 0, target);
            nextLow = nextLow == -1 ? middle : nextLow;

            var nextHigh = searchHigh(nums,nums.length-1,middle + 1,target);
            nextHigh = nextHigh == -1 ? middle : nextHigh;

            return new int[] {nextLow,nextHigh};
        }
        else if(nums[middle]>target)
        {
            return search(nums, middle-1, low, target);
        }
        else
        {
            return search(nums, high, middle+1, target);
        }
    }
    public static int[] searchRange(int[] nums, int target) {
        return search(nums, nums.length-1, 0, target);
    }

    public static void main(String[] args) {
        int[] nums = {5,7,7,8,8,10};
        System.out.println(searchRange(nums,8));
    }
}