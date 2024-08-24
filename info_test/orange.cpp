#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Cell {
    int oranges; // oranges in the cell
    int row; // row number
    int col; // column number
};

// Function to calculate the shortest distance from each cell to the nearest lantern
vector<vector<int>> calculateLanternDistance(vector<vector<int>>& grid, int N, int M) {
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    queue<Cell> q;
    
    // Initialize the queue with all lantern positions and their distances
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 0) {
                q.push({0, i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    // Directions for moving up, down, left, right
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    // Perform BFS to calculate the shortest distance to the nearest lantern for each cell
    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int newRow = curr.row + dir[k];
            int newCol = curr.col + dir[k + 1];
            
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && dist[newRow][newCol] == INT_MAX) {
                dist[newRow][newCol] = dist[curr.row][curr.col] + 1;
                q.push({0, newRow, newCol});
            }
        }
    }
    
    return dist;
}

// Function to find the maximum profit path
int maxProfit(vector<vector<int>>& grid, int N, int M) {
    vector<vector<int>> lanternDist = calculateLanternDistance(grid, N, M);
    vector<vector<long long>> dp(N, vector<long long>(M, LLONG_MIN));
    
    dp[0][0] = grid[0][0]; // Starting point
    
    // Fill the DP table
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 && j == 0) continue; // Skip the starting point
            
            long long oranges = (grid[i][j] == 0) ? 0 : grid[i][j];
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + oranges);
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + oranges);
        }
    }
    
    // Calculate the profit
    long long maxProfit = dp[N-1][M-1];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            maxProfit -= lanternDist[i][j]; // Subtract the distance traveled by the dog
        }
    }
    
    return maxProfit;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
    
    cout << maxProfit(grid, N, M) << endl;
    
    return 0;
}