// TO FIND MODE OF THE BST
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
void traverse(TreeNode* root, unordered_map<int,int>& mpp){
    if(root == NULL){
        return;
    }

    mpp[root->val]++;
    traverse(root->left, mpp);
    traverse(root->right, mpp);
}

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mpp;
        traverse(root,mpp);

        int maxCount = 0;

        for(auto& [key,val]: mpp){
            maxCount = max(maxCount, val);
        } 

        vector<int> ans;

        for(auto& [key,val]: mpp){
            if(val == maxCount){
                ans.push_back(key);
            }
        }

        return ans;

    }
};