#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n,maxPrice;
    cin>>n>>maxPrice;
    vector<int> prices;
    vector<int> pages;
    prices.reserve(n);
    pages.reserve(n);

    int temp=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        prices.push_back(temp);
    }
    
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        pages.push_back(temp);
    }
    

    vector<vector<int>> dp(n+1,vector<int>(maxPrice+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxPrice;j++)
        {
            if(prices[i-1]<=j)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-prices[i-1]]+pages[i-1]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp.back().back();
}