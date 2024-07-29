/*
Burning Tree
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.



Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.


Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.


Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

*/
#include <bits/stdc++.h>

using namespace std;

// hint : node can burn its left side and right side as well as its parent as there is no pointer for parent we will create a mapping between parent and the node using level order traversal
// then find the target node then start burning using bfs (take a visited array and a queue to track and track time )

class Solution {
  private:
      
    //   create mapping and return target node
    
    Node* createParentMapping(Node* root, int target,map<Node*,Node*> &nodeToParent){
        // use level order traversal for mapping
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        
        // as root parent is null
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        
        return res;
        
    }
    
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent){
        map<Node*,bool>visited;
        queue<Node*>q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        while(!q.empty()){
            
            
            // flag is needed to check the addition in time if there is an addition mark flag as true
            
            bool flag = false;
            
            int size = q.size();
            for(int i=0;i<size;i++){
                // processing neighbouring nodes to burn
                Node* front = q.front();
                q.pop();
                
                // traversing left side
                
                if(front->left && !visited[front->left]){
                    // as addition is done here
                    flag = true;
                    
                    q.push(front->left);
                    visited[front->left] = 1; //mark current node visited
                }
                
                // traversing right side
                if(front->right && !visited[front->right]){
                    // as addition is done here
                    flag = true;
                    
                    q.push(front->right); //push it in a queue
                    visited[front->right] = 1; //mark the current node visited
                }
                
                // traversing parent
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    // as addition is done here
                    flag = true;
                    
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;//mark current node visited
                }
            }
            
            if(flag == true){
                ans++;
            }
        }
        return ans;
        
    }
    
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        map<Node*,Node*>nodeToParent;
        Node* targetNode = createParentMapping(root,target,nodeToParent);
        
        int ans = burnTree(targetNode,nodeToParent);
        
        return ans;
    }
};

// TC - O(N LOG N)
// SC = O(N

int main(){
    
    return 0;
}


// SAME QUESTION IN LEETCODE : 2385. Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/