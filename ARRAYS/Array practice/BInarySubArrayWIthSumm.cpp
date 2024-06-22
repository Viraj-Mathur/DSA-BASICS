#include <bits/stdc++.h>

using namespace std;

/*
930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

*/

// Approach: Using prefix Sum appraoch
/*
Why Prefix Sum : 
Prefix sum is indeed an excellent approach for solving this problem efficiently. 

Problem characteristics:

We're dealing with a binary array (0s and 1s).
We need to find subarrays with a specific sum.
We need to count all such subarrays.


How prefix sum helps:

It allows us to calculate the sum of any subarray in O(1) time.
It transforms the problem from finding subarrays with a specific sum to finding pairs of prefix sums with a specific difference.


Applying prefix sum to this problem:

We create a prefix sum array where each element represents the sum of all elements up to that index.
For a subarray to have a sum of goal, we need to find two indices i and j where:
prefixSum[j] - prefixSum[i] = goal


Efficient counting:

As we build the prefix sum array, we can count the occurrences of each prefix sum.
For each prefix sum, we check how many previous prefix sums would result in the desired goal when subtracted from the current prefix sum.




*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, prefixSum = 0;
        unordered_map<int,int>freq;
        freq[0] = 1;

        for(auto i:nums){
            prefixSum += i;

            if(freq.find(prefixSum - goal)!= freq.end()){
                ans += freq[prefixSum - goal];
            }
            freq[prefixSum]++;
        }
        
        return ans;
    }
};


int main(){
    
    return 0;
}


// Aother question with same appraoch but with negative numbers also in the constraints:

/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

