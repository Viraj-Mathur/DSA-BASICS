/*

140. Word Break II

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    void solve(string s,set<string>& st,vector<string>& result,string temp,int index){
        // base case
        if(index >= s.length()){
            temp.pop_back(); //inorder to remove the extra spacing at the end of the formed word
            result.push_back(temp);
            return;
        }
        string subString = ""; //this to form string check
        for (int i = index; i < s.length(); i++) {
            subString.push_back(s[i]);

            if(st.count(subString)){
                // if string match call for action - recursion
                solve(s,st,result,temp+subString + " ",i+1); //addded because temp is the prev sol
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        vector<string>result;

        for(auto str :wordDict){
            st.insert(str);
        }

        // creating a temporary string
        string temp = "";
        solve(s,st,result,temp,0);
        return result;
    }
};

int main(){
    
    return 0;
}