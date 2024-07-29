// Kth largest/smallest element in Binary Search Tree

// Problem Statement: Given a Binary Search Tree and an integer ‘K’. Find and return the ‘K-th’ smallest and ‘K-th’ largest element in the given Binary Search Tree.


// APPROACH 1: STORE INORDER - GET SORTED ELEMENTS AND FIND SMALLEST ELEMENT BY INDEXING - O(n)
// Kth smallest element by accessing the element at index k-1 in the array considering array indices start from 0. Similarly to determine the Kth largest element, we can access it at index array.length - k.


// APPROACH 2: USE INORDER TRAVERSAL ANS STORE K AS GIVEN WHENEVER PRINT ROOT DO K-- TILL K BECOMES 0 TO GET THE REQUIRED RESULT
// LOGIC SAME AS KTH ANCESTOR IN BINARY TREE

// FOR KTH LARGEST USE REVERSE INORDER TRAVERSAL : R N L


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
    int kthSmallest(TreeNode* root, int &k) {
        
        // BASE CASE
        if(root == NULL){
            return -1;
        }

        // inorder traversal with keeping track of k when priniting node decrement k

        // L
        int leftAns = kthSmallest(root->left, k);

        // if valid answer exists in left side
        if(leftAns !=-1){
            return leftAns;
        }

        // N (while decrementing k)
        k--;
        if(k==0){
            return root->val;
        }

       

        // R
        int rightAns = kthSmallest(root->right, k);

        return rightAns;
        
    }

    int kthLargest(TreeNode* root, int& k) {
        if (root == NULL) {
            return -1;
        }

        // R
        int rightAns = kthLargest(root->right, k);
        if (rightAns != -1) {
            return rightAns;
        }


        // N (while decrementing k)

        k--;
        if (k == 0) {
            return root->val;
        }

        // L
        return kthLargest(root->left, k);
    }


    pair<int, int> findKthElements(TreeNode* root, int k) {
        int k1 = k;
        int KthSmallest = kthSmallest(root, k1);
        k1 = k;
        int KthLargest = kthLargest(root, k1);
        return {KthSmallest, KthLargest};
    }
};



// Function to perform an in-order traversal
// of a binary tree and print its nodes
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

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;
    
    Solution solution;

    int k = 3; 
    cout << "k: " << k << endl;
    pair<int, int> kthElements = solution.findKthElements(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}