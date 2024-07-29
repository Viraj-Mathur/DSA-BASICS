/*
Tree Boundary Traversal

Problem Statement: 
Given a Binary Tree, perform the boundary traversal of the tree. The boundary traversal is the process of visiting the boundary nodes of the binary tree

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

ALGO:print left side of tree except the leaf node
     print all the leaf nodes
     print right side of tree except the leaf node(catch - print this in reverse direction)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // printing the left side without leaf
    void traverseLeft(Node* root, vector<int>& ans) {
        // base case
        if (root == NULL || (root->left == NULL && root->right == NULL)) { // null and leaf condition check
            return;
        }

        // print root first - then left part after loop
        ans.push_back(root->data);

        // now print the left part
        if (root->left) {
            traverseLeft(root->left, ans);
        } else {
            traverseLeft(root->right, ans);
        }
    }

    // function to traverse the leaf now - using inorder traversal - LNR
    void traverseLeaf(Node* root, vector<int>& ans) {
        // base case
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
        }

        // traversing left and right and checking for leaf
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    // printing the right side without leaf
    void traverseRight(Node* root, vector<int>& ans) {
        // base case
        if (root == NULL || (root->left == NULL && root->right == NULL)) { // null and leaf condition check
            return;
        }
        // traverse through right subtree and print the recursion while coming back (reverse inorder)
        // travel right subtree
        if (root->right) {
            traverseRight(root->right, ans);
        } else {
            // traverse for left if right not exist
            traverseRight(root->left, ans);
        }

        // waapas aagye
        ans.push_back(root->data);
    }

public:
    vector<int> boundary(Node* root) {
        // Your code here
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        ans.push_back(root->data);

        // left side traverse
        traverseLeft(root->left, ans);

        // leaf traversal
        // for both left and right
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        // right side traversal
        traverseRight(root->right, ans);

        return ans;
    }
};


int main(){
    
    return 0;
}