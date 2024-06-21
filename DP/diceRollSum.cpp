#include <bits/stdc++.h>

using namespace std;

class Solution {
    const long long int MOD = 1000000007;

private: 
    // Approach 1 using recursion
    int solveUsingRecursion(int n, int k, int target) {
        // base cases
        if (n == 0 && target == 0) {
            return 1; // exactly zero dice and zero target sum
        }
        if (n == 0 || target < 0) {
            return 0; // no dice left or target sum became negative
        }

        // main cases
        long long int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = (ans + solveUsingRecursion(n - 1, k, target - i)) % MOD;
        }
        return ans;
    }

    // Approach 2 using memoization DP
    int solveUsingMemo(int n, int k, int target, vector<vector<long long int>>& dp) {
        // base cases
        if (n == 0 && target == 0) {
            return 1; // exactly zero dice and zero target sum
        }
        if (n == 0 || target < 0) {
            return 0; // no dice left or target sum became negative
        }

        // check if answer already solved or not
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        // main cases
        long long int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (target - i >= 0) { // handling edge case that target - i does not become negative
                ans = (ans + solveUsingMemo(n - 1, k, target - i, dp)) % MOD;
            }
        }

        // storing ans in DP array
        dp[n][target] = ans;
        return dp[n][target];
    }

// Tabulation approach
    int solveTab(int n,int k,int target){
        // step 1 : create dp array
        vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, 0));
        // observing base cases of top down
        dp[0][0] = 1;
        // step 3: reversing the flow of top down
        for (int index = 1; index <= n; index++) {
            for(int t = 1;t<=target;t++){
                dp[index][t] = 0; //initialising current cell of the table
                for(int face = 1;face<=k;face++){

                    if (t - face >= 0) { // handling edge case that target - i does not become negative
                        dp[index][t] = (dp[index][t] + dp[index-1][t-face]) % MOD;
                    }
                }

            }
        }
        return dp[n][target];

    }

// Approach 3: space optimised
    int spaceOptimised(int n,int k,int target){
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);

        // step 2: observing base cases
        prev[0] = 1;

        // step 3: reversing flow of top down
        for(int index = 1;index<=n;index++){
            for(int t = 1;t<=target;t++){
                long long int ans = 0;
                for(int i = 1;i<=k;i++){
                    long long int recAns = 0;
                    if(t - i >= 0){
                        recAns = prev[t-i];
                    }
                    ans = (ans%MOD + recAns%MOD)%MOD;
                    }
                    curr[t] = ans;
                }
                // Shift logic
                prev = curr;
        }
        return prev[target];

    }

public:
    int numRollsToTarget(int n, int k, int target) {
        // // Recursion solution (uncomment for testing)
        // return solveUsingRecursion(n, k, target);

        // // Top Down DP
        // // Step 1: create 2D DP array
        // vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));
        // return solveUsingMemo(n, k, target, dp);

        // // // Bottom up solution
        // return solveTab(n,k,target);

        // Space optimization solution
        int ans = spaceOptimised(n,k,target);
        return ans;
    }

    
};

int main() {
    Solution sol;
    cout << sol.numRollsToTarget(1, 6, 3) << endl; // Expected output: 1
    cout << sol.numRollsToTarget(2, 6, 7) << endl; // Expected output: 6
    cout << sol.numRollsToTarget(30, 30, 500) << endl; // Expected output: 222616187
    return 0;
}
