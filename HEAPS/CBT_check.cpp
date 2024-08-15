// check if the given tree is complete binary tree or not

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  In a complete binary tree, all levels are completely filled except possibly the last level, and all nodes in the last level are as far left as possible.

//  logic : numbering the total nodes of the tree using level order traversal
// if the last node's number (when numbered this way) is equal to the total count of nodes -> it is CBT else not


class Solution{
private:
    int countNodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

public:
    bool isCompleteTree(TreeNode* root){
        if(root == NULL){
            return true;
        }

        int totalNodes = countNodes(root); 
        int count = 0;

        queue<pair<TreeNode* ,int>> q; //making a queue for level order traverssal storing node and its count

        q.push({root,1}); //pushing root and assigning it number 1

        while(!q.empty()){
            TreeNode* current = q.front().first;
            int index = q.front().second;
            q.pop();

            count++; //incrementing the count

            if(current->left){
                // if current ka left exists
                q.push({current->left, 2*index}); // left child index
            }

            if(current->right){
                // if current ka right exists
                q.push({current->right, 2*index + 1}); // right child index
            }

            // If the current node's index is greater than the total number of nodes, return false
            if(index > totalNodes){
                return false;
            }


        }

        // If the loop finishes without returning false, the tree is complete binary tree
        return count == totalNodes;

    }

};


int main(){
    
    return 0;
}