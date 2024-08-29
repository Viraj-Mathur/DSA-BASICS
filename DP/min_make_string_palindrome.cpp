/*
1312. Minimum Insertion Steps to Make a String Palindrome

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

find the longest intact palindrome that you can find in the string
between those add the remaining string at one side and reverse of it on another
len - longest intact palindrome will be the answer

Note : use LCS to find len of l subseqongest intact palindrome subsequence
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int lcs(string s1, string s2){
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i] = 0;
        }

        for(int ind1 = 1; ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(s1[ind1 -1] == s2[ind2 - 1]){
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 -1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 -1]);
                }
            }

        }

        return dp[n][m];
    }

    int longestPalindromeIntact(string s){
        string s1 = s;
        reverse(s.begin(), s.end());
        return lcs(s,s1);
    }
public:
    int minInsertions(string s) {
        int len = s.size();
        int k = longestPalindromeIntact(s);

        // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return len - k;
    }
};

int main(){
    
    return 0;
}