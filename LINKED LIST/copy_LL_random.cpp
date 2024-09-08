/*
138. Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer, 
which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
where each new node has its value set to the value of its corresponding original node. 
Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers 
in the original list and copied list represent the same list state. None of the pointers in the new list should point to
nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then 
for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. 
Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 
Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    // Data stored in the node
    int data;           
     // Pointer to the next node
    Node *next;        
    // Pointer to a random
    // node in the list
    Node *random;       

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};


// Approach 1 : using HashMaps
/*
create a copy LL first and then try to make the pointer connection usinh hash maps
Step 1 : create a temp as pointer for traversing the OG LL and use map to store copied nodes.
Step 2 : Map the original node to its copied node in the map.

Get the copied node corresponding to the original node using the map.
Set the next pointer of the copied node to the copied node mapped to the original node’s next node.
Set the random pointer of the copied node to the original node’s next node copied from the map.

Time Complexity: O(2N) as LL is traversed twice
Space Complexity : O(N)+O(N)

*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head; //temp pointing to head of the OG LL
        unordered_map<Node*, Node*>mpp; // map to map original nodes to their corresponding copied nodes 

        // create copy of each node and store in the map
        while(temp!=NULL){
            Node* newNode = new Node(temp->data);
            mpp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;

        // connecting next and random pointers
        while(temp!=NULL){
            // Access the copied node corresponding
            // to the current original node
            Node* copyNode = mpp[temp];
            // Set the next pointer of the copied node
            // to the copied node mapped to the
            // next node in the original list
            copyNode->next = mpp[temp->next];
            // Set the random pointer of the copied node
            // to the copied node mapped to the
            // random node in the original list 
            copyNode->random = mpp[temp->random];
            // Move to the next node
            // in the original list
            temp = temp->next;


        }

        return mpp[head];
    }
};


// Approach 2 REMOVING THE EXTRA SPACE: without using hashmaps  -> making copy LL inbetween 
/*
Step 1 : create copy nodes in between the OG list
step 2 : connect random pointers for in between list
step 3 : connect next pointer ->to extract the in-between list

Time Complexity: O(3N)
Space Complexity : O(N)

*/

class Solution {
    private:
    // step 1 function
    void insertBetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* nextElement = temp->next;

            // creating a copy node with the same data inbetween
            Node* copy = new Node(temp->data);

            // point the copy's next to the OG node's next
            copy->next = nextElement;
            // point the OG node's next to the copy
            temp->next = copy;
            // move the next og node
            temp = nextElement;
            
        }
    }

    // step 2 function
    void connectRandom(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            // access the copied node
            Node* copyNode = temp->next;

            // connect random pointer if the OG node have one
            if(temp->random){
                // Point the copied node's random to the
                // corresponding copied random node
                copyNode->random = temp->random->next;
            }
            else{
                // set random to null
                copyNode->random = NULL;
            }

            // move to the next OG node (move 2 step as copy node is in between them)
            temp = temp->next->next;

        }
    }

    // step 3 funtion
    Node* extract(Node* head){
        Node* temp = head;
        // create a dummy node and initialise it to -1 for copy node
        Node* dummyNode = new Node(-1);

        // initialise the result pointer
        Node* res = dummyNode;

        while(temp!=NULL){
            // creating a new list by pointing to copied nodes
            res->next = temp->next;
            res = res->next;

            // Disconnect and revert back to the
            // initial state of the original linked list
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

public:
    Node* copyRandomList(Node* head) {
        // If the original list
        // is empty, return null
        if(!head) return nullptr;   
        
        // Step 1: Insert copy of
        // nodes in between
        insertBetween(head); 
        // Step 2: Connect random
        // pointers of copied nodes
        connectRandom(head);  
        // Step 3: Retrieve the deep
        // copy of the linked list
        return extract(head); 

    }
};

int main(){
    
    return 0;
}