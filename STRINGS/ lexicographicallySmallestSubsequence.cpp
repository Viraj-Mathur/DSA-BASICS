/*
Given a string s, return the
lexicographically smallest
subsequence
of s that contains all the distinct characters of s exactly once.

 

Example 1:

Input: s = "bcabc"
Output: "abc"

Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

*/

// 316. Remove Duplicate Letters - same question


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string output;
        vector<bool> taken(26, false); //to keep track of which characters have been included in the subsequence so far,
        vector<int> lastIdx(26,-1); //to store the last index at which each character appears in s
        stack<char>  st;

        // store the last index of each character
        for(int i=0;i<n;i++){
            lastIdx[s[i] - 'a'] = i;
        }

        /* For each character currLetter at index i, it performs the following steps:
        a. If currLetter has not been included in the subsequence yet (i.e., isTaken[currLetter - 'a'] is 
           false), it removes all characters from the stack that are lexicographically greater than currLetter 
           and occur after currLetter in s. This is done to ensure that the subsequence is lexicographically 
           smallest.
        b. After removing the unnecessary characters, currLetter is pushed onto the stack. 
        c. isTaken[currLetter - 'a'] is set to true to mark currLetter as included in the subsequence.
        
        */
        for(int i=0;i<n;i++){
            char curr = s[i];
            if(!taken[curr - 'a']){
                while (!st.empty() && st.top() > curr && lastIdx[st.top() - 'a'] > i) {

                    taken[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(curr);
                taken[curr - 'a'] = true;
            }
        }
        // transfer characer from stack to output string
        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }

        // reverse the output string to get the lexicographically smallest ubsequence
        reverse(output.begin(), output.end());
        return output;
    }
};

int main(){
    
    return 0;
}