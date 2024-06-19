/*
416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

*/

#include <bits/stdc++.h>

using namespace std;

// using memoisation
class Solution {
private:
    bool memo(vector<int> &arr,int i,int sum,vector<vector<int>> &dp){
        if(i==0){
            return arr[i] == sum;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        if(sum==0){
            return true;
        }
        if(sum<0){
            return false;
        }

        bool ans = false;
        if(arr[i]<=sum){
            ans = memo(arr,i-1,sum-arr[i],dp);
        }
        bool b = memo(arr,i-1,sum,dp);
        return dp[i][sum] = ans || b;
    }
public:
    bool canPartition(vector<int>& nums) {
        // find the sum of array
        int sum = 0;
        for(int i : nums){
            sum += i;
        }

        // if odd than array cannot be divided into 2 subsets
        if(sum%2 !=0){
            return false;
        }
        sum = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return memo(nums,n-1,sum,dp);
        
    }
};

int main(){
    
    return 0;
}