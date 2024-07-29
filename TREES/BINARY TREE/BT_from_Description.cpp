/*
2196. Create Binary Tree From Descriptions
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.

*/

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach 1 : BFS - TC and SC :  O(n)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Sets to track parents and children
        unordered_set<int> parents, children;
        // Map to store parent-child relationships
        unordered_map<int, vector<pair<int, int>>> parentToChild;

        // Building the graph from the descriptions
        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            parents.insert(parent);
            children.insert(child);
            parentToChild[parent].emplace_back(child, isLeft);
        }

        // Finding the root by checking which node is a parent but not a child
        for (auto it = parents.begin(); it != parents.end();) {
            if (children.find(*it) != children.end()) {
                it = parents.erase(it);
            } else {
                ++it;
            }
        }

        // The remaining node in parents is the root
        TreeNode* root = new TreeNode(*parents.begin());

        // Using BFS to construct the binary tree starting from the root
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();
            // Iterating over children of the current parent
            for (auto& childInfo : parentToChild[parent->val]) {
                int childValue = childInfo.first, isLeft = childInfo.second;
                TreeNode* child = new TreeNode(childValue);
                q.push(child);

                // Assign the child to the correct position (left or right)
                if (isLeft == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
        }

        return root;
    }
};


// Approach 2 : DFS
class Solution {
private:
    // Recursive DFS function to build the tree
    TreeNode* dfs(unordered_map<int, vector<pair<int, bool>>>& parentToChild, int val) {
        // Create a new TreeNode with the current value
        TreeNode* node = new TreeNode(val);

        // If the current node has children, recursively build them
        if (parentToChild.find(val) != parentToChild.end()) {
            for (auto& childInfo : parentToChild[val]) {
                int child = childInfo.first;
                bool isLeft = childInfo.second;

                // Recursively build the left or right child based on the isLeft flag
                if (isLeft) {
                    node->left = dfs(parentToChild, child);
                } else {
                    node->right = dfs(parentToChild, child);
                }
            }
        }
        return node;
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Map to store parent-child relationships
        unordered_map<int, vector<pair<int, bool>>> parentToChild;
        // Sets to keep track of parents and children
        unordered_set<int> parents, children;

        // Build the parent-to-child map and track parents and children
        for (auto& d : descriptions) {
            int parent = d[0];
            int child = d[1];
            bool isLeft = d[2];

            parentToChild[parent].push_back({child, isLeft});

            parents.insert(parent);
            children.insert(child);
        }

        // Find the root by identifying the node which is a parent but not a child
        int rootVal = 0;
        for (int node : parents) {
            if (!children.contains(node)) {
                rootVal = node;
                break;
            }
        }

        // Build the tree using DFS starting from the root
        return dfs(parentToChild, rootVal);
    }
};

// Approach 3 : using only map ad set

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Map to store TreeNode pointers keyed by their values
        unordered_map<int, TreeNode*> nodeMap;
        // Set to store values which are children in the descriptions
        unordered_set<int> children;

        // Iterate through descriptions to create nodes and set up the tree
        for (const auto& d : descriptions) {
            // Extract parent, child, and left/right flag values
            int parent = d[0];
            int child = d[1];
            bool isLeft = d[2];

            // Create parent node if it doesn't exist
            if (nodeMap.count(parent) == 0) {
                nodeMap[parent] = new TreeNode(parent);
            }
            // Create child node if it doesn't exist
            if (nodeMap.count(child) == 0) {
                nodeMap[child] = new TreeNode(child);
            }

            // Attach child to the left or right of the parent
            if (isLeft) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }

            // Mark child as a child in the set
            children.insert(child);
        }

        // Find and return the root node
        for (const auto& entry : nodeMap) {
            int value = entry.first;
            TreeNode* node = entry.second;
            // If the value is not found in the children set, it is the root
            if (children.find(value) == children.end()) {
                return node;
            }
        }

        // If no root is found, return nullptr (this shouldn't happen given valid input)
        return nullptr;
    }
};
