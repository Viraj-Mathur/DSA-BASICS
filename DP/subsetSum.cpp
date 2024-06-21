/*
Subset Sum Problem
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

*/

#include <bits/stdc++.h>

using namespace std;

// Usind memoisation dp
class Solution{   
private:
    bool memo(vector<int>& arr, int n, int sum, vector<vector<int>>& dp){
        // Base case: If the target sum is 0,
        // an empty subset always sums up to 0
        if (sum == 0)
            return true;
    
        // Base case: If there are no elements in the array,
        // and the target sum is non-zero, it's not possible to find a subset
        if (n == 0)
            return false;
            
        // if result already computed
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        // if current element is greater than the target sum
        // exclude case
        if(arr[n-1]>sum){
            return dp[n][sum] = memo(arr,n-1,sum,dp);
        }
        else{
            // try including and excluding current element
            bool include = memo(arr, n - 1, sum - arr[n - 1], dp);
            bool exclude = memo(arr, n - 1, sum, dp);
            return dp[n][sum] = include || exclude;
        }

    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        return memo(arr,n,sum,dp);
        
    }
};

// using tabulation
class Solution2{   

public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        // initialisng dp array
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // Base case: If the target sum is 0,
        // an empty subset always sums up to 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Base case: If there are no elements in the array,
    // and the target sum is non-zero, it's not possible to find a subset
        for (int j = 1; j <= sum; j++) {
            dp[0][j] = false;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};


int main(){
    
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
    
    return 0;
}