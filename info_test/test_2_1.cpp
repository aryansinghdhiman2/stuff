#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printLCS(const vector<vector<int>>& v,const vector<int>& arr,const vector<int>& other,const int i,const int j)
{
    if(i<=0 || j<=0)
    {
        return;
    }

    if(arr[i-1] == other[j-1])
    {
        printLCS(v,arr,other,i-1,j-1);
        cout<<arr[i-1]<<' ';
    }
    else
    {
        if(v[i-1][j] > v[i][j-1])
        {
            printLCS(v,arr,other,i-1,j);
        }
        else printLCS(v,arr,other,i,j-1);
    }

}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int> sorted_copy(arr.begin(),arr.end());
    sort(sorted_copy.begin(),sorted_copy.end(),[](const int& a,const int& b){
        if((((a & b) * 2) < (a | b)) && (a<b))
        {
            return true;
        }
        else return false;
    });

    for(const int& i : sorted_copy)
    {
        cout<<i<<' ';
    }
    cout<<'\n';

    // vector<vector<int>> lcs(n+1,vector<int>(n+1,0));

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(arr[i-1] == sorted_copy[j-1])
    //         {
    //             lcs[i][j] = lcs[i-1][j-1] + 1;
    //         }
    //         else
    //         {
    //             lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
    //         }
    //     }
    // }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         cout<<lcs[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    // printLCS(lcs,arr,sorted_copy,n,n);
}