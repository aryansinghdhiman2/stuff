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

    vector<intmax_t> dp(target+1,-1);
    dp[0]=0;

    for(int i=1;i<int(dp.size());i++)
    {
        intmax_t coins = -1;
        for(size_t j=0;j<nums.size();j++)
        {
            if(nums[j]<=i && dp[i-nums[j]]!=-1)
            {
                if(coins==-1)
                {
                    coins=dp[i-nums[j]];
                }
                else coins = min(dp[i-nums[j]],coins);
            }
        }
        if(coins!=-1)
        {
            dp[i]=coins+1;
        }
    }

    cout<<dp.back();
}