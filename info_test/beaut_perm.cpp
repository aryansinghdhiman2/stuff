#include <iostream>
#include <vector>

using namespace std;

vector<int> p;

void getSum(const vector<vector<char>>& arrows,const vector<int>& a,const int i,const int j)
{
    if(i==-1 or j==-1)
    {
        return;
    }
        
    if(arrows[i][j]=='d')
    {
        getSum(arrows,a,i-1,j-1);
        p.push_back(a[i-1]);
    }
        
    else if(arrows[i][j]=='u')
    {
        getSum(arrows,a,i-1,j);
    }
        
    else
        getSum(arrows,a,i,j-1);
}

vector<vector<char>> longestCommonSubsequence(vector<int>& a, vector<int>& b) {
    vector<vector<int>> c(a.size()+1,vector<int>(b.size()+1,0));
    vector<vector<char>> arrows(a.size()+1,vector<char>(b.size()+1,'u'));

    for(size_t i=1;i<c.size();i++)
    {
        for(size_t j=1;j<c[i].size();j++)
        {
            if(a[i-1]==b[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                arrows[i][j] = 'd';
            }
            else if(c[i-1][j] > c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                arrows[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j-1];
                arrows[i][j] = 'l';
            }
        }
    }

    return arrows;
}

int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<int> a;
    for(int i=1;i<=m;i++)
    {
        a.push_back(i);
    }
    vector<int> b;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        b.push_back(temp);
    }

    auto c= longestCommonSubsequence(a,b);
    getSum(c,a,m,n);
    long long sum=0;
    for(size_t i=0;i<p.size();i++)
    {
        sum+=(p[i] * (i+1)) % (1000000007);
    }
    cout<<sum;
}