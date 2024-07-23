/*
Sum of nodes on the longest path from root to leaf node

Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

Example 1:

Input: 
         4        
       /   \       
      2     5      
     / \   / \     
    7   1 2   3    
       /
      6
Output: 
13
Explanation:
         4        
       /   \       
      2     5      
     / \   / \     
    7   1 2   3  
       /
      6
The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 
11
Explanation:
Use path 1->3->7, with sum 11.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // Recursive function to solve the problem
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLength) {
        // base case: if the node is NULL
        if (root == NULL) {
            // if the current path length is greater than the maxLength found so far
            if (len > maxLength) {
                maxLength = len; // update maxLength
                maxSum = sum; // update maxSum with the sum of the current path
            } 
            // if the current path length is equal to the maxLength found so far
            else if (len == maxLength) {
                maxSum = max(sum, maxSum); // update maxSum with the maximum of the two sums
            }
            return;
        }
        
        // Add the current node's data to the sum
        sum += root->data;
        
        // Recur for the left subtree
        solve(root->left, sum, maxSum, len + 1, maxLength);
        
        // Recur for the right subtree
        solve(root->right, sum, maxSum, len + 1, maxLength);
    }

public:
    // Function to return the sum of the longest root to leaf path
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0; // Initial length of the path
        int maxLength = 0; // Variable to store the maximum length of the path found so far
        
        int sum = 0; // Initial sum of the path
        int maxSum = INT_MIN; // Variable to store the maximum sum of the path found so far
        
        // Call the recursive solve function
        solve(root, sum, maxSum, len, maxLength);
        
        return maxSum; // Return the maximum sum
    }
};


int main(){
    
    return 0;
}