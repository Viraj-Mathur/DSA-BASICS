/*
leecode: https://leetcode.com/problems/kth-missing-positive-number/description/
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/

#include <bits/stdc++.h>
using namespace std;
/*
MATHEMATICAL LOGIC AFTER BASIC BINARY SEARCH:
    So, in the given array, the preceding neighbor of the kth missing number is vec[high]. 
    Now, we know, up to index ‘high’,
    the number of missing numbers = vec[high] - (high+1).
    But we want to go further and find the kth number. To extend our objective, we aim to find the kth number in the sequence. In order to determine the number of additional missing values required to reach the kth position, we can calculate this as
    more_missing_numbers = k - (vec[high] - (high+1)).
    Now, we will simply add more_missing_numbers to the preceding neighbor i.e. vec[high] to get the kth missing number.
    kth missing number = vec[high] + k - (vec[high] - (high+1))
            =  vec[high] + k - vec[high] + high + 1
            = k + high + 1.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;

            // Number of missing numbers up to index i = vec[i] - (i+1).
            // The given array, vec, is currently containing the number vec[i] whereas it should contain (i+1) if no numbers were missing. 
            // The difference between the current and the ideal element will give the result.
            int missing = arr[mid] - (mid+1);

            if(missing <k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }


        }
        return k+high+1;
        
    }
};

int main(){
    
    return 0;
}