/*
662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
*/

#include <bits/stdc++.h>

using namespace std;


// use level order traversal as we need width and level order traverses width 
// index every nodes as 1,2,3.. therefore for every level - the width will be the differences of starting and ending node of that levels


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        // if the root is null width is 0

        if(!root){
            return 0;
        }

        // variable to store the max width
        int ans = 0;

        // queue to perform level order traversal which will have node and its perticular index
        queue<pair<TreeNode*,int>> q;

        // push the root node and its index in the queue
        q.push({root,0});

        // perform level order traversal

        while(!q.empty()){
            // get number of nodes in that perticular level
            int size = q.size();

            // get position of the front node
            int min_index = q.front().second;

            // store first and last index of the current level

            int first,last;

            for(int i=0;i<size;i++){
                // calculate current position relative to the minimum position - to avoid overflow
                int curr_index = q.front().second - min_index;

                // get the current node
                TreeNode* node = q.front().first;

                // pop the front node from the queue
                q.pop();

                // if it is the first node in this level update first variable
                if(i==0){
                    first = curr_index;
                } 

                // if it is the last node in the level, update the lasr variable
                if(i==size-1){
                    last = curr_index;
                }

                // now push the left child in the queue to process
                if(node->left){
                    q.push({node->left, curr_index*2+1}); //indexing is done using the formula

                }

                // now push the right child in the queue to process
                if(node->right){
                    q.push({node->right, curr_index*2+2}); //indexing is done using the formula

                }

            }

            // Update the maximum width by calculating
            // the difference between the first and last
            // positions, and adding 1
            ans = max(ans, last - first + 1);
        }


        return ans;
    }
};


// SPACE AND TIME COMPLEXITY IS O(n)

int main(){
    
    return 0;
}