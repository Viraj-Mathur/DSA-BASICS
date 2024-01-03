/*
216. Combination Sum III
https://leetcode.com/problems/combination-sum-iii/description/
*/

/*
INTUITION:
If k becomes 0, it checks whether the current sum equals the target sum (n). 
If true, the current combination is sorted and added to the result vector ans. If k is not 0, it enters a loop 
to iterate through elements in the array from the current starting index (st). For each element, it adds 
the element to the current combination (curr) and increments the sum. The recursive call is made with 
updated parameters, including a reduced value of k and an updated starting index (i+1).
After the recursive call, it backtracks by subtracting the element from the sum and removing 
the last element from the current combination (op.pop_back())
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    void recurse(vector<vector<int>>&ans, vector<int>&curr, int st, int k, int n, int &sum, int arr[]){
        if (k == 0){
            if(sum == n){
                sort(curr.begin(),curr.end());
                ans.push_back(curr);
            }
            return;
        }
        for(int i=st;i<9;i++){
            sum = sum+arr[i];
            curr.push_back(arr[i]);
            recurse(ans, curr, i+1,k-1,n,sum,arr);
            sum = sum-arr[i];
            curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        int arr[9] = {1,2,3,4,5,6,7,8,9};
        vector<int>curr;
        int st = 0;
        int sum = 0;
        recurse(ans,curr,st,k,n,sum,arr);
        return ans;
        
    }
};

int main(){
    
    return 0;
}