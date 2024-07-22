/*
Right View of Binary Tree

Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side. Return the right view as a list. 

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Examples :

Input:
       1
    /    \
   3      2
Output: 1 2
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105

*/

#include <bits/stdc++.h>

using namespace std;

// SAME AS LEFT VIEW JUST CHANGE THE ORDER OF RECURSION

class Solution
{
    private:
    
    void solve(Node *root, vector<int> &ans, int level){
    
    // base case
    if(root == NULL){
        return ;
    }
    
    // we enter into a new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    // JUST CHANGE THE ORDER 
    
    // this will print right to left
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
    
}
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }
};

int main(){
    
    return 0;
}