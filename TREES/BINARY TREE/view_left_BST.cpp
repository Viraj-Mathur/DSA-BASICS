/*
Left View of Binary Tree

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
0 <= Data of a node <= 1000

*/

// HINT : print the first node of each level from the left side - track level to know the node to print

#include <bits/stdc++.h>

using namespace std;

void solve(Node *root, vector<int> &ans, int level){
    
    // base case
    if(root == NULL){
        return ;
    }
    
    // we enter into a new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    // this will print left to right
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}



int main(){
    
    return 0;
}