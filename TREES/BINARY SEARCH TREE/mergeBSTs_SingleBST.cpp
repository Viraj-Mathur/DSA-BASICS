/*

1932. Merge BSTs to Create Single BST - https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/

ou are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:

Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
Replace the leaf node in trees[i] with trees[j].
Remove trees[j] from trees.
Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, or null if it is impossible to create a valid BST.

A BST (binary search tree) is a binary tree where each node satisfies the following property:

Every node in the node's left subtree has a value strictly less than the node's value.
Every node in the node's right subtree has a value strictly greater than the node's value.
A leaf is a node that has no children.

 

Example 1:


Input: trees = [[2,1],[3,2,5],[5,4]]
Output: [3,2,5,1,null,4]
*/

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

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    // Collect all nodes of a tree except for the root node in a map
    void collect(unordered_map<int, TreeNode*>& mpp, TreeNode* node) {
        if (!node) {
            return;
        }
        mpp[node->val] = node;

        // Recursively collect left subtree
        collect(mpp, node->left);
        // Recursively collect right subtree
        collect(mpp, node->right);
    }

    // Merge trees by replacing leaf nodes with matching trees from the map
    void makeTree(unordered_map<int, TreeNode*>& mpp, TreeNode*& node, int& count) {
        if (!node) return;

        // If it's a leaf node and its value exists in the map
        if (!node->left && !node->right && mpp[node->val]) {
            // Replace the leaf with the corresponding tree from the map
            node = mpp[node->val];
            mpp[node->val] = NULL;
            count++;
        }
        
        // Recursively process left subtree
        makeTree(mpp, node->left, count);

        // Recursively process right subtree
        makeTree(mpp, node->right, count);
    }

    // Function to validate if the tree is a valid BST
    bool validateBST(TreeNode* root, TreeNode* low, TreeNode* high) {
        if (!root) return true;

        // Check if the current node's value is within the valid range
        if ((low && root->val <= low->val) || 
            (high && root->val >= high->val)) return false;

        // Recursively validate left and right subtrees
        return validateBST(root->left, low, root) 
            && validateBST(root->right, root, high);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // If there's only one tree, validate and return it
        if (trees.size() == 1) {
            return validateBST(trees[0], NULL, NULL) ? trees[0] : NULL;
        }
        
        // Collect all nodes except root nodes in a map
        unordered_map<int, TreeNode*> mp;
        for (auto& node : trees) {
            collect(mp, node->left);
            collect(mp, node->right);
        }

        // Find the root of the final tree
        TreeNode* root = NULL;
        for (auto& node : trees) {
            if (mp.count(node->val)) mp[node->val] = node;
            else if (root) return NULL; // More than one root found, invalid
            else root = node;
        }

        if (!root) return NULL; // No root found, invalid

        // Merge trees
        int cnt = 0;
        makeTree(mp, root, cnt);
        if (cnt != mp.size()) return NULL; // Not all trees were merged, invalid
        
        // Validate the final BST and return
        return validateBST(root, NULL, NULL) ? root : NULL;
    }
};


/*
The solution works by:

Collecting all nodes except root nodes in a map.
Identifying the root of the final tree.
Merging trees by replacing leaf nodes with matching trees from the map.
Validating that all trees were merged and that the final tree is a valid BST.

The time complexity of this solution is O(n), where n is the total number of nodes across all trees, as each node is processed a constant number of times. The space complexity is also O(n) due to the use of the unordered_map to store nodes.
*/