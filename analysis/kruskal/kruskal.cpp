#include <vector>
#include <climits>
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

int find(const vector<int>& parent,int k)
{
    if(parent[k]==-1)
    {
        return k;
    }
    else return find(parent,parent[k]);
}

inline void _union(vector<int>& parent,int i,int j)
{
    parent[j] = i;
}

int main()
{
    vector<vector<int>> cost = {{0,28,0,0,0,10,0},
                                {28,0,16,0,0,0,14},
                                {0,16,0,12,0,0,0},
                                {0,0,12,0,22,0,18},
                                {0,0,0,22,0,25,24},
                                {10,0,0,0,25,0,0},
                                {0,14,0,18,24,0,0}};

    for(int i=0;i<cost.size();i++)
    {
        for(int j=0;j<cost.size();j++)
        {
            if(cost[i][j]==0)
            {
                cost[i][j] = INT_MAX;
            }
        }
    }

    vector<array<int,3>> edges;
    for(int i=0;i<cost.size();i++)
    {
        for(int j=i+1;j<cost.size();j++)
        {
            if(cost[i][j]!=INT_MAX)
            {
                edges.push_back({cost[i][j],i,j});
            }
        }
    }

    sort(edges.begin(),edges.end());

    vector<array<int,3>> tree(cost.size()-1);
    vector<int> parent = vector<int>(cost.size(),-1);

    int t=0;
    int minCost = 0;
    for(int i=0;i<int(edges.size());i++)
    {
        if(t==tree.size()) break;

        int j = find(parent,edges[i][1]);
        int k = find(parent,edges[i][2]);

        if(j!=k)
        {
            tree[t] = edges[i];
            t++;
            minCost+=edges[i][0];
            _union(parent,edges[i][1],edges[i][2]);
        }
    }

    cout<<minCost<<'\n';
    for(const auto& e : tree)
    {
        cout<<e[0]<<' '<<e[1]<<' '<<e[2]<<'\n';
    }
}