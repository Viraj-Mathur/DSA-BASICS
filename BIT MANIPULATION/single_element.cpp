/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space

Input: nums = [4,1,2,1,2]
Output: 4

*/



#include <bits/stdc++.h>

using namespace std;


// Approach 1 : adding elements in a map along with its count
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp; 

        // Populate the unordered_map with the frequency of each number
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++; // Added missing semicolon
        }

        // Iterate through the unordered_map to find the single number
        for (auto it : mpp) {
            if (it.second == 1) {
                return it.first;
            }
        }
        
        return -1; // Added return statement to handle the case where no single number is found
    }
};


// Approach 2 : bit manipulation  - using XOR

// XOR with every number as a^a = 0  so repeated elements will become 0 and only single element will remain

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ nums[i];
    }
    return xorr;
        
    }
};

int main(){
    
    return 0;
}