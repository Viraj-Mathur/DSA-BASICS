/*
https://leetcode.com/problems/house-robber/description/

PROBLEM STATEMENT : 
You are a professional robber planning to rob houses, the only constraint is that adjacent houses have security systems and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

WE HAVE TO ROB A HOUSE SUCH THAT WE HAVE DO NOT HAVE TO PICK ADJACENT HOUSES
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int f(int index, vector<int> &nums, vector<int> &dp){
        // base case
        if(index == 0) return nums[index]; //the current index is 0 means it's the first house so only one house to consider not to worry about adjacent houses therefore returns the value of the first house
        if(index < 0) return 0; //checks if the current index is negative,Since there are no more houses to rob beyond this point, the function returns 0

        if(dp[index]!=-1) return dp[index]; //Memoisation -> to check if already contains value at current index. The DP array is used to store the results of subproblems to avoid redundant calculations. If the value at the current index has already been calculated and stored in the dp array, there's no need to re-calculate it. The function directly returns the precalculated value from the dp array.

        int pick = nums[index] + f(index -2, nums, dp); // case 1 if one house is picked, "index - 2" because no adjacent is allowed i.e index-1 not possible
        int notPick = 0 + f(index-1, nums, dp); // second case if you decide not to rob the current house

        return dp[index] = max(pick, notPick);   // returns the maximum value
     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
        
    }
};


// Approach 2: Space Optimised O(1) -> AS index-1 and index-2 is only being used 
class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        // base cases
        int prev = nums[0]; // (index 0), as you start at the first house and have no adjacent houses to worry about. 
        int prev2 = 0; //Initialize prev2 to 0, as there is no house two places before the first house.

        for(int i=1;i<n;i++){ 
            int pick = nums[i]; 
            if(i>1){ // If i is greater than 1, add the maximum amount robbed up to two houses ago (prev2) with the current house (nums[i]) as you can't rob adjacent houses.
                pick += prev2; 
            }

            int notPick = 0 + prev; //if you decide not to rob the current house. In this case, the amount is the same as the maximum amount robbed up to the previous house (prev).

            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
        
    }
};
int main(){
    
    return 0;
}