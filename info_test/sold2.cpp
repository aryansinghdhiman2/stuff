#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> memo;

int reduce(const int n)
{
    if(n==1)
    {
        return 0;
    }

    if(memo[n]!=-1)
    {
        return memo[n];
    }

    int steps = INT_MAX;
    if((n % 3) == 0)
    {
        steps = min(1 + reduce(n/3),steps);
    }
    if((n % 2) == 0)
    {
        steps = min(1 + reduce(n / 2),steps);
    }

    steps = min(1 + reduce(n - 1),steps);

    memo[n] = steps;

    return steps;

}

int main()
{
    int n;
    cin>>n;
    memo = vector<int>(n+1,-1);
    cout<<reduce(n);
}