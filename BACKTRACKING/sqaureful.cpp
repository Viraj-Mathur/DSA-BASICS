/*
996. Number of Squareful Arrays

An array is squareful if the sum of every pair of adjacent elements is a perfect square.

Given an integer array nums, return the number of permutations of nums that are squareful.

Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].

 

Example 1:

Input: nums = [1,17,8]
Output: 2
Explanation: [1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: nums = [2,2,2]
Output: 1
 

Constraints:

1 <= nums.length <= 12
0 <= nums[i] <= 109

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isSquare(int a) {
        int root = sqrt(a);
        return (root * root == a);
    }

    void solve(vector<int>& nums, int index, int& count, set<vector<int>>& uniquePerms) {
        int n = nums.size();
        if (index >= n) {
            if (uniquePerms.find(nums) == uniquePerms.end()) {
                uniquePerms.insert(nums);
                count++;
            }
            return;
        }

        for (int i = index; i < n; i++) {
            if (i > index && nums[i] == nums[index]) continue; // Avoid duplicate permutations
            swap(nums[index], nums[i]);
            if (index == 0 || (index > 0 && isSquare(nums[index] + nums[index - 1]))) {
                solve(nums, index + 1, count, uniquePerms);
            }
            swap(nums[index], nums[i]); // Backtrack
        }
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        // using set to handle duplicate values
        
        int count = 0;
        set<vector<int>> uniquePerms;
        sort(nums.begin(), nums.end());
        solve(nums, 0, count, uniquePerms);
        return count;
    }
};

    // if (index == 0 || isSquare(nums[0] + nums[-1])) // index == 0 is true - 0 is done for the first case

int main(){
    
    return 0;
}