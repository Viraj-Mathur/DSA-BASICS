/*
257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.


*/

#include <bits/stdc++.h>

using namespace std;


//  * Definition for a binary tree node.
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
    void solve(TreeNode* root,vector<string>& ans,string &temp ){
        // base case
        if(root == NULL){
            return;
        }

        // if leaf node
        if(root->left == NULL && root->right == NULL){
            string oldtemp = temp;
            temp = temp+ to_string(root->val);
            ans.push_back(temp);
            // backtrack
            temp = oldtemp;
        }

        // noramal case
        string oldtemp = temp;
        temp = temp + to_string(root->val);

        // as we need "->" also
        temp.push_back('-');
        temp.push_back('>');

        // left call
        solve(root->left,ans,temp);

        // right call
        solve(root->right,ans,temp);

        // backtrack
        temp = oldtemp;
    }


public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";

        solve(root,ans,temp);
        return ans;
    }

};

int main(){
    
    return 0;
}