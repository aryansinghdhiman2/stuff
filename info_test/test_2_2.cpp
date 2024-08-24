#include <vector>
#include <iostream>
#include <array>
#include <climits>
#include <cstdint>

using namespace std;

int main()
{
    int rows = 0;
    cin>>rows;


    vector<array<int,2>> grid(rows);
    for(int i=0;i<rows;i++)
    {   
        cin>>grid[i][0]>>grid[i][1];
    }

    vector<array<int,2>> pathSum(grid.begin(),grid.end());

    for(int row = rows-2;row>=0;row--)
    {
        for(int j = 0;j<2;j++)
        {
            int temp = INT_MIN;

            if(grid[row][j] < grid[row+1][0])
            {
                temp = max(temp,pathSum[row+1][0]);
            }

            if(grid[row][j] < grid[row+1][1])
            {
                temp = max(temp,pathSum[row+1][1]);
            }

            if(temp!=INT_MIN)
            {
                pathSum[row][j] = temp + grid[row][j];
            }
        }
    }

    cout<<max(pathSum.front().front(),pathSum.front().back());
}