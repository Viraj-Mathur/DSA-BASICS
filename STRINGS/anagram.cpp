// Group anagrams
/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


*/

// Approach : sorting the words and matching them using a hash table

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> result;
        // iterate through each string str in the input strs vector.
        for (const string& str : strs) {
            // For each str, we create a new string sortedStr by sorting the characters 
            // of str in lexicographical order using the sort function.
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // anagramMap[sortedStr] accesses the value associated with the key sortedStr in the anagramMap.
            // If the key sortedStr already exists in the anagramMap, anagramMap[sortedStr] returns the vector of strings associated with that key. 
            // If the key doesn't exist, a new empty vector is created and inserted into the anagramMap with the key sortedStr.

            anagramMap[sortedStr].push_back(str);
        }
        
        for (const auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

int main(){
    
    return 0;
}

/*
final anagram map
anagramMap = { 
  "aet": ["eat", "tea", "ate"], 
  "ant": ["tan", "nat"], 
  "abt": ["bat"] 
}

*/