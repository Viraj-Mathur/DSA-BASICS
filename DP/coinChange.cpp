class Solution {
private:
    // Top-down (memoization) approach
    int solveTopDown(vector<int>& coins, int amount, vector<int>& dp) {
        // Base cases
        if (amount == 0) {
            return 0;  // No coins needed for zero amount
        }
        if (amount < 0) {
            return INT_MAX;  // Invalid case, return maximum value
        }
        
        // Check if answer already exists in dp table
        if (dp[amount] != -1) {
            return dp[amount];
        }
        
        // Try all possible coins
        int mini = INT_MAX;
        for (int coin : coins) {
            int subproblem = solveTopDown(coins, amount - coin, dp);
            
            // Update minimum if a valid solution is found
            if (subproblem != INT_MAX) {
                mini = min(mini, 1 + subproblem);
            }
        }
        
        // Store result in dp table and return
        dp[amount] = mini;
        return mini;
    }

    // use bottom up tabulation approach
    int bottomUp(vector<int>& coins, int amount) {
    // Step 1: Create DP array
    // Initialize with INT_MAX to represent "impossible" states
    vector<int> dp(amount + 1, INT_MAX);
    
    // Step 2: Set base case
    // 0 coins needed to make amount 0
    dp[0] = 0;
    
    // Step 3: Fill the DP table iteratively
    for (int i = 1; i <= amount; i++) {
        // For each amount, try all coin denominations
        for (int j = 0; j < coins.size(); j++) {
            // Check if the coin can be used (not larger than current amount)
            // and if a valid solution exists for the remaining amount
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                // Calculate the number of coins needed if we use this coin
                int ans = dp[i - coins[j]];
                // Update dp[i] with the minimum of current value and new calculation
                dp[i] = min(dp[i], 1 + ans);
            }
        }
    }
    
    // Return the minimum number of coins needed for the target amount
    // If dp[amount] is still INT_MAX, it means no solution was found
    return dp[amount];
}

public:
    int coinChange(vector<int>& coins, int amount) {
    //     // Initialize dp table with -1 (unprocessed states)
    //     vector<int> dp(amount + 1, -1);
        
    //     int ans = solveTopDown(coins, amount, dp);
        
    //     // Return -1 if no valid solution found
    //     if(ans == INT_MAX){
    //         return -1;
    //     }
    //     else{
    //         return ans;
    //     }
    // }
    int ans = bottomUp(coins,amount);
    if(ans == INT_MAX) 
        return -1;
    return ans;
    }
};
