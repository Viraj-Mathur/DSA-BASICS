// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>


using namespace std;

// SOLUTION USING UPPER AND LOWER BOUND FOR BINARY SEARCH

class Solution {

    private:
    int upper(vector<int> &arr, int n, int x){
        int low = 0, high = n-1, ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] >x){
                ans = mid;
            high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int lower(vector<int> &arr, int n, int x){
        int low = 0, high = n-1, ans = n;
        while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;

    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower(nums, n, target);
        if (lb == n || nums[lb] != target) return { -1, -1};
        int ub = upper(nums, n, target);
        return {lb, ub - 1};
        
    }
};


// SIMPLY IMPLEMENTING BINARY SEARCH



int main(){
    
    return 0;
}