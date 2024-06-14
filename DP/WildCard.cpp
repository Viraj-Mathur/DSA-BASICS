/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

 
*/


class Solution {
private: 
    int solve(string a, string b, int i, int j,vector<vector<int>> &dp){
        // base cases
        if (i < 0 && j < 0) {
            return true; // both strings are exhausted
        }

        if (i >= 0 && j < 0) {
            return false; // pattern is exhausted but string is not
        }

        
        if (i < 0 && j >= 0) {
            // if pattern has only '*' remaining, it's a match
            for (int k = j; k >= 0; k--) {
                if (b[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1){ // dp memoization
            return dp[i][j];
        }

        // if characters match or pattern character is '?'

        if(a[i] == b[j] || b[j] == '?'){
            dp[i][j] = solve(a,b,i-1,j-1,dp);
        }
        // '*' can match zero or more characters
        else if (b[j] == '*'){
            dp[i][j] = solve(a,b,i,j-1,dp) || solve(a,b,i-1,j,dp);
        }
        else{
            dp[i][j] = false; // characters do not match
        }

        return dp[i][j];
    }

public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, p, m - 1, n - 1, dp);
        
    }
};


// Approach 2: using DP the previous one gives TLE
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        // Create a DP table with (m + 1) rows and (n + 1) columns
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base cases
        dp[0][0] = true; // Empty string matches empty pattern
        
        // Fill the first row (s is empty)
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = false;
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        // The result is in dp[m][n]
        return dp[m][n];
    }
};

