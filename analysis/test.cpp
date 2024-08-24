#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
using namespace std;

int find(const vector<intmax_t>& parent,const intmax_t k)
{
    if(parent[k]==-1)
    {
        return k;
    }
    else return find(parent,parent[k]);
}

inline void _union(vector<intmax_t>& parent,const intmax_t j,const intmax_t k)
{
    intmax_t u = find(parent,j);
    intmax_t v = find(parent,k);
    
    if(u!=v)
    {
        parent[u] = v;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int numNodes,numEdges;
    cin>>numNodes>>numEdges;
    
    vector<array<intmax_t,3>> edges(numEdges);
    
    intmax_t u,v,lk;
    for(intmax_t i=0;i<numEdges;i++)
    {
        cin>>u>>v>>lk;
        edges[i] = {lk,u-1,v-1};
    }
    sort(edges.begin(),edges.end());
    
    vector<intmax_t> parent(numNodes,-1);
    intmax_t removed_cost = 0;
    for(size_t i=0;i<(edges.size());i++)
    {
        intmax_t j = find(parent,edges[i][1]);
        intmax_t k = find(parent,edges[i][2]);
        
        if(j!=k)
        {
            _union(parent,edges[i][1],edges[i][2]);
        }
        else if(edges[i][0]<=0)
        {
            continue;
        }
        else
        {
            removed_cost += edges[i][0];
        }
    }
    cout<<removed_cost;
    return 0;
}
