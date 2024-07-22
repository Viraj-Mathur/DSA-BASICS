/*
Vertical Traversal of Binary Tree

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 

*/

#include <bits/stdc++.h>

using namespace std;

// hint : try to map horizontal distance with levelwise nodes(levelwise nodes also means mapping levels with nodes)
// treat each verticles as numberline with 0 as root and left as -ve and right as +ve distance

class Solution
{
    public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // Base case: If the root is NULL, return an empty vector.
        if (root == NULL) {
            return {};
        }
        
        // This map stores nodes based on their horizontal distance and level.
        // mpp[horizontal_distance][level] -> vector of nodes
        map<int, map<int, vector<int>>> mpp;
        
        // Queue to perform level order traversal. Each element is a pair where:
        // - First element is the node
        // - Second element is a pair containing horizontal distance and level.
        queue<pair<Node*, pair<int, int>>> q;
        
        // Start with the root node at horizontal distance 0 and level 0.
        q.push(make_pair(root, make_pair(0, 0)));
        
        while (!q.empty()) {
            // Extract the front element from the queue.
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int horizontal_distance = temp.second.first;
            int level = temp.second.second;
            
            // Store the node's data in the map based on its horizontal distance and level.
            mpp[horizontal_distance][level].push_back(frontNode->data);
            
            // If the left child exists, push it to the queue with horizontal distance -1 and level +1.
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(horizontal_distance - 1, level + 1)));
            }
            
            // If the right child exists, push it to the queue with horizontal distance +1 and level +1.
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(horizontal_distance + 1, level + 1)));
            }
        }
        
        // Vector to store the final vertical order traversal.
        vector<int> ans;
        
        // Traverse the map and collect the nodes in vertical order.
        for (auto i : mpp) {
            for (auto j : i.second) {
                for (auto k : j.second) {
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
    }
};


int main(){
    
    return 0;
}