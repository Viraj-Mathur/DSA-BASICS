#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a tree recursively
Node* buildTree(Node* root) {
    cout << "Enter Data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;  // return -1 if you don't want to give a value
    }

    // Entering values through recursion
    cout << "Enter data for inserting in Left of  " << data << endl;
    root->left = buildTree(root->left);

    cout << "Entering data for inserting in Right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// Level Order Traversal using a queue
void LevelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    // For displaying the tree structure with spaces
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Inorder traversal: Left, Node, Right
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal: Node, Left, Right
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left, Right, Node
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Function to build a tree from level order input
void buildFromLevelOrder(Node*& root) {
    queue<Node*> q;
    cout << "Enter Data for the root: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

// Function to calculate the maximum depth of the tree
int maxDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

// Function to calculate the minimum depth of the tree
int minDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    // If a node has only one child, return the depth of the non-empty child
    if (root->left == NULL || root->right == NULL) {
        return max(leftDepth, rightDepth) + 1;
    }

    return min(leftDepth, rightDepth) + 1;
}

// Function to delete a node in the tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    Node* root = NULL;

    // Uncomment the following line to build the tree from level order input
    // buildFromLevelOrder(root);

    // Print the level order of traversal output
    cout << "Print the level order of traversal output: " << endl;
    LevelOrderTraversal(root);

    // Inorder Traversal
    cout << "Inorder Traversal is: " << endl;
    inorder(root);
    cout << endl;

    // Postorder Traversal
    cout << "Postorder Traversal is: " << endl;
    postorder(root);
    cout << endl;

    // Preorder Traversal
    cout << "Preorder Traversal is: " << endl;
    preorder(root);
    cout << endl;

    // Calculate and print the minimum and maximum depth of the tree
    cout << "Minimum Depth: " << minDepth(root) << endl;
    cout << "Maximum Depth: " << maxDepth(root) << endl;

    // Example of deleting a node (uncomment and modify as needed)
    // int keyToDelete;
    // cout << "Enter the key to delete: ";
    // cin >> keyToDelete;
    // root = deleteNode(root, keyToDelete);

    return 0;
}
