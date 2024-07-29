// program for searching in binary search tree

#include <bits/stdc++.h>

using namespace std;


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
Node* insertIntoBST(Node* root,int data){
    // Empty tree
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if(root->data > data){
        // insert into left
        root->left = insertIntoBST(root->left,data);
    }
    else{
        // insert into right
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}


// code for searching

bool search(Node* root, int target){
    // base case
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }

    // check for left

    else if(root->data > target){
        return search(root->left, target);
    }

    // check for right

    else{
        return search(root->right, target);
    }
}

int main(){
    
    Node* root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);
    if(search(root,175)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}