// Leetcode: https://leetcode.com/problems/open-the-lock/description/?envType=daily-question&envId=2024-04-22
// Open the Lock


#include <bits/stdc++.h>

using namespace std;

// approach using BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Set to keep track of dead-end combinations for quick lookup.
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        
        // If the initial state "0000" is a dead-end, return -1 immediately.
        if (deadSet.count("0000")) {
            return -1;
        }

        // Queue for BFS, starting with the initial state "0000".
        queue<pair<string, int>> bfsQueue;
        bfsQueue.push({"0000", 0});

        // Set to keep track of visited combinations to avoid revisiting.
        unordered_set<string> visited;
        visited.insert("0000");

        // Perform BFS traversal.
        while (!bfsQueue.empty()) {
            auto current = bfsQueue.front();
            bfsQueue.pop();
            string currentCombination = current.first;
            int moves = current.second;

            // Check if we've reached the target combination.
            if (currentCombination == target) {
                return moves;
            }

            // Generate all possible next combinations by rotating each digit.
            for (int i = 0; i < 4; ++i) {
                for (int delta : {-1, 1}) {
                    int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = '0' + newDigit;

                    // Check if the new combination is valid to explore.
                    if (visited.find(newCombination) == visited.end() && deadSet.find(newCombination) == deadSet.end()) {
                        visited.insert(newCombination);
                        bfsQueue.push({newCombination, moves + 1});
                    }
                }
            }
        }

        // If target combination is not reachable.
        return -1;
    }
};



int main(){
    
    return 0;
}