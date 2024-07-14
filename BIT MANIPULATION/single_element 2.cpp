#include <bits/stdc++.h>

using namespace std;

/*

137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

// Approach 1: same solution using map

// Approach 2 : using stimulation - TC: Nlogn + n/3

// sort the elements this will make all the repeated elements together
// then start with 2nd element and check previous if same then go forward 3 places and check prev element again if found if not same then it is the single element if all array traversed then the last element is the single elemnt

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i+=3){
            if(nums[i-1] !=nums[i]){
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};

// Approach 3
/*
take 3 buckets ones,twos and threes

nums[i] will go to ones if not in twos - (ones^nums[i])&~twos
nums[i] will go to twos if it is in ones
nums[i] will go to threes if it is in twos
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();

        int ones = 0;
        int twos = 0;

        for(int i=0;i<n;i++){
            ones = (ones^nums[i])&(~twos);
            twos = (twos^nums[i])&(~ones);
        }
        return ones;
        
    }
};

int main(){
    
    return 0;
}