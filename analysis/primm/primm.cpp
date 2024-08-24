#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
using namespace std;

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

    const int numberOfNodes = int(cost.size());

    vector<pair<int,int>> tree(numberOfNodes-1);
    vector<int> near(numberOfNodes,INT_MAX);
    
    pair<int,int> edge = {0,0};

    int minEdgeCost = INT_MAX;

    for(int i=0;i<numberOfNodes;i++)
    {
        for(int j=i+1;j<numberOfNodes;j++)
        {
            if(cost[i][j]<minEdgeCost)
            {
                edge = {i,j};
                minEdgeCost = cost[i][j];
            }
        }
    }

    for(int i=0;i<near.size();i++)
    {
        if(cost[i][edge.first] < cost[i][edge.second])
        {
            near[i] = edge.first;
        }
        else near[i] = edge.second;
    }

    near[edge.first] = near[edge.second] = -1;

    tree.front() = edge;

    for(int i=1;i<tree.size();i++)
    {
        // find node with minimum edge cost 
        int k = -1;
        int mini = INT_MAX;
        for(int j=0;j<near.size();j++)
        {
            if(near[j]!=-1 && cost[j][near[j]]<mini)
            {
                mini = cost[j][near[j]];
                k = j;
            }
        }
        minEdgeCost+=cost[k][near[k]];
        tree[i] = {k,near[k]};
        near[k] = -1;

        for(int j=0;j<near.size();j++)
        {
            if(near[j] != -1 && cost[j][near[j]] > cost[j][k])
            {
                near[j] = k;
            }
        }

    }

    cout<<minEdgeCost;
}