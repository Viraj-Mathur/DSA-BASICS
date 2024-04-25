/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.


Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
*/

#include <bits/stdc++.h>

using namespace std;

// Approach: use 2 pointers

class Solution {
private:
    bool isPalindrome(string s, int i, int j){
        while(j>=i){
            if(s[i]!=s[j]) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i=0;
        int j= s.length()-1;
        while(j>=i){
            if(s[i]!=s[j]){
                return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1); //removing one character
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};

int main(){
    
    return 0;
}