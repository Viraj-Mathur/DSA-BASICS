/*
Children Sum in a Binary Tree

Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. 
Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, data value must be equal to the sum of data values in left and right children. 
Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Example 1:

Input:
Binary tree
       35
      /   \
     20  15
    /  \  /  \
   15 5 10 5

Output: 
1

Explanation: 
Here, every node is sum of its left and right child.

Example 2:

Input:
Binary tree
       1
     /   \
    4    3
   /  
  5    

Output: 
0

Explanation: 
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.

*/


#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     // Base case: if the node is NULL or it's a leaf node, return true
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return 1;
        }

        int left_data = 0, right_data = 0;

        // If the left child is not null, get its data
        if (root->left != NULL) {
            left_data = root->left->data;
        }

        // If the right child is not null, get its data
        if (root->right != NULL) {
            right_data = root->right->data;
        }

        // Check if the current node's data is equal to the sum of its children
        // and recursively check for left and right subtrees
        if (root->data == left_data + right_data &&
            isSumProperty(root->left) &&
            isSumProperty(root->right)) {
            return 1;
        } else {
            return 0;
        }
    }
    
    
    
};


// leetcode : 2236. Root Equals Sum of Children : You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child. Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

class Solution {
public:
    bool checkTree(TreeNode* root) {
        int sum = 0;
        sum = root->left->val + root->right->val; 
        if(root->val == sum){
            return true;
        }
        return false;
    }
};


// STRIVER - TO CONVERT ANY BINARY TREE INTO SOMETHING THAT FOLLOWS CHILDREN SUM PROPERTY BY INCREASING THE VALUE OF THE NODE BY 1 AS MANY TIMES AS NEEDED
// REDUCTION IS NOT ONLY INCREMENT - https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/

/*
ALGO: 

Compare the sum of the children (child) with the current node's value.

If the sum of children is greater than or equal to the current node's value, we update the value of the parent to the sum of the children.

If the sum of children is smaller than the current node's value, we need to make an adjustment to ensure the property holds. 
However, remember that we cannot decrease the value of any node. So, instead, we update one of the children's values to match the current node's value.

IF CHILD NODE IS SMALLER MAKE IT EQUAL TO PARENT 
IF CHILD NODE EQUAL WE MAKE THE PARENT NODE EQUAL TO THE SUM OF CHILD NODES


*/

class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root) {
        // Base case: If the current node
        // is NULL, return and do nothing.
        if (root == NULL) {
            return;
        }

        // Calculate the sum of the values of
        // the left and right children, if they exist.
        int child = 0;
        if (root->left) {
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }

        // Compare the sum of children with
        // the current node's)ROOT) value and update
        if (child >= root->val) {
            root->val = child;
        } else {
            // If the sum is smaller, update the
            // child with the current node's value.
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }

        // Recursively call the function
        // on the left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the
        // values of the left and right
        // children, if they exist.
        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }

        // If either left or right child
        // exists, update the current node's
        // value with the total sum.
        if (root->left or root->right) {
            root->val = tot;
        }
    }
};




int main(){
    
    return 0;
}