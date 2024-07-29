/*
Given a Binary Search Tree and a ‘key’ value which represents the data data of a node in this tree. Return the inorder predecessor and successor of the given node in the BST.

The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. Return nullptr if the given node is the one that is visited first in the inorder traversal.
The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. Return nullptr if the given node is visited last in the inorder traversal.
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


void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}





// Approach 1 : perform inorder traversal and find left and right of the perticular element

// inorder using morris traversal

class Solution1 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;

        while(root!=NULL){
            // If the current node value is
            // greater than the given node 'p'
            if(root->val > p->val){
                // update the successor and move to the left subtree
                successor = root;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }

        return successor;
    }


};


/*
 Approach 2: 
 for inorder successor - SAME FOR PREDECESSOR JUST OPPOSITE

If the current node value is smaller than the key, move to its right child.
If the current node value is greater than the key, update ‘successor’ as the minimum between the current ‘successor’ value and the current node value then move to its left subtree.

*/

class Solution {
public:

// function for finding successot
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        // initialise successor to null
        TreeNode* successor = NULL;

        // traverse till root is not null
        while(root!= NULL){

            // if p value is greater or equal to the current root's value - that means inorder successor is on right side(greater)
            if(p->val >= root->val){
                // go right
                root = root->right;
            }
            else{
                // if p is smaller move to left subtree and update the successor to the current root and traverse left
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }



    // function to find the predecessor
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
            
            // initialise successor to null
            TreeNode* predecessor = NULL;

            // traverse till root is not null
            while(root!= NULL){

            // if p value is greater than the current root's value - that means inorder predecessor could be the current root or in the right subtree
            if (p->val > root->val) {
                // update predecessor to the current root
                predecessor = root;
                // go right
                root = root->right;
            } 
            
            else {
                // if p is smaller or equal, move to left subtree
                root = root->left;
            }
            }

            return predecessor;
        }

};






int main(){
    
Solution solution;

    // Constructing the BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(10);
    
    cout << "BST: ";
    printInOrder(root);
    cout << endl;
    
    // Node for which we want to
    // find the inorder successor
    TreeNode* p = root->right;
    
    // Find the inorder successor
    TreeNode* successor = solution.inorderSuccessor(root, p);
    TreeNode* predecessor = solution.inorderPredecessor(root, p);
    
    // Print the inorder successor's value
    if (successor != nullptr) {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } else {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    // Print the inorder predecessor's value
    if (predecessor != nullptr) {
        cout << "Inorder Predecessor of " << p->val << " is: " << predecessor->val << endl;
    } else {
        cout << "Inorder Predecessor of " << p->val << " does not exist." << endl;
    }
    
    return 0;
}
    