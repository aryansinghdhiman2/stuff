#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N; // Read the number of employees
    
    vector<int> distances(N);
    
    // Read the distances
    for (int i = 0; i < N; ++i) {
        cin >> distances[i];
    }
    
    int start, end;
    cin >> start; // Read the start of the range
    cin >> end;   // Read the end of the range
    
    bool found = false;
    
    // Iterate through distances and print those within the range
    for (int i = 0; i < N; ++i) {
        if (abs(distances[i]) >= start && abs(distances[i]) < end) {
            if (found) {
                cout << " ";
            }
            cout << distances[i];
            found = true;
        }
    }
    
    // If no distances are found in the range, print -1
    if (!found) {
        cout << "-1";
    }
    
    cout << endl; // Print a newline character at the end

    return 0;
}