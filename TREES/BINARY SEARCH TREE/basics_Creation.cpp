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

// level order traversal to check

void levelOrderTraversal(Node *root) {
    // Empty tree
    if (root == NULL) {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty()) {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            // left child exists
            if (temp->left) {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for Node (-1 to stop):" << endl;
    takeInput(root);
    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);
    return 0;
}
