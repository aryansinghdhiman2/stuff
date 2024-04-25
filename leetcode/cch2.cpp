#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int dfs(const vector<int>& coins,int amount,int number_of_coins,vector<int>& memo)
    {
        if(amount==0)
        {
            return number_of_coins;
        }
        if(amount < 0)
        {
            return -1;
        }
        if(memo[amount]!=INT_MIN)
        {
            return memo[amount];
        }

        int count = -1;
        int temp = -1;
        for(int i=coins.size()-1;i>=0;i--)
        {
            temp = dfs(coins,amount-coins[i],number_of_coins+1,memo);
            if(count==-1)
            {
                count=temp;
            }
            else if(temp != -1 && temp < count)
            {
                count=temp;
            }
        }
        memo[amount]=count;
        return count;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> memo(amount+1,INT_MAX);
        int count = dfs(coins,amount,0,memo);
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> v = {186,419,83,408};
    cout<<s.coinChange(v,6249);
    return 0;
}