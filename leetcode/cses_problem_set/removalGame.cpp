#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<intmax_t> nums;
    nums.reserve(n);

    intmax_t sum=0;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sum+=temp;
        nums.push_back(temp);
    }

    vector<vector<intmax_t>> dp = vector<vector<intmax_t>>(n,vector<intmax_t>(n,0));
    for(int i=0;i<n;i++)
    {
        dp[i][i] = nums[i];
    }

    for(int left=n-1;left>=0;left--)
    {
        for(int right=left;right<n;right++)
        {
            if(left==right)
            {
                dp[left][right] = nums[left];
            }
            else
            {
                dp[left][right] = max(nums[left]-dp[left+1][right],nums[right]-dp[left][right-1]);
            }
        }
    }
    cout<<(sum+dp.front().back())/2;
}