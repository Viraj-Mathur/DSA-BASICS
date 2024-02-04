// 162. Find Peak Element
/*
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return 0; //if contain 0 element
        if(nums[0] > nums[1]) return 0; // if first elemet is peak
        if(nums[n-1] > nums[n-2]) return n-1; // if last element is peak

        // for rest binary search
        int low = 1; 
        int high = n-2;
        int ans = -1;
        while(low <=high){
            int mid = (low+high)/2;

            // if arr[mid] is peak
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                ans = mid;
                break;
            }
            // if left but in right
            if(nums[mid] > nums[mid-1]){
                low = mid+1;
            }

            // if right or mid but in left
            else{
                high = mid-1;
            }
        }

        return ans;
        
    }
};

int main(){
    
    return 0;
}