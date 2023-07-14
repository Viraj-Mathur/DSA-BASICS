/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

*/

// t.c = O(n)

#include <bits/stdc++.h>

using namespace std;


// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



class Solution {
  public:
  
  
  int countNodes(struct Node* root) {//using recursion
    //   base case
    if(root==NULL){
        return 0;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
      
  }
  
  bool isCBT(struct Node* root, int index, int count){
      // if index exceed total count it is not a CBT
      
      if(root ==NULL)
          return true;
      
      if(index >= count)
          return false;
          
      else{
        //   check the same for right and left case
          bool left = isCBT(root->left, 2*index+1, count);
          bool right = isCBT(root->right, 2*index+2, count);
          return (left && right);
      }
  }
  
  bool isMaxOrder(struct Node* root){
    //   if leaf node
    if(root->left == NULL && root->right == NULL)
        return true;
    // if right node
    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
    // check for the leftovers
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        
        return (left && right && (root->data > root->left->data && root->data > root->right->data) );
    }
    
  }
  
  
  
  
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalCount = countNodes(tree);
        
        // Checking for both conditions
        if( isCBT(tree, index,totalCount) && isMaxOrder(tree)){
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