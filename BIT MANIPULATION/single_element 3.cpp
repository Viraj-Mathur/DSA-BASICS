/*
260. Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

#include <bits/stdc++.h>

using namespace std;

// Approach 1 : using maps : push elements and their frequency in a map and return those elements which have frequency of 1
// TC: O(n log m)

// as using external data structure we need to optimise it

// Approach 2 :using bit masking
class Solution1 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long res = 0; // Using long to handle overflow
        int n = nums.size();
        for(int i = 0; i < n; i++){
            res = res ^ nums[i];
        }

        // Using mask to find a differing bit
        long mask = res & (-res);

        // Getting the first number
        int first = 0;
        for(int i = 0; i < n; i++){
            if((mask & nums[i]) != 0){
                first = first ^ nums[i];
            }
        }

        // Getting the second number
        int second = res ^ first;
        
        return {first, second};
    }
};

int main(){
    vector<int> nums = {1, 2, 1, 3, 2, -2147483648};
    Solution1 sol;
    vector<int> result = sol.singleNumber(nums);
    
    // Print the result to verify correctness
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
