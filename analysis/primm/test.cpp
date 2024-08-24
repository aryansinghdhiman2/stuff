#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;


int main() {
    int number_of_nodes = 0;
    int number_of_edges = 0;
    cin>>number_of_nodes>>number_of_edges;
    vector<vector<int>> cost(number_of_nodes,vector<int>(number_of_nodes,INT_MAX));
    
    int sum_of_all_edges = 0;
    int u,v,lk;
    for(int i=0;i<number_of_edges;i++)
    {
        cin>>u>>v>>lk;
        cost[u-1][v-1] = cost[v-1][u-1] = lk;
        sum_of_all_edges+=lk;
    }
    
    pair<int,int> edge;
    int edgeSum = INT_MAX;
    for(int i=0;i<number_of_nodes;i++)
    {
        for(int j=i+1;j<number_of_nodes;j++)
        {
            if(cost[i][j]<edgeSum)
            {
                edgeSum = cost[i][j];
                edge = {i,j};
            }
        }
    }
    vector<int> near(number_of_nodes,0);
    for(int i=0;i<int(near.size());i++)
    {
        if(cost[i][edge.first] < cost[i][edge.second])
        {
            near[i] = edge.first;
        }
        else near[i] = edge.second;
    }
    
    near[edge.first] = near[edge.second] = -1;
    
    for(int j=1;j<number_of_nodes-1;j++)
    {
        int smallest_edge = -1;
        int smallest_cost = INT_MAX;
        for(int k=0;k<int(near.size());k++)
        {
            if(near[k]!=-1 && cost[k][near[k]]<smallest_cost)
            {
                smallest_cost = cost[k][near[k]];
                smallest_edge = k;
            }
        }
        
        edgeSum+=cost[smallest_edge][near[smallest_edge]];
        near[smallest_edge] = -1;
        
        for(int k=0;k<int(near.size());k++)
        {
            if(near[k]!=-1 && cost[k][near[k]] > cost[k][smallest_edge])
            {
                near[k] = smallest_edge;
            }
        }
        
    }
    
    int sum_of_removed = sum_of_all_edges - edgeSum;
    if(sum_of_removed<0) cout<<0;
    else cout<<sum_of_removed;
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
