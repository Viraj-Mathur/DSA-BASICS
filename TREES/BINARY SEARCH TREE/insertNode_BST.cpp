/*
701. Insert into a Binary Search Tree

You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

*/

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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL){
            return new TreeNode(val); //base case if no tree exists make it root
        }

        TreeNode* curr = root;//make current node as root;

        while(true){//means if root exists
            if(curr->val <= val){
                // if value is greater traverse at the right child
                if(curr->right !=NULL){
                    curr = curr->right; //traverse
                }

                else{
                    // insert the value when right does not exists
                    curr->right = new TreeNode(val);
                    break;
                }
            }

            else{ //case where value is less than root then traverse left
                if(curr->left !=NULL){
                    curr = curr->left; //traverse
                }

                else{
                    // insert the value when left does not exists
                    curr->left = new TreeNode(val);
                    break;
                }

            }
        }

        return root;
        
    }
};

// TC : O(log n)

int main(){
    
    return 0;
}