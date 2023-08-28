/*
Problem Description: https://leetcode.com/problems/minimum-path-sum/description/

We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix,
such that there is a minimum cost past that we select.

At every cell, we can move in only two directions: right and bottom. 
The cost of a path is given as the sum of values of cells of the given matrix.
*/

/*
Greedy approach will not give correct min solution therefore use Dp and recursion(at every cell, we will make the choice to move which costs are less.)


*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
// recursion process
int f(int i, int j ,vector<vector<int>> &grid, vector<vector<int>> &dp){
    // base cases
    if(i==0 && j==0) return grid[i][j]; //destination reached 
    if(i<0 || j<0) return INT_MAX; // negative: when boundry is crossed beyond therefore return a very large number so that path is rejected by function calling
    
    // going to all possible places using top down recursion
    if(dp[i][j] != -1) return dp[i][j];
    // at every index we have to option to go top or left
    // To go upwards, we will reduce i by 1, and move towards left we will reduce j by 1.
    int up =  f(i-1,j, grid, dp);
    int left =  f(i,j-1, grid, dp);
    return dp[i][j] = grid[i][j] + min(left, up); //as we need minimum sum

}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // initialise 2D vector dp to store minimum cost values
        vector<vector<int>> dp(n,vector<int> (m,-1)); // dp with n rows and m col with each cell initialse to -1(to indicate not computed)
        return f(n-1,m-1,grid,dp); //n-1 and m-1 because of zero based indexing as starting from (0,0)
        
    }
};

int main(){

    
    
    return 0;
}