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





#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Creating a queue {word,transitions to reach ‘word’}
        queue<pair<string, int >> q;

        q.push({startWord ,1});

        // push all values of worldList in a set coz it makes deletion easy with O(1) time complexity

        unordered_set<string> st(wordList.begin(), wordList.end()); 
        st.erase(startWord); //deleting the word after being used from the set

        while(!q.empty()){
            string word = q.front().first; //word
            int steps = q.front().second; //transition
            q.pop();

            // return the step when occurance of the targetWord is found

            if(word == targetWord){
                return steps;
            }

            for(int i=0;i<word.size();i++){
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i] = ch;
                    

                    // if word from the set exist push it in a queue
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps +1 });
                    }

                }
                    word[i] = original;
                    cout<< original;


                    
            }
        }

        // if word not found and cannot be converted
        return 0;
    }
};

int main(){

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
    cout<<"Transformed Words are: ";
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
    cout<<endl;
    cout << "Total number of tranformations performed to reach the target word is: " << ans;
    cout << endl;
    
    return 0;
}