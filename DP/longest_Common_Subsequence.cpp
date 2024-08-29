/*

1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
*/


#include <bits/stdc++.h>

using namespace std;

/*
// compare the two strings using recursion and add it if matched 
// recursive function :(consider index of string 1 as index1 and index of string 2 as index2)

the recursive function would be : if matched : 1 + f(index1-1 , index2-1 )
if not matched : 0 + max(f(index1-1, index2), f(index1, index2-1))
*/


// approach 1 : memoisation - Time Complexity: O(N*M), Space Complexity: O(N*M) + O(N+M)

class Solution {
    private:
    int lcs_memo(string &text1, string &text2, int index1, int index2, vector<vector<int>>&dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }

        // check if dp exists
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];

        }

        // string matched condition
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + lcs_memo(text1 ,text2, index1-1, index2-1 ,dp);
        }
        else{
            // not matched condition
            return dp[index1][index2] = max(lcs_memo(text1, text2, index1-1,index2,dp), lcs_memo(text1,text2, index1,index2-1,dp));
        }
    }

// tabulation :
/*
Initialization: Shifting of indexes
In the recursive logic, we set the base case to if(ind1<0 || ind2<0) but we can’t set 
the dp array’s index to -1. Therefore a hack for this issue is to shift every index by 1 towards the right.

Therefore, now the base case will be if(ind1==0 || ind2==0).
Similarly, we will implement the recursive code by keeping in mind the shifting of indexes, therefore S1[ind1] will be converted to S1[ind1-1]. Same for others.
At last we will print dp[N][M] as our answer.

Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.

*/


int lcs_tab(string text1, string text2){
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); // creating a dp table with shift in vector space
    // base cases
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for(int index1 = 1; index1<=n;index1++){
        for(int index2 = 1; index2 <=m;index2++){
            if(text1[index1-1] == text2[index2-1]){
                // match condition
                dp[index1][index2] = 1 + dp[index1-1][index2-1];
            }
            // no match case
            else{
                dp[index1][index2] = max(dp[index1-1][index2], dp[index1][index2-1]);
            }
        }

    }

    return dp[n][m];


}


// space optimised method
/*
If we closely we are using two rows: dp[ind1-1][ ], dp[ind][ ],

So we are not required to contain an entire array, we can simply have two rows prev and cur 
where prev corresponds to dp[ind-1] and cur to dp[ind].

After declaring prev and cur, replace dp[ind-1] to prev and dp[ind] with cur and after the inner loop executes, 
we will set prev = cur, so that the cur row can serve as prev for the next index.
*/

int lcs_spcace(string text1, string text2){

        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Fill in the DP table to calculate the length of LCS
        for(int index1 = 1; index1 <= n; index1++) {
            for(int index2 = 1; index2 <= m; index2++) {
                if(text1[index1 - 1] == text2[index2 - 1]) {
                    // match condition
                    cur[index2] = 1 + prev[index2 - 1]; 
                } else {
                    // no match case
                    cur[index2] = max(prev[index2], cur[index2 - 1]);
                }
            }
            prev = cur; // update prev to be the current row after processing
        }

        return prev[m]; // the last value in prev contains the length of the LCS
    }





public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return lcs_memo(text1, text2, n-1,m-1,dp);
    }
};

int main(){
    
    return 0;
}