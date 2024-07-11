/*
Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. 
Find the length of the shortest transformation sequence from startWord to targetWord.


Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord = "dfs"
Output:
3
Explanation: 
The length of the smallest transformation sequence from "der" to 
"dfs" is 3 i.e. "der" -> (replace ‘e’ by ‘f’) -> "dfr" -> (replace ‘r’ by ‘s’)  -> "dfs". 

So, it takes 3 different strings for us to reach the targetWord. Each of these strings are present in the wordList.

APPROACH: USING BFS TRAVERSAL

*/


/*
https://takeuforward.org/graph/word-ladder-i-g-29/

In this problem statement, we need to keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList

Queue: Define a queue data structure to store the BFS traversal.
Hash set: Create a hash set to store the elements present in the word list to carry out the search and delete operations in O(1) time. 


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Creating a queue of type {word, number of transitions to reach 'word'}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({beginWord, 1});

        // Push all the values of wordList into a set - to make deletion easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Erase the beginWord from the set to avoid re-visiting it.
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Return steps as soon as the first occurrence of endWord, which is the target word, is found.
            if (word == endWord) {
                return steps;
            }

            // For each character in the word, try changing it to every possible character from 'a' to 'z'.
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // Check if the modified word exists in the set and push it into the queue.
                    if (st.find(word) != st.end()) {
                        st.erase(word);  // Remove the word from the set to prevent re-visiting.
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;  // Restore the original character before moving to the next character.
            }
        }

        // If there is no transformation sequence possible
        return 0;
    }
};

int main() {
    // Given wordList, startWord, and targetWord
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    // Print the wordList
    cout << "List: ";
    for (const string& word : wordList) {
        cout << word << " ";
    }
    cout << endl;

    // Print the startWord and targetWord
    cout << "Start Word: " << startWord << endl;
    cout << "Target Word: " << targetWord << endl;

    // Create an instance of Solution class
    Solution obj;

    // Output the result
    cout << "Total number of transformations performed to reach the target word is: ";
    int ans = obj.ladderLength(startWord, targetWord, wordList);
    cout << ans << endl;

    return 0;
}


// same question as : 433. Minimum Genetic Mutation

// O(N^2∗L)

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>>q;
        q.push({startGene, 0});
        unordered_set<string> st(bank.begin(), bank.end());

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endGene ){
                return step;
            }

            for(int i=0;i<word.size();i++){
                char original = word[i];

                for(char ch : "ACGT"){
                    word[i] = ch;
                    if(st.find(word)!= st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original;
            }


        }

        return -1;
    }
};