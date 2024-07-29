/*
Flatten a binary tree into linked list

Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. 
After flattening, left of each node should point to NULL and right should contain next node in preorder.

Examples: 

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

Input :
        1
       / \
      3   4
         /
        2
         \
          5
Output :
     1
      \
       3
        \
         4
          \
           2
            \ 
             5

*/


#include <bits/stdc++.h>

using namespace std;


// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{

    

    public:
        // initialise prev to keep track of previously node 
        TreeNode* prev = NULL;


        // Approach 1 : recursion : reverse of R L N (perform a reverse pre-order traversal) - initialise a global variable `prev` to keep track of the previously processed node. Initially set it to null.

        // Time Complexity: O(N) Space Complexity : O(log2N)
        void flatten(TreeNode* root){
            // base case: if current node is null

            if(root==NULL){
                return;
            }

            // R
            flatten(root->right);

            // L
            flatten(root->left);

            

            // when both right and left tree is flatten and prev is pointing to rightmost node in flatten right subtree

            // set right child of current node to prev
            root->right = prev;

            // set left child of current node to current node to NULL.
            root->left = NULL;

            // N
            prev = root;
        }


        // Approach 2: using stack  : iteratively put the node in a stack then put its right then left node along with it. pop the latest node and mark it as right of the current node and so on
        // Time Complexity: O(N) Space Complexity : O(N)        
        void flatten2(TreeNode* root){
            if(root == NULL){
                return;
            }

            // use stack for iterative traversal
            stack<TreeNode*>st;

            st.push(root);

            // continue till stack becomes empty
            while(!st.empty()){
                // get the top node from the stack
                TreeNode* curr = st.top();
                // pop it
                st.pop();

                // push right child

                if(curr->right!=NULL){
                    st.push(curr->right);
                }

                // then push left child

                if(curr->left!=NULL){
                    st.push(curr->left);
                }

                if(!st.empty()){
                    // connect the right child to the next node in the stack
                    curr->right = st.top(); //MAKE THE POPPED ELEMENT AS THE RIGHT SIDE OF THE TREE
                }

                // SET ALL THE LEFT NODE TO NULL OF TREE
                curr->left = NULL;
            }
        }


        // Approach 3: using MORRIS TRAVERSAL - in the left subtree whichever is the last node connect it to the right of the node. 
        /*
        Algorithm
            Step 1: Start with the current node as the root of the tree.

            Step 2: While the current node is not null we traverse the tree in a while loop:

            If the current node has a left child:
            Find the rightmost node in the left subtree.
            Connect the rightmost node of the left subtree to the current node’s right child.
            Update the current node’s right child to be its left child.
            Set the current node’s left child to null.
            Move to the current node’s right child.
            If the current node has no right child:
            Move to the current node’s left child (if it exists) or null.
            Step 3: Repeat until all nodes are processed.
        

        Time Complexity: O(2N) Space Complexity: O(1)
        */ 


       void flatten3(TreeNode* root){
        
            // initialising a pointer curr to the root node
            TreeNode* curr = root;

            // iterate untill curr becomes NULL
            while(curr){
                // check if left child exists

                if(curr->left){
                    // if exist find the rightmost subtree
                    TreeNode* pre = curr->left;

                    while(pre->right){
                        pre = pre->right;
                    }

                    // connect the rightmost node in left subtree to node right child using thread or link
                    pre->right = curr->right;

                    // move entire left subtree to the right child of the current node
                    curr->right = curr->left;

                    curr->left = nullptr; // clear the left child
                }

                // move the next node to the right side
                curr = curr->right;
            }

       }



        
};







// Print the preorder traversal of the
// Orignal Binary Tree
void printPreorder(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the 
// Right Pointers after Flattening
void printFlattenTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    cout<<"Approach 1"<<endl;
    
    sol.flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    cout<<"Approach 2"<<endl;
    
    sol.flatten2(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    cout<<"Approach 3"<<endl;
    
    sol.flatten3(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    

    return 0;
}
         