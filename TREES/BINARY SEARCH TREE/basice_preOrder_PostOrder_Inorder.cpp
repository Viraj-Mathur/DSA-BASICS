// preorder postoder and inorder in BST

// CREATION OF BST

// smaller values than root will go at left side and larger values will go at right side

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// CREATION IN BST

Node* insertIntoBST(Node* root, int data) {
    // empty tree
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // not empty tree
    if (root->data > data) {
        // insert in left side
        root->left = insertIntoBST(root->left, data);
    } else {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while (data != -1) { // till data arrives at -1
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // Left 
    inorderTraversal(root->left);
    // Node
    cout<<root->data<<" ";
    // Right
    inorderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // Left 
    postOrderTraversal(root->left);
    // Right
    postOrderTraversal(root->right);
    // Node
    cout<<root->data<<" ";
}

void preOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // Node
    cout<<root->data<<" ";
    // Left 
    preOrderTraversal(root->left);
    // Right
    preOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for Node (-1 to stop):" << endl;
    takeInput(root);
    
   
    cout<<"Inorder Traversal"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal"<<endl;
    postOrderTraversal(root);
    cout<<endl;
    cout<<"Preorder Traversal"<<endl;
    preOrderTraversal(root);

    return 0;
}
