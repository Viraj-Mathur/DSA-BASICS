// DELETING A NODE IN BST

/*
THERE ARE 4 CASES TO DELETE IN BST

CASE 1:
WHEN BOTH CHILD NULL(LEAF NODE) - IN THIS CASE SIMPLY DELETE THE NODE AND RETURN NULL

CASE 2:
WHEN EITHER LEFT OR RIGHT CHILD EXISTS AND OTHER CHILD NULL : RETURN THE CHILD NODE TO THE CURRENT NODE AND DELETE THE CHILD RETURNING IT BY NULL

CASE 3:
WHEN BOTH CHILD EXISTS

REPLACE THE INORDER PRED OR SUCC OF THE CURRENT NODE WITH THE CURRENT NODE AND CHECK AGAIN BY RECURSION AND RETURN NULL


*/


#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertIntoBST(Node *root, int data)
{
    // Empty tree
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if (root->data > data)
    {
        // insert into left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
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

// function to search node
Node *findNode(Node *root, int target)
{
    // Base case
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    // Left
    else if (root->data > target)
    {
        return findNode(root->left, target);
    }
    // Right
    else
    {
        return findNode(root->right, target);
    }
}

// function to find the max element of the node for inorder pred
int findMax(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return -1;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// MAIN : FUNCTION TO DELETE THE NODE

Node *deleteNode(Node *root, int target) {
    // Base case: if the tree is empty, return NULL
    if (root == NULL) {
        return root;
    }

    // If the target node is found
    if (root->data == target) {
        // Case 1: The node is a leaf node (no children)
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }

        // Case 2: The node has only a right child
        else if (root->left == NULL && root->right != NULL) {
            Node *child = root->right; // Replace the node with its right child
            return child;
        }

        // Case 3: The node has only a left child
        else if (root->left != NULL && root->right == NULL) {
            Node *child = root->left; // Replace the node with its left child
            return child;
        }

        // case 4: both child exists

        // replace the node with the maximum node of the left subtree - inorder pred
        // or replace it with minimum node of the right subtree
        else {
            
            // Replace the node's value with the maximum value in the left subtree (inorder predecessor)
            int inorderPred = findMax(root->left);
            root->data = inorderPred;
            // Delete the inorder predecessor node from the left subtree
            root->left = deleteNode(root->left, inorderPred);
            return root;
        }
    }

    // If the target node is greater than the current node, go to the right subtree
    else if (root->data < target) {
        root->right = deleteNode(root->right, target);
    }
    // If the target node is less than the current node, go to the left subtree
    else {
        root->left = deleteNode(root->left, target);
    }

    // Return the (potentially updated) root node
    return root;
}







int main(){
    Node *root = NULL;
    cout << "Enter the data for Node" << endl;
    takeInput(root);
    deleteNode(root, 200);
    levelOrderTraversal(root);
    return 0;
}

// 100 150 200 175 160 140 210 205 190 -1