#include <iostream>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;

unordered_map<int,int> memo;

int helper(int target)
{
    if(target==0)
    {
        return 0;
    }
    
    if(memo.count(target)!=0)
    {
        return memo[target];
    }
    int numberOfDigits = int(log10(target))+1;
    int numberOfSteps = INT_MAX;
    for(int i=0;i<numberOfDigits;i++)
    {
        int digit = (target / int(pow(10,i))) % 10;
        if(digit!=0)
        {
            numberOfSteps=min(numberOfSteps,helper(target-digit));
        }
    }

    memo[target]=numberOfSteps+1;
    return numberOfSteps+1;

}

int main()
{
    int n;
    cin>>n;
    cout<<helper(n);
}