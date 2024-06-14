/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/

// Approach 1: Using recursion
class Solution {
private:
    int solve(string& a, string& b, int i, int j) {
        if (i == a.length())
            return b.length() - j;
        if (j == b.length())
            return a.length() - i;

        if (a[i] == b[j]) {
            // match
            return solve(a, b, i + 1, j + 1);
        }
        else {
            // no match
            int insertAns = solve(a, b, i, j + 1);    // insert condition
            int deleteAns = solve(a, b, i + 1, j);    // delete condition
            int replaceAns = solve(a, b, i + 1, j + 1); // replace condition

            return 1 + min({insertAns, deleteAns, replaceAns});
        }
    }
public:
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};

// Approach 2: using DP and memoisation - T(M*N)

class Solution {
private:
    vector<vector<int>> dp;

    int solve(string& a, string& b, int i, int j) {
        if (i == a.length())
            return b.length() - j;
        if (j == b.length())
            return a.length() - i;

        if (dp[i][j] != -1)
            return dp[i][j];


        if (a[i] == b[j]) {
            // match
            return dp[i][j] = solve(a, b, i + 1, j + 1);
        }
        else {
            // no match
            int insertAns = solve(a, b, i, j + 1);    // insert condition
            int deleteAns = solve(a, b, i + 1, j);    // delete condition
            int replaceAns = solve(a, b, i + 1, j + 1); // replace condition

            return dp[i][j] = 1 + min({insertAns, deleteAns, replaceAns});
        }
    }
public:
    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();
        
        // Initialize dp vector
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return solve(word1, word2, 0, 0);
    }
};
