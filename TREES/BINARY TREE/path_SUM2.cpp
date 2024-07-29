/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22


*/

// traverse to all the paths and store them in vector along with their sum in the leaf node if sum == req sum return those paths

#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    void solve(TreeNode* root, int targetSum,int currSum, vector<int>&path, vector<vector<int>>& ans){
        // base case
        if(root == NULL){
            return;
        }

        // if leaf node found
        if(root->left == NULL && root->right == NULL){
            // include leaf node in the sum
            path.push_back(root->val);
            currSum += root->val;

            if(currSum == targetSum){
                ans.push_back(path);
            }

            // backtracking as passed by reference
            path.pop_back();
            currSum -= root->val;
            return;
        }


        // including the normal current paths until leaf
        path.push_back(root->val);
        currSum += root->val;

        // check left
        solve(root->left, targetSum, currSum,path,ans);

        // check right
        solve(root->right, targetSum, currSum,path,ans);

        // backtrack as passed by reference
        path.pop_back();
        currSum -= root->val;
    }


public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int sum =0;
        vector<int>target;

        solve(root,targetSum,sum,target,ans);

        return ans;
    }
};

int main(){
    
    return 0;
}