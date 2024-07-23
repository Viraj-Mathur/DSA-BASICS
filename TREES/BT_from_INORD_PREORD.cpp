/*
Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal
 of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

*/

#include <bits/stdc++.h>


using namespace std;

// Definition for the binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
private:

    // finding position in O(N)
        // int findPosition(int in[], int element,int n){
        //     for(int i=0;i<n;i++){
        //         if(in[i] == element) return i;
        //     }
        //     return -1;
        // }
        
    // Creating mapping in O(N)
    void createMapping(int in[], multimap<int, int> &nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex.insert({in[i], i});
        }
    }

    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, multimap<int, int> &nodeToIndex) {
        // Base case: if index exceeds the size or the start is greater than the end
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        // Find the root element from PreOrder
        int element = pre[index++];
        Node* root = new Node(element);

        // // Find the position of the root element in the inorder array
        // int position = nodeToIndex[element];
        // Find the position of the root element in the inorder array
        
        auto positionIter = nodeToIndex.find(element);
        int position = positionIter->second;
        nodeToIndex.erase(positionIter); // Erase the used entry to handle duplicates

        // Recursively build the left and right subtrees
        root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);

        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        int preOrderIndex = 0;
        multimap<int, int> nodeToIndex; // Create a mapping of node values to their indices in the inorder array

        createMapping(in, nodeToIndex, n);

        // Construct the tree using the solve function
        Node* ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};

// Helper function to print InOrder traversal (for testing purposes)
void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    Solution obj;
    int in[] = {7, 3, 11, 1, 17, 3, 18};
    int pre[] = {1, 3, 7, 11, 3, 17, 18};
    int n = sizeof(in) / sizeof(in[0]);
    
    Node* root = obj.buildTree(in, pre, n);

    // Print InOrder traversal of the constructed tree
    printInOrder(root);
    return 0;
}

// 7
// 7 3 11 1 17 3 18
// 1 3 7 11 3 17 18