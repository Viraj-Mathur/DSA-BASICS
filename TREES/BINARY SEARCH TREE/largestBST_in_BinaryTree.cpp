/*
largest binary search tree in a binary tree

Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).
*/

#include <bits/stdc++.h>

using namespace std;


// APPROACH 1 : BRUTE FORCE-> FIND THE INORDER AND FIND ALL THE SUBSETS WHICH ARE IN SORTED ORDER THEN FIND MAX OF THOSE SUBSETS

// APPROACH 2 : BOTTOM UP APPROACH

/*
RECURSION CALL ORDER : L R N

GO TO LEFT AND CHECK BOOLEAN FLAG OF IF LEFT PART IS BST AND ALSO TAKE SIZE(TO BE ADDED LATER WITH THE CURRENT NODE) -> SIMILARLY DO THE SAME FOR RIGHT SUBTREE

ALSO CHECK IF CURRENT NODE HAS VALUE MAXIMUM THEN THEN MAX VALUE IN LEFT SUBTREE AND HAS VALUES MINIMUM THEN THE MIN VALUE OF RIGHT SUBTREE

// SO RETURN 4 THINGS : SIZE,MIN VALUE, MAX VALUE, VALID BST EXISTS FOR BOTH LEFT AND RIGHT SUBTREE

*/


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

class NodeData{
    public:
    // basic requirements
        int size;
        int minVal;
        int maxVal;
        bool validBST;
        NodeData() : size(0), minVal(INT_MAX), maxVal(INT_MIN), validBST(true) {}
        // calling them for constructor
        NodeData(int size, int min, int max, bool valid) : size(size), minVal(min), maxVal(max), validBST(valid) {}
};


// MAIN FUNCTION!!!

NodeData findLargestBST(Node* root, int &ans) {
    // Base case
    if (root == NULL) {
        NodeData temp(0, INT_MAX, INT_MIN, true); // case when encounter the null node in leaf
        return temp;
    }

    // find the left subtree
    NodeData leftAns = findLargestBST(root->left,ans);

    // find the right subtree
    NodeData rightAns = findLargestBST(root->right,ans);

    // current node
    NodeData currNode;

    // now find the requirements

    // check for size
    currNode.size = leftAns.size + rightAns.size + 1; // 1 is added for the current node 
    // check for min and max values
    currNode.maxVal = max(root->data, rightAns.maxVal);
    currNode.minVal = min(root->data, leftAns.minVal);

    // validate that left and right subtree are bst or not

    if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
        currNode.validBST = true; //make flag true
    }
    else{
        currNode.validBST = false; // make flag false;
    }

    if(currNode.validBST){
        ans = max(ans,currNode.size); //if all follows return ans 
    }
    return currNode;

}

int main() {
    Node* root = new Node(6);
    Node* first = new Node(6);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(1);
    Node* fifth = new Node(3);
    root->left = first;
    root->right = second;
    first->right = third;
    second->left = fourth;
    second->right = fifth;

    int ans = 0;
    findLargestBST(root, ans);
    cout << "Largest BST size = " << ans << endl;
    return 0;
}