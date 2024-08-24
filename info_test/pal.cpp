#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to convert binary vector to integer
int binaryToInt(const vector<int>& bits) {
    int num = 0;
    for (int bit : bits) {
        num = (num << 1) | bit;
    }
    return num;
}

// Function to generate palindromic binary numbers of given length
void generatePalindromes(int len, int K, int& count) {
    vector<int> bits(len);
    int half = (len + 1) / 2;  // Half length

    // Iterate over all possible first halves
    for (int i = 0; i < (1 << half); ++i) {
        // Set the first half bits
        for (int j = 0; j < half; ++j) {
            bits[j] = (i >> j) & 1;
        }
        // Mirror the first half to the second half
        for (int j = 0; j < len / 2; ++j) {
            bits[len - 1 - j] = bits[j];
        }

        // Convert to integer and check divisibility
        int num = binaryToInt(bits);
        if (num != 0 && num % K == 0) {
            count = (count + 1) % 107;
        }
    }
}

// Function to count palindromic binary numbers of at most N bits divisible by K
int countPalindromicDivisibles(int N, int K) {
    int count = 0;
    for (int len = 1; len <= N; ++len) {
        generatePalindromes(len, K, count);
    }
    return count;
}

int main() {
    int N, K;
    cout << "Enter N (max bits): ";
    cin >> N;
    cout << "Enter K (divisor): ";
    cin >> K;

    int result = countPalindromicDivisibles(N, K);
    cout << "Total palindromic integers divisible by " << K << " is: " << result << endl;

    return 0;
}