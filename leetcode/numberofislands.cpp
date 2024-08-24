#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int number_of_islands = 0;
        this->m = grid.size();
        this->n = grid.at(0).size();


        this->visited.resize(m);
        for(int i=0;i<this->m;i++)
        {
            this->visited.at(i).resize(n);
        }
        for(int i=0;i<this->m;i++)
        {
            for(int j=0;j<this->n;j++)
            {
                if(grid.at(i).at(j)=='0' or this->visited.at(i).at(j)==true)
                    continue;
                else
                {
                    ++number_of_islands;
                    findBoundaries(grid,i,j);
                }
            }
        }

        return number_of_islands;
    }
private:
    int m,n;
    vector<vector<bool>> visited;
    struct coordinates {
        coordinates(int a,int b):i(a),j(b){}
        int i;
        int j;
    };
    bool withinGrid(coordinates coordinate)
    {
        if(coordinate.i < 0 or coordinate.j < 0 or coordinate.i >= m or coordinate.j >= n)
            return false;
        else return true;
    }
    void findBoundaries(const vector<vector<char>>& grid,int i,int j)
    {
        visited.at(i).at(j) = true;
        coordinates north(i-1,j);
        coordinates east(i,j+1);
        coordinates south(i+1,j);
        coordinates west(i,j-1);

        if(withinGrid(north) && !visited.at(north.i).at(north.j) && grid.at(north.i).at(north.j)=='1')
        {
            findBoundaries(grid,north.i,north.j);
        }

        if(withinGrid(east) && !visited.at(east.i).at(east.j) && grid.at(east.i).at(east.j)=='1')
        {
            findBoundaries(grid,east.i,east.j);
        }

        if(withinGrid(south) && !visited.at(south.i).at(south.j) && grid.at(south.i).at(south.j)=='1')
        {
            findBoundaries(grid,south.i,south.j);
        }

        if(withinGrid(west) && !visited.at(west.i).at(west.j) && grid.at(west.i).at(west.j)=='1')
        {
            findBoundaries(grid,west.i,west.j);
        }
    }
};


int main()
{
    Solution s;
    vector<vector<char>> inp = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout<<s.numIslands(inp);

}