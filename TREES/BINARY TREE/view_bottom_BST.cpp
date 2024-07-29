/*
Bottom View of Binary Tree

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Your Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView() which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

Expected Time Complexity: O(N*logN).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

*/

#include <bits/stdc++.h>

using namespace std;

// the question is same as top view but now we don't need the condition as the map should overwrite the values and give result of the latest value that would be the bottom view

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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

            // CHANGE HERE
            
            // no neeed for this condition now
            // // If there is no node at this horizontal distance in the map,
            // // then this node is the topmost node for this horizontal distance.
            // if(topNode.find(horizontal_distance) == topNode.end()){
            //     topNode[horizontal_distance] = frontNode->data;
            // }
            topNode[horizontal_distance] = frontNode->data;
            
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