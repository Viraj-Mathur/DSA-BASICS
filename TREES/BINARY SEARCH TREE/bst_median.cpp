// to find median in bst

// approach : find number of elements using morris traversal and then find desired element using morris traversal

#include <bits/stdc++.h>

using namespace std;


// Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// your task is to complete the Function
// Function should return median of the BST

int getNodeLength_Morris(Node* root){
    
            int count = 0;


            // pointer start with the root node
            Node* curr = root;

            while(curr!=NULL){

                // case 1: if current node left is empty
                if(curr->left == NULL){
                    // print the node and move to right side
                    count++;
                    // move to right
                    curr = curr->right;
                }

                else{
                    // case 2
                    // if left child is not null find the predecessor(righnmost node of the left subtree)
                    Node* prev = curr->left;

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
                        count++; //print value
                        curr = curr->right;//go right
                    }
                }
            }

            return count;
        }
        
        
float findMedian_Morris(Node* root, int n){
    
            int i=0;
            
            // median element when n is odd  = (n+1)/2 th term
            // median element when n is even =  (n/2 + (n)/2 + 1)/2
            
            int odd = (n+1)/2, // odd term
            oddVal = -1; //initialise
            
            int even1 = n/2, // even term
            even1Val = -1; //initialise
            
            int even2 = n/2+1, // even term
            even2Val = -1; //initialise

            // pointer start with the root node
            Node* curr = root;

            while(curr!=NULL){

                // case 1: if current node left is empty
                if(curr->left == NULL){
                    // print the node and move to right side
                    i++;
                    if(i == odd) oddVal = curr->data;
                    if(i == even1) even1Val = curr->data;
                    if(i == even2) even2Val = curr->data;
                    
                    // move to right
                    curr = curr->right;
                }

                else{
                    // case 2
                    // if left child is not null find the predecessor(righnmost node of the left subtree)
                    Node* prev = curr->left;

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
                        i++;
                        if(i == odd) oddVal = curr->data;
                        if(i == even1) even1Val = curr->data;
                        if(i == even2) even2Val = curr->data;
                        curr = curr->right;//go right
                    }
                }
            }
            
            float median = 0.0;
            
            if (n % 2 == 0) {
        return (even1Val + even2Val) / 2.0;
    } else {
        return oddVal;
    }
        }
        
        
float findMedian(struct Node *root)
{
      //Code here
      int n  = getNodeLength_Morris(root);
      
      return findMedian_Morris(root,n);
}