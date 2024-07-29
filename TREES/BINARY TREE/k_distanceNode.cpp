/*
863. All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []



*/

#include <bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


/*
Approach: a bit same as burn tree


Create an unordered map mp to store the parent-child relationships of nodes in the binary tree.

Create a queue q and push the root node of the tree into it.

While the queue is not empty, do the following:
    a. Pop a node temp from the front of the queue.
    b. If temp has a left child, push it into the queue and store the parent-child relationship in the map mp.
    c. If temp has a right child, push it into the queue and store the parent-child relationship in the map mp.

Push the target node into the queue q.

Initialize a count variable to 0 and create an empty vector ans to store the nodes at distance k.

Create an unordered map mp1 to keep track of visited nodes.

While the queue is not empty, do the following:
    a. Get the size of the queue and iterate size times.
    b. Pop a node temp from the front of the queue.
    c. Increment the count of temp in the map mp1.
    d. If temp has a left child and it has not been visited before, push it into the queue.
    e. If temp has a right child and it has not been visited before, push it into the queue.
    f. If temp has a parent (mp[temp]), and the parent node has not been visited before, push it into the queue.
    g. If the count is equal to k, add the value of temp to the ans vector.

Increment the count.

If the count is equal to k+1, break out of the loop.
Return the ans vector containing the values of the nodes at distance k from the target node.
*/
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // create map
        unordered_map<TreeNode*, TreeNode*>NodeToParent;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            // if left exists
            if(temp->left){
                q.push(temp->left);
                NodeToParent[temp->left] = temp;
            }

            // if  right exists
            if(temp->right){
                q.push(temp->right);
                NodeToParent[temp->right] = temp;
            }
        }

        q.push(target);

        int count = 0;

        vector<int> ans; //to store the answer

        // create a visited map
        unordered_map<TreeNode*, int>visited;
        while(!q.empty()){

            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();

                // updating the visited map
                visited[temp]++;


                // left
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                }

                // right
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                }

                // parent
                if(!visited[NodeToParent[temp]] && NodeToParent[temp]){
                    q.push(NodeToParent[temp]);
                }

                // check for count
                if(count == k){
                    ans.push_back(temp->val);
                }

            }
            count++;

            // till reaches k
            if(count == k+1) break;
        }
        
        return ans;
    }
};

int main(){
    
    return 0;
}