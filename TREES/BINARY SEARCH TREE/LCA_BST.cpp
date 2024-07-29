// program to find LOWEST COMMON ANCESTOR IN BST

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // base case
        if(root == NULL){
            return NULL;
        }

        // case 1 : Answer is on the left subtree
        if(p->val < root->val && q->val < root->val){
            // if p and q both are smaller than node go left
            return lowestCommonAncestor(root->left,p,q);
        }

        // case 2 : Answer is on the right subtree
        else if(p->val > root->val && q->val > root->val){
            // if p and q both are greater than node go right
            return lowestCommonAncestor(root->right,p,q);
        }

        // case 3 and 4 where any p or q is greater or smaller
        else 
            return root;
    }
};

int main(){
    
    return 0;
}