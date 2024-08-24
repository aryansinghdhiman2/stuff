#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int number_of_coins = 0;
    cin>>number_of_coins;
    vector<int> coins;
    coins.reserve(number_of_coins);
    int temp;
    for(int i=0;i<number_of_coins;i++)
    {
        cin>>temp;
        coins.push_back(temp);
    }
    
    int maxVal = reduce(coins.begin(),coins.end());

    vector<vector<bool>> dp(number_of_coins+1,vector<bool>(maxVal+1,false));
    
    for(size_t i=1;i<=coins.size();i++)
    {
        for(int amount=1;amount<=maxVal;amount++)
        {
            if(coins[i-1]==amount)
            {
                dp[i][amount]=true;
            }
            else if(coins[i-1]<amount)
            {
                dp[i][amount] = dp[i-1][amount] || dp[i-1][amount-coins[i-1]];
            }
            else
            {
                dp[i][amount] = dp[i-1][amount];
            }
        }
    }

    vector<int> result;
    for(int i=1;i<=maxVal;i++)
    {
        if(dp.back()[i])
        {
            result.push_back(i);
        }
    }
    cout<<result.size()<<'\n';
    for(const int i:result)
    {
        cout<<i<<' ';
    }
    
}