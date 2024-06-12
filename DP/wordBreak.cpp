/*

139. Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

*/
//solved using top down approach memoisation dp
class Solution {
private:
    unordered_map<int,bool> memo; //to store result in memoisation
    unordered_set<string> wordSet;

    bool recurr(const string& s, int start){
        if(start == s.length()){
            return true; //if all the length matches with the string base case
        }

        if(memo.count(start)){
            return memo[start]; //If the subproblem for start has already been solved, we return the memoized result from memo[start].
        }

        for(int i = start+1;i<=s.length();i++){
            string word = s.substr(start,i-start); //we extract the prefix substring word from the string s using the substr function. The starting index is start, and the length of the substring is end - start. This gives us the prefix substring from index start to end - 1.
            if(wordSet.count(word) && recurr(s,i)){//checking if substring is present in the word list and This recursive call checks if the remaining suffix s[end:] can be segmented into words from wordDict. If this recursive call returns true, it means the suffix can be segmented, and we have found a valid segmentation of the entire string s.
                memo[start] = true; //if conditioned satisfied
                return true;
            }
        }

        memo[start] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return recurr(s,0); //calls the recurr function, passing the input string s and the starting index 0

        
    }
};
