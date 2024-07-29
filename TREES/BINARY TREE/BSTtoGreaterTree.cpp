/*
538. Convert BST to Greater Tree

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]

*/

#include <bits/stdc++.h>

using namespace std;

// Approach 1: iterative approach using stacks
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

//  iterative using stacks
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int globalSum = 0;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(!st.empty() || node!= nullptr){
            while(node!=nullptr){
                st.push(node);
                node = node->right;
            }

            node = st.top();
            st.pop();
            globalSum += node->val;
            node->val = globalSum;

            node = node->left;
            
        }

        return root;
        
    }
};

//  using recursion
class Solution {
private:
    int globalSum;

    void solve(TreeNode* node){
        if(node == nullptr) return;

        solve(node->right);
        globalSum += node->val;
        node->val = globalSum;
        solve(node->left);

        return;
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        int globalSum = 0;
        solve(root);
        return root;
        
    }
};


int main(){
    
    return 0;
}

// same question : 1038. Binary Search Tree to Greater Sum Tree