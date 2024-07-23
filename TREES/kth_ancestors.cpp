/*
Kth Ancestor in a Tree

Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.


Example 2:

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

*/

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int data)
{
    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root = new Node(data);
    // Recursion will handle
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);
    return root;
}


bool kthAncestors(Node* root, int &k, int p){
    if(root == NULL){
        return false; //p not found
    }

    if(root->data == p){
        return true; // p found
    }

    // finding p in left side
    bool leftAns = kthAncestors(root->left, k,p);

    // finding p in right side
    bool rightAns = kthAncestors(root->right, k,p);

    // the node p will mark = k now to find its kth ancestor decrement k in left and right side until k becomes 0

    if(leftAns || rightAns){
        k--;
    }

    if(k==0){
        cout<<"kth Ancestor at node : "<<root->data<<""<<endl;
        k = -1; //putting k=-1 will stop the function to check for k =0 again
    }

    return leftAns|| rightAns;
}

int main(){
    
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);
    int k = 1;
    int p = 4;
    bool found = kthAncestors(root,k,p);
    return 0;
}