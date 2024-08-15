// given a complete binary tree check if the tree is a heap or not

// heap has 2 conditions - should be complete binary tree and parent should be greater than child node(max heap)

// we check for max heap property - go to left and right subtree and compare values with the root

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

pair<bool,int>checkHeap(Node* root){
    // pair consist of max value of left and right subtree and true/false value for heap property

    // base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true, INT_MIN); // making a pair as no root exists make it true for heap property
        return p;
    }

    // for leaf node
    if(root->left == NULL && root->right == NULL){
        // leaf node is always a heap so return true
        pair<bool,int>p = make_pair(true, root->data);
        return p;
    }

    // solve for left and right subtree using recursion
    pair<bool,int> leftAns = checkHeap(root->left);
    pair<bool,int> RightAns = checkHeap(root->right);

    // checking conditions
    if(leftAns.first && RightAns.first && root->data > leftAns.second && root->data > RightAns.second){
        // if everything is passed true from below and root value is greater than left and right it is a heap
        pair<bool,int>p = make_pair(true, root->data);
        return p;
    }
    else{
        // if any condition did not met
        pair<bool,int>p = make_pair(false,root->data);
        return p;
    }
}

int main(){
    
    return 0;
}