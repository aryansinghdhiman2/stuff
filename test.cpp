#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        this->m = heights.size();
        this->n = heights.at(0).size();

        this->visited.resize(this->m);
        
        for(unsigned k=0;k<this->visited.size();k++)
        {
            this->visited.at(k).resize(this->n);
        }
        vector<vector<int>> result;

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                reachability status = searchGrid(heights,coordinates(i,j));
                updateReachability(coordinates(i,j),status);
                if(status==both)
                {
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
private:
    struct coordinates
    {
        int i,j;
        coordinates(int a,int b):i(a),j(b){}
    };
    int m;
    int n;
    enum reachability {unvisited,none,pacific,atlantic,both};
    vector<vector<reachability>> visited;
    void updateReachability(coordinates coordinate,reachability new_status)
    {
        reachability& current_status = this->visited.at(coordinate.i).at(coordinate.j);
        if(new_status == both)
            current_status = both;
        if(current_status == pacific && new_status == atlantic)
            current_status = both;
        else if(current_status == atlantic && new_status == pacific)
            current_status = both;
        else if((current_status == none || current_status == unvisited) && (new_status == atlantic || new_status == pacific || new_status == both))
            current_status = new_status;
    }
    inline bool sameHeight(const vector<vector<int>>& heights,const coordinates& a,const coordinates& b)
    {
        if( a.i == -1 || b.i == -1 || a.i == m || b.i == m || a.j == -1 || b.j == -1 || a.j == n || b.j == n)
            return false;
        if(heights.at(a.i).at(a.j) == heights.at(b.i).at(b.j))
            return true;
        return false;
    }
    bool shouldTraverse(const vector<vector<int>>& heights,const coordinates& current,const coordinates& to_add)
    {
        if(to_add.i == -1 || to_add.j == -1)
        {
            updateReachability(current,pacific);
            return false;
        }
        if(to_add.i == this->m || to_add.j == this->n)
        {;
            updateReachability(current,atlantic);
            return false;
        }
        if(heights.at(to_add.i).at(to_add.j) <= heights.at(current.i).at(current.j))
        {
            return true;
        }
        return false;
    }
    reachability searchGrid(const vector<vector<int>>& heights,coordinates start)
    {
        int& i = start.i;
        int& j = start.j;
        if(this->visited.at(i).at(j)!=unvisited)
            return this->visited.at(i).at(j);
        else
            this->visited.at(i).at(j)=none;

        coordinates north(i-1,j);
        if(shouldTraverse(heights,start,north))
        {
            reachability status = searchGrid(heights,north);
            updateReachability(start,status);
        }

        coordinates east(i,j+1);
        if(shouldTraverse(heights,start,east))
        {
            reachability status = searchGrid(heights,east);
            updateReachability(start,status);
        }

        coordinates south(i+1,j);
        if(shouldTraverse(heights,start,south))
        {
            reachability status = searchGrid(heights,south);
            updateReachability(start,status);
        }

        coordinates west(i,j-1);
        if(shouldTraverse(heights,start,west))
        {
            reachability status = searchGrid(heights,west);
            updateReachability(start,status);
        }

        if(sameHeight(heights,start,north))
        {
            updateReachability(start,visited.at(north.i).at(north.j));
            updateReachability(north,visited.at(start.i).at(start.j));
        }
        if(sameHeight(heights,start,east))
        {
            updateReachability(start,visited.at(east.i).at(east.j));
            updateReachability(east,visited.at(start.i).at(start.j));
        }
        if(sameHeight(heights,start,south))
        {
            updateReachability(start,visited.at(south.i).at(south.j));
            updateReachability(south,visited.at(start.i).at(start.j));
        }
        if(sameHeight(heights,start,west))
        {
            updateReachability(start,visited.at(west.i).at(west.j));
            updateReachability(west,visited.at(start.i).at(start.j));
        }
        return visited.at(start.i).at(start.j);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{12,9,18,4,1,4,8,8,9,7,15,17,2,17,17},{1,0,17,15,11,10,10,7,8,1,16,10,11,14,19},{0,19,7,4,9,6,4,5,4,7,0,13,3,16,6},{18,18,10,16,12,13,3,6,11,5,7,5,16,15,19},{0,9,16,15,17,11,1,1,17,14,2,11,18,0,6},{14,18,2,10,2,0,8,0,11,10,4,16,1,10,19},{5,16,3,4,5,10,5,14,15,15,18,0,15,12,15},{4,8,8,14,18,6,15,9,18,6,16,12,14,7,18},{9,13,16,15,5,9,16,18,8,0,18,7,10,10,13},{5,0,8,9,16,2,8,5,5,3,14,12,4,19,19},{6,13,10,5,0,15,9,3,8,13,6,3,12,17,16},{9,18,3,13,10,1,12,6,19,11,6,13,17,14,1},{19,2,10,15,11,13,16,3,14,6,9,7,17,6,11},{14,14,3,1,14,17,5,19,7,2,12,0,8,0,13},{7,14,11,4,6,3,15,0,17,5,18,7,8,18,8},{8,0,4,15,19,11,9,1,16,12,17,18,1,1,3},{3,2,1,11,9,19,10,10,12,1,19,9,7,5,8},{12,17,10,11,13,15,14,3,5,12,9,16,10,6,2},{1,17,6,18,2,8,16,7,6,16,18,14,2,5,19},{1,17,13,0,13,15,3,14,3,9,18,7,2,2,19},{3,14,4,12,3,8,19,9,0,11,7,1,14,1,13},{6,9,14,3,2,10,7,1,12,3,7,1,15,1,13},{0,18,19,5,14,0,12,4,19,11,13,19,12,16,4},{19,6,13,9,9,15,7,19,5,5,11,12,13,8,1},{7,4,4,1,15,4,12,18,1,1,8,16,19,16,1},{10,15,16,11,1,11,17,8,12,14,19,19,0,8,5},{0,8,8,8,7,19,3,6,9,10,11,9,12,2,2},{9,11,14,12,16,13,18,14,2,14,0,12,9,11,0},{3,16,0,15,1,9,1,0,12,3,10,12,5,18,4},{12,6,18,12,9,2,7,19,4,16,17,9,12,4,10}};

    auto result = s.pacificAtlantic(v);
    for(const vector<int>& a : result)
    {
        for(const int& i : a)
        {
            cout<<i<<' ';
        }
        cout<<'\n';
    }

    return 0;
}