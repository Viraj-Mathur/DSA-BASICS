/*
Root to Leaf Paths

Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3

Output: 
1 2 
1 3 

Explanation: 
All possible paths:
1->2
1->3


Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60

Output: 
10 20 40 
10 20 60 
10 30 

*/

#include <bits/stdc++.h>

using namespace std;

// During the recursive calls, we append the current node’s data value to the vector and explore the left and right children. We backtrack if the target value is not found as the children return ‘false’ and remove the last node from the path vector. In the end, we return the vector containing the path from the root to the given node.

// traverse using inorder sequence
// f the current node is null then we return false, indicating the end of the path. If the current node’s data value is equal to the given node then we return the true, signifying the completion of the path.


/*
Step 3: Recursive Calls:

During the recursive exploration, the recursive function appends the current node's data value to the vector arr.
It checks if the current node's value matches the target value x. If it does, the function returns true, indicating the completion of the path to the target node.
We then call the function on the left and right children of the current node.

Step 4: Backtracking:

If the target value x is not found in the current path, the function backtracks by removing the last node from the path vector arr.
This means the current node is not part of the valid path from the root to the given node ensuring that the algorithm explores all possible paths and doesn't miss any valid routes to the target node.

*/

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    

};

int main(){
    
    return 0;
}