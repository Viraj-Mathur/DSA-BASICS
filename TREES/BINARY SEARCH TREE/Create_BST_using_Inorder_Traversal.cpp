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

// To print the tree level wise
void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


// MAIN CODE
// TO MAKE BST USING INORDER TRAVERSAL : MIDDLE POINT ELEMENT WILL BE ROOT AND ITS LEFT WILL BE LEFT CHILD AND RIGHT WILL BE RIGHT CHILD
// MAKE RECURSION CALL EVERYTIME FOR LEFT AND RIGHT CHILD

Node* BSTInorder(int inorder[], int start, int end){
    // base case
    if(start > end){
        return NULL;
    }

    // finding the middle element
    int mid = start + (end-start)/2;
    int element = inorder[mid]; 
    
    Node* root = new Node(element);//middle element will be the root
    
    // call for left subtree
    root->left = BSTInorder(inorder,start,mid-1);

    // call for right subtree
    root->right = BSTInorder(inorder,mid+1,end);

    return root;
}

int main(){
    int inorder[] = {10,20,30,40,50,60,70,80,90};
    int s = 0;
    int e = 8;
    Node* root = BSTInorder(inorder,s,e);
    levelOrderTraversal(root);
    return 0;
    return 0;
}