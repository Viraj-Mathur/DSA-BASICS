/*
115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

*/

#include <bits/stdc++.h>

using namespace std;
/*
getting the recurrence relation
take two pointers i and j for respective strings 
if word matched : we have two option of taking or not taking
if(S1[i]==S2[j]) : f(i-1,j-1) and f(i-1,j). ->not rejecting string and rejecting the string to explore other possibilities
if(S1[i]!=S2[j]), call f(i-1,j). -> string rejected only
*/


// approach 1 : using memo - gives TLE(sometimes due to extra space: Time Complexity: O(N*M), Space Complexity: O(N*M) + O(N+M) Reason: We are using a recursion stack space(O(N+M)) and a 2D array ( O(N*M)).)
class Solution {
    private:
        int memo(int i,int j, string s,string t, vector<vector<int>>&dp){
            // base cases
            if(j<0) return 1; // If s2 has been completely matched, return 1 (found a valid subsequence)
            if(i<0) return 0; // If s1 has been completely traversed but s2 hasn't, return 0

            if(dp[i][j]!=-1){
                return dp[i][j];
            }

            if(s[i] == t[j]){
                // string letter matched 
                return dp[i][j] = memo(i-1,j-1,s,t,dp) + memo(i-1,j,s,t,dp);
            }
            else{
                return dp[i][j] = memo(i-1,j,s,t,dp);
            }
        }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return memo(n-1,m-1,s,t,dp);
    }
};

int main(){
    
    return 0;
}