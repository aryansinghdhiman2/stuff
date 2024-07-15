#include <vector>

using namespace std;


class UnionFind {
private:
    vector<int> root;
    vector<int> comp_size;
    int components;
public:
    UnionFind(const int n): root(n+1),comp_size(n+1),components(n)
    {
        for(int i=0;i<=n;i++)
        {
            this->root[i] = i;
            this->comp_size[i] = 1;
        }
    }

    int find(const int i)
    {
        if(this->root[i]==i)
        {
            return i;
        }
        else return this->root[i] = find(root[i]);
    }

    int _union(const int x,const int y)
    {
        int rootx = find(x);
        int rooty = find(y);

        if(rootx!=rooty)
        {
            if(this->comp_size[rootx]<this->comp_size[rooty])
            {
                this->root[rootx] = rooty;
                this->comp_size[rooty]+=this->comp_size[rootx];
            }
            else
            {
                this->root[rooty] = rootx;
                this->comp_size[rootx]+=this->comp_size[rooty];
            }

            components--;
            return 1;
        }
        else return 0;
    }

    bool connected()
    {
        return components==1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> edges) {
        UnionFind Alice(n);
        UnionFind Bob(n);

        int num_edges = 0;
        for(size_t i=0;i<edges.size();i++)
        {
            if(edges[i][0]==3)
            {
                num_edges+=(Alice._union(edges[i][1], edges[i][2]) | Bob._union(edges[i][1], edges[i][2]));
            }
        }

        for(size_t i=0;i<edges.size();i++)
        {
            if(edges[i][0]==1)
            {
                num_edges+=Alice._union(edges[i][1], edges[i][2]);
            }
            else if(edges[i][0]==2)
            {
                num_edges+=Bob._union(edges[i][1], edges[i][2]);
            }
        }

        if(Alice.connected() && Bob.connected())
        {
            return edges.size() - num_edges;
        }
        else return -1;
    }
};

int main()
{
    Solution().maxNumEdgesToRemove(12,{{3,1,2},{2,2,3},{3,1,4},{2,3,5},{1,2,6},{2,4,7},{3,3,8},{3,2,9},{2,1,10},{2,1,11},{1,11,12},{1,10,11},{2,5,9},{2,7,10},{2,4,12},{3,9,10},{1,6,9},{2,10,12},{1,2,5},{3,5,6},{1,7,11},{1,8,9},{1,1,11},{3,4,5},{1,5,9},{2,4,9},{1,8,11},{3,6,8},{1,8,10},{2,2,4},{2,3,8},{3,2,6},{3,10,11},{2,3,11},{3,5,9},{3,3,5},{2,6,11},{3,2,7},{1,5,11},{1,1,5},{2,9,10},{1,6,7},{3,2,3},{2,8,9},{3,2,8}});
}