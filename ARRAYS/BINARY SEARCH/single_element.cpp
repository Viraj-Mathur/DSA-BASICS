// Single Element in a Sorted Array
/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.
*/

#include <bits/stdc++.h>

using namespace std;

/*
    a ^ a = 0, XOR of two same numbers results in 0.
    a ^ 0 = a, XOR of a number with 0 always results in that number.
*/

class Solution {  // USING XOR - O(n)
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); //size of the array.
        int ans = 0;
        // XOR all the elements:
        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
            
        }
};

// SOLUTION 2 : USING BINARY SEARCH

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); //size of the array.
        if(n==1) return nums[0];
        if(nums[0]!= nums[1]) return nums[0];
        if(nums[n-1]!= nums[n-2]) return nums[n-1];

        int low = 1, high = n-2;
        while(low<=high){
            int mid = (low+high)/2;

            // if mid is a single element
            if(nums[mid]!= nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }

            // when left
            if((mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                // if first condition true that means that the single element is on the left side of the current mid index
                // if second condition is true that means that the single element is on the left side of the current mid index.
                // if one of these conditions is true, it implies that the single element is on the left side of the mid index
                low = mid+1;
            }
            else{
                high = mid-1; // means right side
            }
        }
        return -1;
    }
};






int main(){
    
    return 0;
}