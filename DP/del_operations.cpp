/*
583. Delete Operation for Two Strings

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.


*/

#include <bits/stdc++.h>

using namespace std;


/*
first find the maximum common characters coming in the same order intact from both the words - use LCS for this
1. keep the longest common subsequence of the str1 and str2 intact in str1 and delete all other characters from str1.
2.  insert all the remaining characters of str2 to str1.
Minimum Operations required = (n - k) + (m - k)
*/

class Solution {

private:
    // Function to calculate the length of the Longest Common Subsequence
    int lcs(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize the first row and first column to 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        return dp[n][m];
    }



public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int k = lcs(word1, word2);

        return (n-k) + (m-k);
        
    }
};

int main(){
    
    return 0;
}