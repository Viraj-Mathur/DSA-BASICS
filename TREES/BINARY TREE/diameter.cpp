#include <bits/stdc++.h>



using namespace std;





// DIAMETER OF THE TREE: LONGEST PATH BETWEEN ANY 2 (END)NODES

/*
APPROACHES: 1) LEFT SUBTREE 2} RIGHT SUBTREE 3}BOTH
PAIR IN STL: Pair is used to combine together two values that may be of different data types. 
             Pair provides a way to store two heterogeneous objects as a single unit

*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    // FUNCTION TO FIND THE HEIGHT OF THE NODE (USING RECURSION)
    int height(struct Node* node){
        // base case
        if(node == NULL){
            return 0;
        }

        int left = height(node ->left);
        int right = height(node -> right);

        int ans = max(left,right)+1; // will find the maximum of left or right node and add it with 1(root node)
        return ans;
    }

    // function to return the diameter of a binary tree
    int diameter(Node* root){
        // base case
        if(root == NULL){
            return 0;
        }

        int op1 = diameter(root-> left); //subtree left
        int op2 = diameter(root->right); //subtree right
        int op3 = height(root->left)+height(root->right)+1; // mixture of both 1 is added for root node
        //this height function together with diameter function is making the complexity O(n^2) so should be avoided
        // TO RESOLVE TAKE HEIGHT AND DIAMETER EK SAATH USING PAIR
        int ans = max(op1,max(op2,op3));
        return ans;
    }

    // BETTER APPROACH
    pair<int,int> diameterFast(Node* root){
        // base case
        if(root == NULL){
            pair<int,int> p =make_pair(0,0);
            return p;
        }

        pair<int,int>left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second+right.second +1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.first = max(left.second,right.second) +1 ;
        return ans;
    }
    int dia(Node* root){
        return diameterFast(root).first;
    }
};

int main(){
    
    return 0;
}