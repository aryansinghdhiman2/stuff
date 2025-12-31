import java.util.Arrays;

class Solution {
    public static boolean canPartition(int[] nums) {
        int setSum = Arrays.stream(nums).parallel().sum();

        if((setSum % 2) != 0) return false;

        int subSetSum = setSum / 2;

        boolean [] dp = new boolean[subSetSum+1];

        dp[0] = true;

        for(var num : nums)
        {
            for(int y = subSetSum;y>=0;y--)
            {
                if(y>=num)
                {
                    dp[y] = dp[y] || dp[y-num];
                }
            }
        }

        return dp[dp.length-1];
    }

    public static void main(String[] args) {
        int [] nums = new int[]{1,2,5};
        System.out.println(Solution.canPartition(nums));
    }
}