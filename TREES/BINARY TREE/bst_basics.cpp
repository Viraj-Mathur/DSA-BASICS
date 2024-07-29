#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data; // Defining the value of the node (integer data)

    Node* left; // Reference pointer to the left child node

    Node* right; // Reference pointer to the right child node

    Node(int val){ //Method to initialize the node with a value
        data = val; // Set the value of the node to the passed integer
        
        left = right = NULL; // Initialize left and right ight pointers as NULL
    }
};

int main(){

    Node* root = new Node(1);

    // Creating left and right child
    // nodes for the root node

    root->left = new Node(2);
    root->right = new Node(3);

    // Creating a right child node for
    // the left child node of the root
    root->left->right = new Node(5);

    
    return 0;
}