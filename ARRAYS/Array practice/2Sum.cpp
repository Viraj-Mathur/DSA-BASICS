/*
2SUM
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

#include <bits/stdc++.h>

using namespace std;

// APPROACH 1: HASHING
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp; //map to strore input along with indices
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i]; //for earch i - indexs
            int moreNeed = target-num;
            if(mpp.find(moreNeed)!=mpp.end()){ //It checks if the calculated moreNeed value exists in the map mpp. If it does, it means the current element, along with the element at the found index in the map, adds up to the target. In that case, the method returns a vector containing the indices of these two elements.
                return {mpp[moreNeed], i};
            }
            mpp[num] = i;
        }

        return {-1,1};
        
    }
};

// APPROACH 2: TWO POINTER
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> numsWithIndex;

        for(int i=0;i<nums.size();i++){
            numsWithIndex.push_back({nums[i], i});  //with index
        }

        // sorting for 2 pointer approach
        sort(numsWithIndex.begin(), numsWithIndex.end());
        // initialise pointer
        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int currentSum = numsWithIndex[left].first + numsWithIndex[right].first;
            if(currentSum == target){
                // Return the original indices of the two elements
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            }
            else if(currentSum<target){
                left++;
            }
            else{
                right--;
            }
        }

        return {-1,1};
        
    }
};

int main(){
    
    return 0;
}