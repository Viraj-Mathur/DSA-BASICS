/*
1382. Balance a Binary Search Tree

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.


*/

#include <bits/stdc++.h>

using namespace std;

/*
Approach:

Intuition
The goal is to balance a Binary Search Tree (BST) given its root node. To achieve this, we can follow these steps:

Perform an inorder traversal of the given BST to obtain a sorted array of the nodes.
Use the sorted array to construct a new, balanced BST by recursively building the tree from the middle element as the root, 
and the left and right subarrays as the left and right subtrees.

Approach
Inorder Traversal: We perform an inorder traversal of the given BST and store the nodes in a sorted array sortedArr.
Constructing Balanced BST: We then use the sorted array to construct a new, balanced BST. We do this by recursively building 
the tree from the middle element as the root, and the left and right subarrays as the left and right subtrees.

Complexity
Time complexity: O(n)
Space complexity: O(n)
*/


//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
private:
    vector<TreeNode*> sortedArr; // Array to store nodes in sorted order

    // Perform inorder traversal to get nodes in sorted order
    void inorderTraverse(TreeNode* root) {
        if (root == nullptr) return; // Base case: if node is null, return
        inorderTraverse(root->left); // Traverse left subtree
        sortedArr.push_back(root);   // Add current node to sorted array
        inorderTraverse(root->right); // Traverse right subtree
    }

    // Convert sorted array to balanced BST
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return nullptr; // Base case: invalid range
        
        int mid = start + (end - start) / 2; // Calculate middle index
        TreeNode* root = sortedArr[mid];    // Create root from middle element
        
        root->left = sortedArrayToBST(start, mid - 1);  // Recursively build left subtree
        root->right = sortedArrayToBST(mid + 1, end);   // Recursively build right subtree
        
        return root; // Return the root of the balanced subtree
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        sortedArr.clear(); // Clear the vector before use
        inorderTraverse(root); // Perform inorder traversal to get sorted nodes
        return sortedArrayToBST(0, sortedArr.size() - 1); // Convert sorted array to balanced BST
    }
};

// Helper function to print the tree in-order
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create an unbalanced BST
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    std::cout << "Original unbalanced BST (in-order): ";
    printInOrder(root);
    std::cout << std::endl;

    Solution solution;
    TreeNode* balanced_root = solution.balanceBST(root);

    std::cout << "Balanced BST (in-order): ";
    printInOrder(balanced_root);
    std::cout << std::endl;

    // Note: In a real-world scenario, you should also implement a function to delete the tree and free memory

    return 0;
}