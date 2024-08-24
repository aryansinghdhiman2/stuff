#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int maxWidth,MaxHeight;
    cin>>maxWidth>>MaxHeight;

    vector<vector<int>> dp(maxWidth+1,vector<int>(MaxHeight+1,0));
    
    for(int w=1;w<=maxWidth;w++)
    {
        for(int h=1;h<=MaxHeight;h++)
        {
            if(w==h)
            {
                continue;
            }
            int cuts = INT_MAX;
            if(w!=1)
            {
                for(int k=1;k<w;k++)
                {
                    cuts = min(cuts,dp[k][h]+dp[w-k][h]+1);
                }
            }

            if(h!=1)
            {
                for(int k=1;k<h;k++)
                {
                    cuts = min(cuts,dp[w][k]+dp[w][h-k]+1);
                }
            }
            if(w!=1 || h!=1)
            {
                dp[w][h] = cuts;
            }
        }
    }

    cout<<dp.back().back();


}