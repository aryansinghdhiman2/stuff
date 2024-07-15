#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> longestCommonSubsequence(const string& text1,const string& text2) {
    vector<vector<int>> c(text1.size()+1,vector<int>(text2.size()+1,0));

    for(size_t i=1;i<c.size();i++)
    {
        for(size_t j=1;j<c[i].size();j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
            {
                c[i][j] = max(c[i-1][j],c[i][j-1]);
            }
        }
    }

    return c;
}

string printLCS(const string& text1,const string& text2,const vector<vector<int>>& c,const int i,const int j)
{
    if(i==0 || j==0)
    {
        return "";
    }
    
    if(text1[i-1]==text2[j-1])
    {
        return printLCS(text1,text2,c,i-1,j-1) + text1[i-1];
    }
    else if(c[i-1][j]>=c[i][j-1])
    {
        return printLCS(text1,text2,c,i-1,j);
    }
    else
    {
        return printLCS(text1,text2,c,i,j-1);
    }
}

string printSCS(const string& text1,const string& text2,const vector<vector<int>>& c,const int i,const int j,const int n1,const int n2)
{
    if(i==0 || j==0)
    {
        string scs = string();
        if(i==0)
        {
            for(int k=j-1;k>=0;k--)
            {
                scs += text2[k];
            }
        }
        else
        {
            for(int k=i-1;k>=0;k--)
            {
                scs += text1[k];
            }
        }
        return scs;
    }
    
    if(text1[i-1]==text2[j-1])
    {
        string scs = printSCS(text1,text2,c,i-1,j-1,i,j) + text1[i-1];
        return scs;
    }
    else if(c[i-1][j]>=c[i][j-1])
    {
        string scs =  printSCS(text1,text2,c,i-1,j,n1,n2) + text1[i-1];
        return scs;
    }
    else
    {
        string scs =  printSCS(text1,text2,c,i,j-1,n1,n2) + text2[j-1];
        return scs;
    }
}

int main()
{
    string t1 = "bcacaaab";
    string t2 = "bbabaccc";
    auto c = longestCommonSubsequence(t1,t2);
    cout<<printLCS(t1,t2,c,t1.size()+1,t2.size()+1)<<endl;
    string s = printSCS(t1,t2,c,t1.size(),t2.size(),t1.size(),t2.size());
    cout<<s<<endl;
    return 0;
}