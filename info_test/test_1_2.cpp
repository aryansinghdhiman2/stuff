#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> memo;
int n;
int k;

//gives number of permutations after val_placed has been placed at i
int waysPlaced(const int val_placed,const int i)
{
    // Can't place number greater than n
    if(val_placed > n)
    {
        return 0;
    }

    //Array exhausted
    if(i==k-1)
    {
        return 1;
    }

    if(memo[val_placed][i]!=INT_MIN)
    {
        return memo[val_placed][i];
    }

    int ways = 0;
    int j=1;
    while(j * val_placed <= n)
    {
        ways+=waysPlaced(j*val_placed,i+1);
        j++;
    }
    memo[val_placed][i] = ways;
    return ways;
}

int main()
{
    cin>>n;
    cin>>k;

    memo = vector<vector<int>>(n+1,vector<int>(k,INT_MIN));

    int ways = 0;
    for(int num = 1;num<=n;num++)
    {
        ways+=waysPlaced(num,0);
    }

    cout<<ways;

}