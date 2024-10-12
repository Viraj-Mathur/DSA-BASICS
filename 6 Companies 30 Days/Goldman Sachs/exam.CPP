#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6;  // Define the maximum possible N based on constraints
vector<long long> dp(MAX_N + 1, 0);  // To store number of ways to reach each island

// Function to solve for each test case, and it will handle precomputation on the first call
long long solve(int N) {
    // Static boolean to check if precomputation is already done
    static bool precomputed = false;
    
    // Perform precomputation only once
    if (!precomputed) {
        dp[1] = 1;  // There's only 1 way to reach Island 1 (itself)

        // Precompute the number of ways to reach each island using a sieve-like approach
        for (int i = 1; i <= MAX_N; ++i) {
            for (int j = 2 * i; j <= MAX_N; j += i) {
                dp[j] += dp[i];  // Add the ways to reach island i to its multiple j
            }
        }
        
        // Mark precomputation as done
        precomputed = true;
    }

    // Return the precomputed result for the given island N
    return dp[N];
}

int main() {
    int T;  // Number of test cases
    cin >> T;

    // Process each test case
    while (T--) {
        int N;
        cin >> N;
        cout << solve(N) << endl;  // Call the solve function and output the result
    }

    return 0;
}
