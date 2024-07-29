/*
Lowest Common Ancestor in a Binary Tree

Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 
Example 3:

Input:
n1 = 5 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 5
Explanation:
LCA of 5 and 4 is 5. 

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL){
            return NULL; // if no tree found
        }

        // check for p and q in current node
        if(root->val == p->val){
            return p; // p found
        }
        if(root->val == q->val){
            return q; // q found
        }

        // check answer from left subtree
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);

        // check answer from right subtree
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // cases
        // if answer not found 
        if(leftAns == NULL && rightAns == NULL){
            return NULL; // means no LCA found 
        }
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns; 
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns; // means no LCA found 
        }

        //if(leftAns =! NULL && rightAns =!R NULL){
        else{
            return root;
        }
    }
};

// Example usage
int main() {
    // Creating the tree:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* ancestor = sol.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(1));

    if(ancestor != NULL) {
        cout << "LCA(5, 1) = " << ancestor->val << endl;
    } else {
        cout << "Keys are not present" << endl;
    }

    return 0;
}
