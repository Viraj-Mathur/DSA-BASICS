/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


*/


#include <bits/stdc++.h>

using namespace std;

// count frequency of each element and try to consume max occuring elements firstly

// use max heap to tackle frequency count 

// in the heap use starting two elements and push it in the string and decrease the count then heapify(2 elements are processed to remove -so that any two adjacent characters are not the same.)


/* PATTERN : 
INSERT ELEMENT IN THE HEAP
USE 2-3-4 ETC STARTING ELEMENTS IN THE HEAP
PERFORM OPERATIONS ON HEAP
AND PUSH THEM BACK IN THE HEAP AND SO ON TILL HEAP BECOMES EMPTY
*/



class Solution {
public:
    string reorganizeString(string s) {
        
        // creating mapping between frequency and count
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Create a max heap (priority queue) that stores pairs of {frequency, character}

        priority_queue<pair<int, char>> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push({entry.second, entry.first});
        }

        // creating an empty string to store result
        string ans = "";

        // Process the heap until we have less than 2 elements
        while(maxHeap.size() > 1){
            // fetch top 2 elements to process
            auto first = maxHeap.top();
            maxHeap.pop();

            auto second = maxHeap.top();
            maxHeap.pop();

            // updating first and secong element in the result string 
            ans = ans + first.second;
            ans = ans + second.second;

            // decreasing their count
            first.first--;
            second.first--;

            // push the element back in heap if count freq is not 0

            if(first.first!=0){
                maxHeap.push(first);
            }

            if(second.first!=0){
                maxHeap.push(second);
            }

             
        }

        // If there's one character left in the heap
        if(!maxHeap.empty()){
            auto temp = maxHeap.top();
            maxHeap.pop();

            // If its count is more than 1, it's not possible to rearrange
            // therefor return an empty string
            if(temp.first>1){
                return "";
            }

            // else it is still possible so append the last character to result
            ans += temp.second;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}