#include <iostream>
#include <vector>
#include <cstdint>

#define MOD_VAL 1000000007

using namespace std;

int main()
{
    int n;
    cin>>n;

    intmax_t fullSum = (((n)*(n+1))/2);
    if((fullSum%2)!=0) 
    {
        cout<<0;
        return 0;
    }

    int subSetSum = fullSum/2;

    vector<vector<intmax_t>> dp(n,vector<intmax_t>(subSetSum+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=subSetSum;j++)
        {
            if(i<=j)
            {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-i]) % MOD_VAL;
            }
            else dp[i][j] = (dp[i-1][j]) % MOD_VAL;
        }
    }

    cout<<(dp.back().back() % MOD_VAL);

    
}