/*
213. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent 
houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob 
tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

*/

class Solution {
private:
    // Recursive function with memoization
    int memo(vector<int>& nums, int start, int end, vector<int>& dp) {
        // Base case: if we've gone past the start index
        if (end < start) {
            return 0;
        }
        
        // If we've already calculated this subproblem, return the stored result
        if (dp[end] != -1) {
            return dp[end];
        }
        
        // Option 1: Rob the current house
        int pick = nums[end];
        // If there are at least 2 houses between this one and the start,
        // we can also rob the house two steps back
        if (end >= start + 2) {
            pick += memo(nums, start, end - 2, dp);
        }
        
        // Option 2: Skip the current house
        int not_pick = memo(nums, start, end - 1, dp);
        
        // Store and return the maximum of the two options
        return dp[end] = max(pick, not_pick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: if there's only one house, rob it
        if (n == 1) {
            return nums[0];
        }
        
        // Initialize two DP arrays for two scenarios
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        
        // Scenario 1: Rob houses from index 1 to n-1 (exclude first house)
        int rob_second_to_last = memo(nums, 1, n - 1, dp1);
        
        // Scenario 2: Rob houses from index 0 to n-2 (exclude last house)
        int rob_first_to_second_last = memo(nums, 0, n - 2, dp2);
        
        // Return the maximum of the two scenarios
        return max(rob_second_to_last, rob_first_to_second_last);
    }
};
