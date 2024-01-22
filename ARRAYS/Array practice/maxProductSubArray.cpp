// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

#include <bits/stdc++.h>

using namespace std;


int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1, suffix = 0 ;
        // prefix and suffix are used to tackle negativ numbers
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n-i-1];
            ans = max(ans, max(prefix,suffix));
        } 

        return ans;
        
    }
};




int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

int main(){
    
    return 0;
}