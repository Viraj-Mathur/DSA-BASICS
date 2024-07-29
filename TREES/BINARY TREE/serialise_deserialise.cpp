/*
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.



*/


#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Encodes the tree into a single string
    string serialize(TreeNode* root) {
        // Check if root is empty
        if (!root) {
            return "";
        }

        // Initialize empty string to store serialized data
        string s = "";

        // Using queue for level order traversal
        queue<TreeNode*> q;

        // Start with root node
        q.push(root);

        while (!q.empty()) {
            // Get the front node in the queue
            TreeNode* currNode = q.front();
            q.pop();

            // Check if current node is null and for null append '#' to the string
            if (currNode == NULL) {
                s += "#,";
            } else {
                // Append the value of current node to the string
                s += to_string(currNode->val) + ",";

                // Push left child
                q.push(currNode->left);

                // Push right child
                q.push(currNode->right);
            }
        }

        // Return serialized string
        return s;
    }

    // Decode the encoded data to a tree
    TreeNode* deserialize(string data) {
        // Checking if the serialized data is empty
        if (data.empty()) {
            return NULL;
        }

        // Using stringstream to tokenize the serialized data using object
        stringstream s(data);
        string str;

        // Read the root value from the serialized data
        getline(s, str, ','); // Reading each string element separated by commas
        TreeNode* root = new TreeNode(stoi(str)); // Creating the root node

        // Using queue for level order traversal
        queue<TreeNode*> q;

        // Start with root node
        q.push(root);

        // Perform level order traversal to reconstruct the tree
        while (!q.empty()) {
            TreeNode* node = q.front(); // Getting the front node
            q.pop();

            // Read value of the left child
            getline(s, str, ',');

            // If value is not '#', create a new left child and push it in the queue
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read value of the right child
            getline(s, str, ',');

            // If value is not '#', create a new right child and push it in the queue
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

void inorder(TreeNode* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Original Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialization: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}


/*
stringstream in C++ and its Applications

A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input. 

Basic methods are:

    clear()- To clear the stream.
    str()- To get and set string object whose content is present in the stream. 
    operator <<- Add a string to the stringstream object. 
    operator >>- Read something from the stringstream object.


getline (string) in C++

The C++ getline() is a standard library function that is used to read a string or a line from an input stream. It is a part of the <string> header. The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered. While doing so the previously stored value in the string object str will be replaced by the input string if any.
The getline() function can be represented in two ways: 

Syntax:

istream& getline(istream& is, 
           string& str, char delim);

2. Parameters: 

    is: It is an object of istream class and tells the function about the stream from where to read the input from.
    str: It is a string object, the input is stored in this object after being read from the stream.
    delim: It is the delimitation character which tells the function to stop reading further input after reaching this character.
*/