/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

*/

#include <bits/stdc++.h>

using namespace std;

// Approach -1 using recursion - O(3^n)

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n==1 || n==2) return 1;
        else{
            return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        }
        
    }
};

// Approach 2 using DP - time complexity of O(n)

class Solution {
public:
    int tribonacci(int n) {
        // Base cases: If n is 0, return 0; if n is 1 or 2, return 1
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }

        // Create a vector to store the Tribonacci sequence up to n
        vector<int> dp(n + 1);
        // Initialize the first three values of the sequence
        dp[1] = 1;
        dp[2] = 1;

        // Calculate the remaining values using dynamic programming
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        // Return the n-th value of the sequence
        return dp[n];
    }
};


int main(){
    
    return 0;
}