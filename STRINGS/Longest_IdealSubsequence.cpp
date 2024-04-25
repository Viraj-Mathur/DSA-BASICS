https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25

#include <bits/stdc++.h>

using namespace std;

// Approach: as the problem symbolises pick or not pick therefore this problem can be seen as 0/1 Knapsack Problem therefore DP can be used to solve the problem

class Solution {
private:
    vector<vector<int>> dp; // 2D vector to store the memoized results

    // Recursive function to solve the problem
    int solve(int i, char last, string& s, int k) {
        int n = s.length();
        
        // Base case: if we have reached the end of the string
        if (i == n) return 0;
        
        // Check if the result is already memoized
        if (dp[i][last - 'a'] != -1) return dp[i][last - 'a'];
        
        // last - 'a' to convert the character to an index between 0 and 26 (since 'a' is ASCII 97) also to prevent overflow
        int takeLength = 0, notTakeLength = 0;
        
        // If the current character can be included in the longest ideal string
        // (either it's the first character or its difference with the previous character is <= k)
        if (last == '{' || abs(s[i] - last) <= k) { // "{" is used because "{" comes after "z"
            // Recursively find the length of the longest ideal string by including the current character
            takeLength = 1 + solve(i + 1, s[i], s, k);
        }
        
        // Recursively find the length of the longest ideal string by not including the current character
        notTakeLength = solve(i + 1, last, s, k);
        
        // Memoize and return the maximum of the two possibilities
        return dp[i][last - 'a'] = max(takeLength, notTakeLength);
    }

public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        // Initialize the dp vector with -1 to indicate that no results are memoized yet
        dp = vector<vector<int>>(n, vector<int>(27, -1));
        
        // Call the recursive function with the first character as '{'
        // (a dummy character to handle the base case)
        return solve(0, '{', s, k);
    }
};
int main(){
    
    return 0;
}