/*
Binary Tree from Inorder and Postorder

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Examples:

Input: n = 8, in[] = [4, 8, 2, 5, 1, 6, 3, 7], post[] = [8, 4, 5, 2, 6, 7, 3, 1]
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8
Input: n = 5, in[] = [9, 5, 2, 3, 4], post[] = [5, 9, 3, 4, 2]
Output: 2 9 5 4 3
Explanation: The  resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3

*/

// hint: same code as of inorder and preorder but now have to check that root will be the last element of the postorder element 

#include <bits/stdc++.h>

using namespace std;

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
    // Function to create a mapping from node value to its index in the inorder traversal
    void createMapping(const vector<int>& inorder, unordered_map<int, int>& nodeToIndex) {
        for (int i = 0; i < inorder.size(); ++i) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    // Recursive function to construct the binary tree
    TreeNode* solve(const vector<int>& inorder, const vector<int>& postorder, int& index, int inorderStart, int inorderEnd, const unordered_map<int, int>& nodeToIndex) {
        // Base case: if the current index is out of bounds or the start exceeds the end, return nullptr
        if (index < 0 || inorderStart > inorderEnd) {
            return nullptr;
        }

        // Get the current element from postorder and decrement the index
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        // Find the position of the current element in the inorder traversal
        int position = nodeToIndex.at(element);

        // Recursively construct the right and left subtrees
        root->right = solve(inorder, postorder, index, position + 1, inorderEnd, nodeToIndex);
        root->left = solve(inorder, postorder, index, inorderStart, position - 1, nodeToIndex);

        return root;
    }

public:
    // Main function to build the tree from inorder and postorder traversals
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIndex = postorder.size() - 1; // Start from the last index of the postorder vector
        unordered_map<int, int> nodeToIndex; // Map to store the index of each node in inorder traversal
        createMapping(inorder, nodeToIndex); // Create the mapping

        // Construct the binary tree and return the root node
        return solve(inorder, postorder, postOrderIndex, 0, inorder.size() - 1, nodeToIndex);
    }
};

// Utility function to print the tree in inorder traversal (for testing purposes)
void printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Main function to test the solution
int main() {
    Solution solution;

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = solution.buildTree(inorder, postorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}