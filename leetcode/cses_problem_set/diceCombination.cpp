#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    int n=0;
    cin>>n;

    vector<uintmax_t> dp(n+1,0);
    dp[0] = 1;

    for(size_t i=1;i<dp.size();i++)
    {
        for(uintmax_t dice=1;dice<=6;dice++)
        {
            if(dice<=i)
            {
                dp[i] += dp[i-dice];
            }        
        }
        dp[i] = dp[i] % 1000000007;
    }

    cout<<dp.back();
    return 0;
}