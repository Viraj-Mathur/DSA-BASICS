/*
PROBLEM STATEMENT: 
We are given a Triangular matrix. We need to find the minimum path sum from the first row to the last row.
At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘)


APPROACH: NO GREEDY USE DP
*/




#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 

// recursion: gives TLE
class Solution1 {
    int solve(int row, int col, vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (row >= n) {
            return 0;
        }
        int m = triangle[row].size();
        if (col >= m) {
            return 0;
        }                                     //down traversal             diagonal traversal
        return triangle[row][col] + min(solve(row+1, col, triangle), solve(row+1, col+1, triangle));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0, 0, triangle);
    }
};

// recursive memoisation : still gives TLE
// We can create a 2D matrix DP and store the result of each recursion call in it.

class Solution2 {
    int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        if (row >= n) {
            return 0;
        }
        int m = triangle[row].size();
        if (col >= m) {
            return 0;
        }
        if (dp[row][col] != -1) { // memoisation 
            return dp[row][col];
        }

        // memoisation                                     //  down traversal                 diagonal traversal
        return dp[row][col] = triangle[row][col] + min(solve(row+1, col, triangle, dp), solve(row+1, col+1, triangle, dp));
    }
public:
    int minTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i=0; i<n; i++) {
            int m = triangle[i].size(); // m stores number of elements in the current row
            for (int j=0; j<m; j++) {
                dp[i].push_back(-1);
            }
        }
        return solve(0, 0, triangle, dp);
    }
};

// tabulation 
// Recursion/Memoization is a top-down approach whereas tabulation is a bottom-up,In recursion/memoization, we have moved from 0 to N-1, in tabulation we move from N-1 to 0, i.e the last row to the first one.

class Solution3 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i=0; i<n; i++) {
            int m = triangle[i].size();
            for (int j=0; j<m; j++) {
                if (i == n-1) {
                    dp[i].push_back(triangle[i][j]);
                } else {
                    dp[i].push_back(-1);
                }
            }
        }
        for (int i=n-2; i>=0; i--) {
            int m = triangle[i].size();
            for (int j=0; j<m; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

int main(){
    
    return 0;
}

/*
    Time complexity: O(n²)
    Space complexity: O(n²)
*/