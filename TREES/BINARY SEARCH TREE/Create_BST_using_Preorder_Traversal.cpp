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
// Approach : like the case of validate BST we will consider upperbound in mind when traversing the node

// take first element as node(as preorder) 
// go to left with upperbound as the root node value
// if smaller then root go to left only recursively
// if bigger element found go rigth(with upper bound of node previous then current node)


    // Recursive function to build the BST from preorder traversal
        Node* solve(vector<int>& preorder, int &index, int upperBound){
        // Base case: If all nodes are processed or current node value exceeds the upper bound, return NULL
        if(index == preorder.size() || preorder[index] > upperBound){
            return NULL;
        }

        // Create the current root node with the value at the current index
        Node* root = new Node(preorder[index++]);

        // Recursively build the left subtree. The new upper bound for left subtree is the value of the current root.
        root->left = solve(preorder, index, root->data);

        // Recursively build the right subtree. The new upper bound for right subtree is the previous upper bound.
        root->right = solve(preorder, index, upperBound);

        // Return the root node of the current subtree
        return root;
    }

    // Public function to initialize the index and call the recursive solve function
    Node* bstFromPreorder(vector<int>& preorder) {
        int index = 0;  // Initialize index to track the current position in preorder traversal
        return solve(preorder, index, INT_MAX);  // Start the recursive process with the initial upper bound set to INT_MAX
    }



int main(){
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Node* root = bstFromPreorder(preorder);
    levelOrderTraversal(root);
    return 0;
    
}