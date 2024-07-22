// TO check if given 2 trees are identical or nor

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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // using any traversal techniques - using preOrder traversal here to compare - NLR
        if(p == NULL || q == NULL){
            return (p==q);
        }
        else{
            return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right); //N&L&R
        }
    }
};


// using LRN

class Solution{
    public:
    bool isIdentical(Node* r1,Node *r2){
        // base case
        if(r1 == NULL && r2 == NULL){
            return true;
        }

        if(r1 == NULL && r2!= NULL){
            return false;
        }

        if(r1!= NULL && r2 == NULL){
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);

        bool value = r1->data == r2->data;

        if(left && right && value){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    
    return 0;
}