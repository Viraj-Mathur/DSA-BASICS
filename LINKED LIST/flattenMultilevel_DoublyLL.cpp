/*
430. Flatten a Multilevel Doubly Linked List - https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

Example:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 3:
Input: head = []
Output: []
Explanation: There could be empty list in the input.
 

Constraints:

The number of Nodes will not exceed 1000.
1 <= Node.val <= 105
 

How the multilevel linked list is represented in test cases:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together, we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,    2,    3, 4, 5, 6, null]
             |
[null, null, 7,    8, 9, 10, null]
                   |
[            null, 11, 12, null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
*/

#include <bits/stdc++.h>


using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


// use stack to handle leftover nodes

class Solution {
public:
    Node* flatten(Node* head) {
        // Initialize 'curr' to iterate through the main list and 'tail' to keep track of the last node
        Node* curr = head;
        Node* tail = head;

        // Stack to store nodes where the flattening should continue later (i.e., nodes after child nodes)
        stack<Node*> st;

        // First pass: Traverse the main list, handling child nodes if they exist
        while(curr != NULL){
            // If the current node has a child
            if(curr->child != NULL){
                Node* child = curr->child;  // Get the child node

                // If the current node has a next node, push it to the stack to return to later
                if(curr->next != NULL){
                    st.push(curr->next);  // Save the 'next' node for future processing
                    curr->next->prev = NULL;  // Detach the next node from the current node (set 'prev' to NULL)
                }

                // Connect the current node to its child
                curr->next = child;
                child->prev = curr;  // Maintain the bidirectional link
                curr->child = NULL;  // Remove the child pointer by setting it as null (since the child is now part of the main list)
            }

            // Move the 'tail' pointer to the current node and advance to the next node
            tail = curr;
            curr = curr->next;
        } 

        // Second pass: Handle nodes stored in the stack (i.e., nodes after child nodes)
        while(!st.empty()){
            // Pop the node that was stored in the stack
            curr = st.top(); 
            st.pop();

            // Attach the popped node to the end of the flattened list (tail)
            tail->next = curr;
            curr->prev = tail;

            // Traverse the newly attached list to update 'tail' to its end
            while(curr != NULL){
                tail = curr;
                curr = curr->next;
            }
        }

        // Return the head of the fully flattened list
        return head;
    }
};


int main(){
    
    return 0;
}