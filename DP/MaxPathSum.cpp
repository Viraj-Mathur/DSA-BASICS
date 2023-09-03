// PROBLEM STATEMENT: We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.

// directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙)

// Variable starting and ending points
// f(i,j) represents the maximum path sum to reach (i,j) from any cell in the row
// out of bound case if j is negative or exceeding the grid - so return a neg value



// if condition to prevent runtime error

#include <bits/stdc++.h>

using namespace std;

// using memoisation - dp

#include <bits/stdc++.h> 


int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    // out of bound case if j is negative or exceeding the grid - so return a neg value
    if(j<0 || j>= matrix[0].size()) return -1e9;
    if(i ==0) return matrix[0][j];
    if(dp[i][j] !=-1) return dp[i][j]; //final condition
    
    // movements
    int up = matrix[i][j] + f(i-1 ,j, matrix, dp);
    int l_diagonal = matrix[i][j] + f(i-1, j-1, matrix ,dp);
    int r_diagonal = matrix[i][j] + f(i-1, j+1, matrix, dp);

    return dp[i][j] = max(up, max(l_diagonal, r_diagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m,-1));
    int maxi = -1e8;

    for(int j=0;j<m;j++){
        maxi = max(maxi, f(n-1, j, matrix ,dp));
    }
    return maxi;
}


// tabulation


int MaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1]; // if condition to prevent out of bound case for left diag
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1]; //if condition to prevent out of bound case for right diag
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
}


int main(){
    vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<"Using Memoisation the sum is: "<< getMaxPathSum(matrix)<<endl;
  cout<<"Using Tebulation the sum is: "<< MaxPathSum(matrix)<<endl;
    return 0;
}