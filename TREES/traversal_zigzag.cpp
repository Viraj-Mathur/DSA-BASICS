/*
Zig Zag Traversal Of Binary Tree / spiral traversal of a BT

Problem Statement: Given a Binary Tree, print the zigzag traversal of the Binary Tree. 
Zigzag traversal of a binary tree is a way of visiting the nodes of the tree in a zigzag pattern, alternating 
between left-to-right and right-to-left at each level.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Initialize the result vector which will store the final zigzag level order traversal
        vector<vector<int>> result;

        // If the root is null, return the empty result
        if (root == nullptr) {
            return result;
        }

        // Initialize a queue to facilitate level order traversal
        queue<TreeNode*> q;

        // Start with the root node
        q.push(root);

        // Boolean flag to determine the direction of traversal, starting with left to right
        bool leftToRight = true;

        // Process nodes level by level
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();

            // Initialize a temporary vector to store nodes of the current level
            vector<int> ans(size);

            // Process each node in the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                TreeNode* frontNode = q.front();
                q.pop();

                // Determine the index to place the node's value based on the current direction
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->val;

                // Push the left child to the queue if it exists
                if (frontNode->left) {
                    q.push(frontNode->left);
                }

                // Push the right child to the queue if it exists
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // Add the current level's result to the final result
            result.push_back(ans);

            // Change direction for the next level
            leftToRight = !leftToRight;
        }

        // Return the final zigzag level order traversal
        return result;
    }
};


int main(){
    
    return 0;
}

