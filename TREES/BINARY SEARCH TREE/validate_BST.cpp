// Given the root of a binary tree, determine if it is a valid binary search tree (BST).


#include <bits/stdc++.h>

using namespace std;

// APPROACH 1: FIND INORDER TRAVERSAL IF IT IS SORTED THEN VALID BUT IT TAKE O(n) TIME

// APPROACH 2: FIND THE RANGE FOR EVERY NODE LIKE ROOT NODE WILL BE IN RANGE (-INF, INF) THEN LEFT CHILD(-INF, ROOT->DATA) RIGHT CHILD (ROOT->DATA,INF) AND SO ON



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    bool solve(TreeNode* root, long long int lowerB,long long int upperB){

        // base case
        if(root == NULL){
            // empty BST
            return true;
        }

        if(root->val > lowerB && root->val <upperB){
            // check if left subtree is a BST or not
            bool leftAns = solve(root->left, lowerB, root->val);

            // check if right subtree is a BST or not
            bool rightAns = solve(root->right, root->val, upperB);

            // both right and left check -> is BST
            return leftAns && rightAns;
        }
        else{
            // NOT A BST
            return false;
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        long long int lowerBound = -4294967296; // -INFINITY
        long long int uppperBound = 4294967296; // INFINITY

        bool ans = solve(root,lowerBound, uppperBound);

        return ans;
    }
};

int main(){
    
    return 0;
}