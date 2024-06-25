// 1130. Minimum Cost Tree From Leaf Values

#include <bits/stdc++.h>

using namespace std;




 // Intuition -> there are various combinations of trees possible 
    
    // We have to take every possible  combination of trees 
    
    // Now creating binary tree is very hectic
    
    // What we will do is , we will recursively do the calculations 
    /*
    
 We need to find the best way to group these numbers into pairs and multiply them to minimize the total sum.

It is classical problem of Merge interval patterns.  

We start with a function solve that takes the input array, two indices, and a map for storing maximum values of subarrays. This function forms the core of our solution.

In solve, we initially check if there are elements to consider. If not, we return 0 as there are no non-leaf nodes.


We explore various split points to compute the minimum sum. For each split, we calculate non-leaf node sums, considering the maximum values in the left and right subtrees. We repeat this recursively for the left and right subtrees.
    */


// for storing maximum value for every range

class Solution {
private:
// using recursion
    int solveRec(vector<int>&arr, map<pair<int,int>, int>&maxi, int left,int right){
        // base case
        if(left == right){
            return 0; //case of leaf node and we don't have to store the sum of leaf nodes
        }

        int ans = INT_MAX;
        for(int i=left;i<right;i++){
            ans = min(ans, maxi[{left,i}]* maxi[{i+1,right}] + solveRec(arr,maxi,left,i) + solveRec(arr,maxi,i+1,right));
        }
        return ans;
    }

// using memo
    int memo(vector<int>&arr ,map<pair<int,int>,int>&maxi, int left,int right, vector<vector<int>>&dp){
        // base case
        if(left == right){
            return 0;
        }

        // check if answer exists
        if(dp[left][right]!= -1){
            return dp[left][right];
        }

        int ans = INT_MAX;

        for(int i = left;i<right;i++){
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + memo(arr,maxi,left,i,dp) + memo(arr,maxi,i+1,right,dp));
        }

        // store answer in dp arrat
        dp[left][right] = ans;
        return dp[left][right];
    }

// using tabulation
int solveTab(vector<int>&arr, map<pair<int,int>,int>&maxi){
    for n = arr.size();

    // initialsing the dp array
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // Step 2 : Observe base case in top down
        // Already initialized to 0.
        // Step 3 : Reverse the flow of top down

        for(int left = n-1;left>=0;left++){
            for(int right = 0;right<=n-1;right++){
                if(left>=right){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i=left;i<right;i++){
                        ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);
                    }
                    dp[left][right] = ans;
                }
            }
        }
         // See top down call is 0 to n-1
        return dp[0][n-1];
}

public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;

         // Pre-computation (Storing maximum value for all possible range)
         // for storing maximum value for every range
         for(int i=0;i<arr.size();i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
         }

         int n = arr.size();

        // // Recursive code

        // int ans = solveRec(arr,maxi,0,n-1);

        // Top down solution
        // Step 1 : Create dp array
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = memo(arr,maxi,0,n-1,dp);



        return ans;

    }
};

int main(){
    
    return 0;
}