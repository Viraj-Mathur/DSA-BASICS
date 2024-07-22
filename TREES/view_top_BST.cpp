/*
Top View of Binary Tree

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105

*/

// Approach  - try finding same as vertical traversal but the mapping should be one-to-one only meaning if for any horizontal mapping there is a node present all the other nodes for the same horizontal mapping will be discarded - logic upar waali node will hide all the neeche waali node


#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Vector to store the result.
        vector<int> ans;
        
        // If the root is NULL, return the empty vector.
        if(root == NULL){
            return ans;
        }
        
        // Map to store the topmost node at each horizontal distance.
        map<int, int> topNode;
        
        // Queue to perform level order traversal.
        // It stores pairs of node and its horizontal distance from the root.
        queue<pair<Node*, int>> q;
        
        // Starting with the root node at horizontal distance 0.
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            // Get the front element of the queue.
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int horizontal_distance = temp.second;
            
            // If there is no node at this horizontal distance in the map,
            // then this node is the topmost node for this horizontal distance.
            if(topNode.find(horizontal_distance) == topNode.end()){
                topNode[horizontal_distance] = frontNode->data;
            }
            
            // If the current node has a left child, add it to the queue
            // with a horizontal distance of (current horizontal distance - 1).
            if(frontNode->left){
                q.push(make_pair(frontNode->left, horizontal_distance - 1));
            }
            
            // If the current node has a right child, add it to the queue
            // with a horizontal distance of (current horizontal distance + 1).
            if(frontNode->right){
                q.push(make_pair(frontNode->right, horizontal_distance + 1));
            }
        }
        
        // Traverse the map and store the result in the vector.
        for(auto i : topNode){
            ans.push_back(i.second);
        }
        
        // Return the result vector.
        return ans;
    }
};


int main(){
  
  return 0;
}