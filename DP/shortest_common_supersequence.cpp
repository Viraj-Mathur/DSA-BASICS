/*
1092. Shortest Common Supersequence 

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>

using namespace std;
/*

 A supersequence is defined as the string which contains both the strings S1 and S2 as subsequences.

// while comparing both the strings taken common letters appearing in both strings once only
// this can be done using LCS

// to find the length find common LCS first then len = n+m-len(LCS)

if(S1[i-1] == S2[j-1]), this means the character is an lcs character and needs to be included only once from both the strings, 
so we add it to the ans string and reduce both i and j by 1. We reduce them simultaneously to 
make sure the character is counted only once.

if(S1[i-1] != S2[j-1]), this means that the character is a non-lcs character and then we move the pointer to the top cell or 
left cell depending on which is greater. This way non-lcs characters will be included separately in the right order.
*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i=0;i<=m;i++){
            dp[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int len = dp[n][m]; //last row and col of the table is the final length

        int index1 = n;
        int index2 = m;

        int index = len - 1;

        string ans = "";

        while(index1>0 && index2>0){
            if(str1[index1-1] == str2[index2-1]){
                ans += str1[index1-1];
                index--;
                index1--;
                index2--;
            }
            else if(dp[index1-1][index2] > dp[index1][index2-1]){
                ans+= str1[index1-1];
                index1--;
            }
            else{
                ans+= str2[index2-1];
                index2--;
            }
        }

        //Adding Remaing Characters - Only one of the below two while loops will run if any letter remains
        while(index1 > 0){
            ans+= str1[index1-1];
            index1--;
        }
        while(index2>0){
            ans+= str2[index2-1];
            index2--;
        }

        // the word we will be getting is the reverse as we had done bottom up
        reverse(ans.begin(), ans.end());

        return ans;


    }
};

int main(){
   
    string s1 = "brute";
    string s2 = "groot";

    cout << "The Longest Common Supersequence is "<<shortestCommonSupersequence(s1,s2);
    return 0;
}