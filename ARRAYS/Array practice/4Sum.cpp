/*
4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

*/

// APPROACH: USING HASH MAPS AND POINTER TECHNIQUES ALSO USED SET TO STORE UNIQUE VALUES

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int newTarget = target - nums[i] - nums[j];
                int low = j+1, high = n-1;
                while(low<high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        set.insert({nums[i], nums[j], nums[low], nums[high]}); //set is used to store unique values
                        low++;
                        high--;
                    }
                }
            }
        }

        for(auto it:set){
            output.push_back(it);
        }
        return output;        
    }
};

int main(){
    
    return 0;
}