/*
Given two strings s and t of lengths m and n respectively, return the minimum window
substring
of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/

#include <bits/stdc++.h>

using namespace std;

// Approach - using sliding window and hash maps - TC: O(m+n)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if (t.length() > n) // Check if t's length is greater than s, early exit
            return "";

        string ans; // Initialize an empty string to store the answer

        unordered_map<char, int> charCount; // Create a hash map to store character frequencies in 't'
        for (char &c : t) {
            charCount[c]++;
        }

        int requiredCount = t.length(); // Number of characters in 't' that need to be found in 's'
        int i = 0, j = 0; // Pointers for the sliding window initialising them at the start of the string

        int minWindowSize = INT_MAX; // Initialize minimum window size as maximum integer value
        int startInd = 0; // Index of the starting character in the minimum window

        while (j < n) {
            char ch = s[j]; // Get the current character in 's'

            if (charCount[ch] > 0) { // If the character is present in 't' and has frequency remaining
                requiredCount--; // Decrement required count as we've found a matching character
            }
            // Always decrement the frequency in the hash map (even if not required) avoids duplication
            charCount[ch]--;

            while (requiredCount == 0) { // Shrink the window until all required characters are found
                int currWindowSize = j - i + 1; // Calculate current window size

                if (minWindowSize > currWindowSize) { // Update minimum window size if smaller
                    minWindowSize = currWindowSize;
                    startInd = i;
                }

                charCount[s[i]]++; // Increment frequency of the character leaving the window

                if (charCount[s[i]] > 0) { // If the character leaving was required, increment required count
                    requiredCount++;
                }

                i++; // Move the left pointer to shrink the window
            }

            j++; // Move the right pointer to expand the window
        }

        return minWindowSize == INT_MAX ? "" : s.substr(startInd, minWindowSize); // Return the minimum window or empty string if not found
    }
};


int main(){
    
    return 0;
}