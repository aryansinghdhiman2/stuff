#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int getBinLen(const int a)
{
    return floor(log2(a)) + 1;
}

bool checkPalindrome(const int a,const int n)
{
    bitset<32> b(a);

    for(int i=0;i<n/2;i++)
    {
        if(b[i]!=b[n-i-1])
        {
            return false;
        }
    }
    return true;
}

int counts(const int n,const int k)
{
    int count = 0;
    for(int i=0;getBinLen(i) <= n;i+=k)
    {
        if(checkPalindrome(i,n))
        {
            count = (count + 1) % 1000000007;
        }
    }
    return count;
}

int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    cout<<counts(n,k);
}