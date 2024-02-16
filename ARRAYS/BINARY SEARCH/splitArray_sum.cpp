/*
https://leetcode.com/problems/split-array-largest-sum/description/

Given an integer array nums and an integer k, split nums into k non-empty subarrays 
such that the largest sum of any subarray is minimized.

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
    int partitions(vector<int> &nums, int maxSum){
        int n = nums.size();
        int partit = 1;
        long long subArraySum = 0;
        for(int i=0;i<n;i++){
            if(subArraySum +nums[i] <=maxSum){
                // insert element to current subarray
                subArraySum +=nums[i];
            }
            else{
                // insert into next partitions
                partit++;
                subArraySum =nums[i];
            }
        }
        return partit;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        // now applying binary search
        while(low<=high){
            int mid = (low+high)/2;
            int partit = partitions(nums,mid);
            if(partit > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
        
    }
};

/*
accumulate(a.begin(), a.end(), 0):

    This function is used to calculate the sum of all elements in the range specified by the iterators a.begin() and a.end() in the container a.
    The third argument 0 is the initial value of the sum.
    */
    


int main(){
    
    return 0;
}