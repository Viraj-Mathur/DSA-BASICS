// CODE FOR COUNTING NUMBER OF LEAF NODE
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void inorder(BinaryTreeNode<int> *root, int &count){
    // base case
    if(root == NULL){
        return;
    }
    inorder(root->left, count); // L
    // leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }

    inorder(root->right,count); // R
}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count = 0;
    inorder(root,count);
    return count;
}

int main(){
    
    return 0;
}