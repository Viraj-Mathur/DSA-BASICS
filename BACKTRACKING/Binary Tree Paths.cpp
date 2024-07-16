/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

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
    void solve(TreeNode* root,vector<string>& ans,string &temp){
        // base case
        if(root == NULL){
            return;
        }
        // if leaf node
        if(root->left == NULL && root->right == NULL){
            string oldTemp = temp;
            temp = temp + to_string(root->val);
            ans.push_back(temp);
            temp = oldTemp;
            return;
        }

        // normal case
        string oldTemp = temp;
        temp = temp + to_string(root->val);
        // as we need "->" also
        temp.push_back('-');
        temp.push_back('>');

        // left call
        solve(root->left,ans,temp);
        // right call
        solve(root->right,ans,temp);

        // backtrack 
        temp = oldTemp;


    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp = "";

        solve(root,ans,temp);
        return ans;
    }
};

int main(){
    
    return 0;
}