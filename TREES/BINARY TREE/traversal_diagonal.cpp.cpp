/*
Diagonal Traversal of Binary Tree

Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4

*/

#include <bits/stdc++.h>

using namespace std;

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


// approach 1 - using map
// hint : when going left +1 when going right do nothing
/*
0 -> 8 ,10,14
1-> 3,6,7,13
2 - > 1,4
*/

//  time complexity of this solution is 𝑂(𝑁 log N) and The space is 𝑂(𝑁)


void solve(Node *root, int d, map<int,vector<int>> &diag) {
    // base case
    if (!root) {
        return;
    }

    // store all nodes in the same line together with corresponding to the value of d
    diag[d].push_back(root->data);

    // increase the vertical distance d for the left child
    solve(root->left, d+1, diag);

    // do nothing to the vertical distance for the right child
    solve(root->right, d, diag);
}

vector<int> diagonal(Node *root) {
    // map to store the diagonal elements
    map<int,vector<int>> diag;

    // solve the tree
    solve(root, 0, diag);

    // vector to store the result
    vector<int> result;

    // iterate over the map and collect all diagonal elements
    for (auto it : diag) {
        vector<int> v = it.second;
        for (auto elem : v) {
            result.push_back(elem);
        }
    }

    return result;
}


// APPROACH 2 : USING LEVEL ORDER TRAVERSAL

// PUSH ROOT IN THE QUEUE 
// POP IT AS A TEMP VARIABLE AND PRINT IT AND
// PUSH THE LEFT CHILD IF EXIST IN THE QUEUE TO USE IT AS A TEMP AFTERWORDS
// PRINT ALL THE THE RIGHT CHILD 
// PROCESS TILL TEMP = NULL AND QUEUE BECOMES EMPTY


//  time complexity of this solution is 𝑂(𝑁) and The space is 𝑂(𝑁)

vector<int> diagonal2(Node *root)
{
   // your code here
   vector<int> ans;

   if(!root){
    return ans;
   }

   queue<Node*> q;

   q.push(root);

   while(!q.empty()){
    Node* temp = q.front();
    q.pop();

    while(temp){
        ans.push_back(temp->data);

        if(temp->left){
            q.push(temp->left);
        }

        temp = temp->right;
    }

   }

   return ans;
}


int main(){
    
    return 0;
}