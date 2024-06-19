#include <bits/stdc++.h>

using namespace std;

/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. Since the answer can be large return it modulo 109 + 7.

Example 1:

Input:
n = 3
k = 2 
Output: 6
Explanation: 
Let the 2 colours be 'R' and 'B'.
We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR
Example 2:

Input:
n = 2
k = 4 
Output: 16
Explanation: 
After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16
Your Task:
Since, this is a function problem. You don't need to take any input or print anything, as it is already accomplished by the driver code. You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted (modulo 109 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ 105
*/

// Approach 1 : using memoisation dp
class Solution {
private:
    long long solveMemo(int n, int k, vector<long long>& dp) {
        const int MOD = 1e9 + 7;
        if (n == 1) {
            return k;
        }
        if (n == 2) {
            return (long long)k * k % MOD;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        /*
            for n=4 if last 2 same picked then recursion call: countWays(n-2, k) * (k-1)
            if last 2 not same picked then recursion call: countWays(n-1, k) * (k-1)
            return ans = same + not same
        */

        dp[n] = ((solveMemo(n - 2, k, dp) + solveMemo(n - 1, k, dp)) * (k - 1)) % MOD;
        return dp[n];
    }
public:
    long long countWays(int n, int k) {
        if (n == 0) return 0;
        vector<long long> dp(n + 1, -1);
        return solveMemo(n, k, dp);
    }
};

// Approach 2 : using tabulation
long long solveTab(int n, int k){
    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] =  (long long)k * k % MOD;

    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-2] + dp[i-1])*((k - 1) % MOD);
    }
    return dp[n];
}

// space optimised
int solveSO(int n, int k){
    // only previous 2 results are needed
    int prev2 = k;
    int prev1 = (k+k*(k-1));

    for(int i=3;i<=n;i++){
        int curr = (prev2 + prev1)*(k-1);

        // important step
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// gfg accepted code
class Solution {
public:
    long long countWays(int n, int k) {
        const int MOD = 1e9 + 7;
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return (long long)k * k % MOD;

        // dp[i] will store the number of ways to paint i posts
        long long dp1 = k;
        long long dp2 = (long long)k * k % MOD;

        for (int i = 3; i <= n; ++i) {
            long long current = (dp1 * (k - 1) + dp2 * (k - 1)) % MOD;
            dp1 = dp2;
            dp2 = current;
        }

        return dp2;
    }
};




int main(){
    
    return 0;
}