/*
Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters 
that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces 
are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, 
where cost of line is = (Number of extra spaces in the line)^2.

Example 1:

Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4

So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.

*/

// Solve using DP
class Solution {
public:
    int dp[500][2005]; // dp array to store the results of subproblems

    // Function to solve the problem recursively with memoization
    int recurr(int i, int remaining, vector<int>& arr, int& k) {
        // Base case: if we have processed all words
        if (i == arr.size()) {
            return 0;
        }

        // If the result for the current subproblem is already computed
        if (dp[i][remaining] != -1) {
            return dp[i][remaining];
        }

        int ans;
        if (arr[i] > remaining) {
            // If the current word is longer than the remaining spaces on the current line,
            // we need to put it on the next line
            ans = (remaining + 1) * (remaining + 1) + recurr(i + 1, k - arr[i] - 1, arr, k);
            // (remaining + 1) represents the extra spaces on the current line,
            // and k - arr[i] - 1 represents the remaining spaces after putting the current word on a new line
        } else {
            // We have two choices: putting the word on the next line or on the same line
            int choice1 = (remaining + 1) * (remaining + 1) + recurr(i + 1, k - arr[i] - 1, arr, k);
            // Choice 1: Put the word on the next line
            int choice2 = recurr(i + 1, remaining - arr[i] - 1, arr, k);
            // Choice 2: Put the word on the same line
            ans = min(choice1, choice2); // Choose the minimum cost option
        }

        // Store the result for the current subproblem and return it
        dp[i][remaining] = ans;
        return dp[i][remaining];
    }

    int solveWordWrap(vector<int> nums, int k) {
        // Initialize the dp array with -1 (uninitialized)
        memset(dp, -1, sizeof(dp));

        // Call the recursive function with initial parameters
        return recurr(0, k, nums, k);
    }
};
