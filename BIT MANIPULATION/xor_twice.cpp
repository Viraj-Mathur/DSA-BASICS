// 3158. Find the XOR of Numbers Which Appear Twice

/*
You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.

 

Example 1:

Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in nums is 1.

Example 2:

Input: nums = [1,2,3]

Output: 0

Explanation:

No number appears twice in nums.

Example 3:

Input: nums = [1,2,2,1]

Output: 3

Explanation:

Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.

 


*/
#include <bits/stdc++.h>

using namespace std;

// approach 1 :
// find the numbers that were repeating (By XOR). Then,stor those numbers in the ans array. Finally , XOR the elements of the ans array.
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i]^nums[j]) == 0){ // if xoring of 2 nos is 0 that means numbers are same
                    ans.push_back(nums[i]);
                }

            }
        }

        int k = ans.size();
        int result = 0;
        for(int i=0;i<k;i++){
            result = result^ans[i];
        }
        return result;
    }
};


// Approach 2 : using map
// create map and store the elements along with their counts if the count is greater or equal to 2 then xor those 

int duplicateNumbersXOR(vector<int>& nums){

    int n = nums.size();

    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }

    int ans = 0;
    for(auto i:mpp){
        if (i.second>=2){
            ans^=i.first;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}