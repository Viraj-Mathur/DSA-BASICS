/* Morris Preorder Traversal and Morris PostOrder Traversal

// normal traversal take O(N) time and O(N) SPACE 


Morris Preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure. 
The algorithm should efficiently visit each node in the binary tree in preorder sequence, printing or processing the node values as it traverses, 
without using a stack or recursion.



*/


// Morris Inorder Traversal of a Binary tree
/*
Algo:

Step 1:Initialise a current to traverse the tree. Set current to the root of the Binary Tree.

Step 2: While the current is not null: If the current node has no left child, print the current node's value and move to the right child 
        ie. set the current to its right child.

Step 3: If the current node has a left child, we find the in-order predecessor of the current node. 
        This in-order predecessor is the rightmost node in the left subtree or the left subtree's rightmost node.

If the right child of the in-order predecessor is null:
    Set the right child to the current node.
    Move to the left child (i.e., set current to its left child).

If the right child of the in-order predecessor is not null:
    Revert the changes made in the previous step by setting the right child as null.
    Print the current node's value.
    Move to the right child (i.e., set current to its right child).

Repeat steps 2 and 3 until the end of the tree is reached.

*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
    public:
        // inorder morris function

        vector<int> getInorder(TreeNode* root){

            // vector to store inorder traversal result
            vector<int> inorder;

            // pointer start with the root node
            TreeNode* curr = root;

            while(curr!=NULL){

                // case 1: if current node left is empty
                if(curr->left == NULL){
                    // print the node and move to right side
                    inorder.push_back(curr->val);
                    // move to right
                    curr = curr->right;
                }

                else{
                    // case 2
                    // if left child is not null find the predecessor(righnmost node of the left subtree)
                    TreeNode* prev = curr->left;

                    while(prev->right && prev->right !=curr){ //go to right
                        prev = prev->right;
                    }

                    // if predecessor right child is null establish a link(thread) and move to the left child

                    if(prev->right == NULL){
                        prev->right = curr;
                        curr = curr->left; //link created
                    }
                    else{
                        // if predecessor's right child is already linked remove the link add current node to inorder vector and move to the right child
                        prev->right = NULL; //link remove
                        inorder.push_back(curr->val); //print value
                        curr = curr->right;//go right
                    }
                }
            }

            return inorder;
        }

// for pre order there is only one change rest is same - priniting the value change


        vector<int> getPreorder(TreeNode* root){

            // vector to store inorder traversal result
            vector<int> preorder;

            // pointer start with the root node
            TreeNode* curr = root;

            // THE NULL CASE IS SAME AS INORDER

            while(curr!=NULL){

                // case 1: if current node left is empty
                if(curr->left == NULL){
                    // print the node and move to right side
                    preorder.push_back(curr->val);
                    // move to right
                    curr = curr->right;
                }

                else{
                    // case 2
                    // if left child is not null find the predecessor(righnmost node of the left subtree)
                    TreeNode* prev = curr->left;

                    while(prev->right && prev->right !=curr){ //go to right
                        prev = prev->right;
                    }

                    // if predecessor right child is null establish a link(thread) and move to the left child

// THE MAIN CHANGE IN PRINTING

                    if(prev->right == NULL){
                        prev->right = curr;
                        preorder.push_back(curr->val); //print value
                        curr = curr->left; //link created
                    }
                    else{
                        // if predecessor's right child is already linked remove the link add current node to inorder vector and move to the right child
                        prev->right = NULL; //link remove
                       
                        curr = curr->right;//go right
                    }
                }
            }

            return preorder;
        }

};






int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;
    
    vector<int> inorder = sol.getInorder(root);
    vector<int> preoder = sol.getPreorder(root);

    cout << "Binary Tree Morris Inorder Traversal: "<<endl;
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout<<endl;

    cout << "Binary Tree Morris Preoder Traversal: "<<endl;
    for(int i = 0; i< preoder.size(); i++){
        cout << preoder[i] << " ";
    }
    cout << endl;
    
    return 0;
}