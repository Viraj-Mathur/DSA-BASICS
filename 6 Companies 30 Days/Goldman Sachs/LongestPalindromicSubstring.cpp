/*
https://leetcode.com/problems/longest-palindromic-substring/description/

Given a string s, return the longest palindromic substring

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/


#include <bits/stdc++.h>
using namespace std;


// Approach 1: Brute Force : takes O(n) time, the run time complexity is O(n^3).

class Solution {
    private:
    bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}
public:
    string longestPalindrome(string s) {
        if(s.length() <=1){
            return s;
        }

        int max_len = 1;
        string max_string = s.substr(0,1);
        for(int i=0;i<s.length(); i++){
            for(int j=i+max_len; j<=s.length();j++){
                if(j-i > max_len && isPalindrome(s.substr(i,j-i))){
                    max_len = j-i;
                    max_string = s.substr(i,j-i);
                }
            }
        }
        return max_string;
        
    }
};

// NOTE : THIS APPROACH GIVES TLE IN LEETCODE

int main(){
    

    return 0;
}