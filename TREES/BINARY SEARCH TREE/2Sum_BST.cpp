/*
653. Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, 
or false otherwise.

*/


// APPROACH -> MAKE INORDER TRAVERSAL IT WILL ACT AS AN ARRAY THEN USE TWO POINTER TECHNIQUE LIKE IN TWO SUM TO MATCH THE SUM

#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

private:
    void storeInorder(TreeNode* root,vector<int>&inorder){
        // to find and store inorder as vector

        if(root == NULL){
            return;
        }

        // L
        storeInorder(root->left,inorder);

        // N
        inorder.push_back(root->val);

        // R
        storeInorder(root->right,inorder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        storeInorder(root,inorder); //making the inorder vector

        // 2 pointer approach

        int start = 0;
        int end = inorder.size()-1;

        while(start < end){
            int sum = inorder[start] + inorder[end];
            // if sum matched equal to k

            if(sum == k){
                return true;
            }

            else if(sum > k){
                end--; //when sum exeeds k decrease the end
            }
            else{
                start++; //when sum is  less than k increase the start
            }
        }

        return false; //no match sum value

    }
};

int main(){
    
    return 0;
}