#include <bits/stdc++.h>

using namespace std;

/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // as we have to return ans in list make it as set to remove duplcasy
        set<vector<int>> ans;
        int n = nums.size();
        int subsets = 1<<n; // total number of subsets

        // Sort the input to handle duplicates
        sort(nums.begin(), nums.end());

        for(int i=0; i<subsets; i++){
            vector<int> subs;
            for(int j=0; j<n; j++){ // corrected loop condition from i<n to j<n
                if(i & (1<<j)) subs.push_back(nums[j]); // if there is 1, return its index
            }
            ans.insert(subs); // insert into set
        }

        // Convert set to vector
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    
    }
};

int main(){
    
    return 0;
}