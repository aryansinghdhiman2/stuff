#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int minMovesToZero(int N) {
    // Edge case for N = 0
    if (N == 0) return 0;

    queue<pair<int, int>> q;  // Queue to store the state and number of moves
    unordered_set<int> visited;  // Set to store visited states

    q.push({N, 0});
    visited.insert(N);

    while (!q.empty()) {
        auto [current, moves] = q.front();
        q.pop();

        // Possible next states
        int next1 = current - 1;
        int next2 = current / 2;
        int next3 = current / 3;

        // Check if we've reached zero
        if (next1 == 0 || next2 == 0 || next3 == 0) {
            return moves + 1;
        }

        // Push the next states if they haven't been visited
        if (visited.find(next1) == visited.end()) {
            q.push({next1, moves + 1});
            visited.insert(next1);
        }
        if (current % 2 == 0 && visited.find(next2) == visited.end()) {
            q.push({next2, moves + 1});
            visited.insert(next2);
        }
        if (current % 3 == 0 && visited.find(next3) == visited.end()) {
            q.push({next3, moves + 1});
            visited.insert(next3);
        }
    }

    return -1;  // Should never reach here
}

int main() {
    int N;
    cout << "Enter the number of soldiers: ";
    cin >> N;

    int result = minMovesToZero(N);
    cout << "Minimum moves to reduce army of size " << N << " to 0: " << result << endl;

    return 0;
}