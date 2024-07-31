// CONVERT SORTED LL TO BST

// APPROACH : SAME AS CONVERTING SORTED ARRAY TO BST(middle element as root and solve for left and right part)

// make left subtree with recursion which will contain n-1-(n/2) nodes (1 for root(mid))
// right will have n/2 nodes
// solve for left subtree then make a root node then solve for right subtree
// for solving the right subtree case increment the head pointer

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


// function to conert ll to bst

Node* sortedLLintoBST(Node* &head,int n){
    if(head == NULL || n<=0){ //BST NOT POSSIBLE
        return NULL;
    }

    // recursion call for getting the left subtree
    // Node* leftSubtree = sortedLLIntoBST(head,n-1-n/2); - this is also correct
    Node* leftSubtree = sortedLLintoBST(head,n/2);

 // Now we can create root as head node now points to the mid node
    Node* root = head;

    // attach the left subtree
    root->left = leftSubtree;

    // increment the head to point for right for right subtree call

    head = head->right;

    // getting right subtree // Head points to one node ahead of mid and hence is updated head
    // root->right = sortedLLIntoBST(head,n/2); - also correct

    root->right = sortedLLintoBST(head,n-1-(n/2));
    return root;
}



// LEETCODE
/*
109. Convert Sorted List to Binary Search Tree

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.
*/


//  * Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
// first find size of the LL
    int findSize(ListNode* head){
        int size = 0;
        while(head){
            size++;
            head = head->next;
        }

        return size;
    }

// function to convert
    TreeNode* LLtoBST(ListNode* &head,int start,int end) {

        if(start>end){
            return nullptr;
        }

        int mid = start+(end-start)/2;

// Recursively build the left subtree
        TreeNode* left = LLtoBST(head, start, mid - 1);

        // the middle element will be the root of BST

        TreeNode* root = new TreeNode(head->val);
        root->left = left;

        // move the head pointer to the next node
        head = head->next;

        // Recursively build the right subtree
        root->right = LLtoBST(head, mid + 1, end);
        
        return root;
    
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = findSize(head);
        return LLtoBST(head,0,n-1);
    }
};