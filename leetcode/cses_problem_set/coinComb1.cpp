#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> nums;
    nums.reserve(n);

    int temp=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }

    vector<intmax_t> dp(target+1,0);
    dp[0]=1;

    for(int i=1;i<int(dp.size());i++)
    {
        for(size_t j=0;j<nums.size();j++)
        {
            if(nums[j]<=i)
            {
                dp[i]+=dp[i-nums[j]];
            }
        }
        dp[i]=dp[i]%1000000007;
    }

    cout<<dp.back();
}