#include<iostream>


// HEIGHT OF NODE IS THE MAXIMUM PATH BETWEEN ROOT NDOE AND LEAF NODE
using namespace std;


class Solution{
    public:
    // FUNCTION TO FIND THE HEIGHT OF THE NODE (USING RECURSION) - max of height of left subtree and right subtree + 1(root)
    int height(struct Node* node){
        // base case
        if(node == NULL){
            return 0;
        }

        int left = height(node ->left);
        int right = height(node -> right);

        int ans = max(left,right)+1 // will find the maximum of left or right node and add it with 1(root node)
        return ans;
    }
};
int main(){
    
    return 0;
}

/*
time complexity = O(n)
space complexity = O(height)

*/