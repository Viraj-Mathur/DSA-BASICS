// Given the head of a singly linked list of `n` nodes and an integer `k`, where k is less than or equal to `n`. Your task is to reverse the order of each group of `k` consecutive nodes, if `n` is not divisible by `k`, then the last group of remaining nodes should remain unchanged.

/*
breaking the list into segments of K nodes and reversing each segment individually.
Starting from the head, the algorithm traverses the list to identify segments of K nodes. 
Upon finding a segment, it reverses it, returning the modified list. If a segment has less than 
K nodes left (ie. remaining nodes at the end), they are left unaltered. 

*/
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// function to reverse a LL
Node* reverseLL(Node *head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Function to find the kth element
Node* getKthNode(Node* temp, int k){
    // decrement k as we already started from first node
    k -=1;
    // decrement k until it reaches the desired position
    while(temp!=NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

// Main function to reverse k nodes
Node* kReverse(Node* head, int k){
    Node* temp = head;
    Node* prevLast = NULL; //initially prev points no node

    while(temp!=NULL){
        // get kth node of current group
        Node* kThNode = getKthNode(temp,k);

        // if kth node is NULL - not a complete group
        if(kThNode ==NULL){
            // if there was a previous group link the last node to current node
            if(prevLast){
                prevLast->next = temp;
            }
            break; //exit the loop
        }

        // store the next node after kth node
        Node* nextNode = kThNode->next;
        // disconnet the kth node to prepare for reversal
        kThNode->next = NULL; //node disconnected
        // reverse the LL
        reverseLL(temp);
        // now adjust the head of reversed LL 
        if(temp == head){
            head = kThNode; //the kth node will become the head
        }
        else{
            // link the last node to the prev group to the reversed group
            prevLast->next = kThNode; //relinking with the previous LLs
        }
        //  update the pointers for the next iteration(last node of the previous group)
        prevLast = temp;
        // move to next group
        temp = nextNode;
    }
    return head;
}

/*
Time Complexity: O(2N) 
The time complexity consists of actions of reversing segments of K and 
finding the Kth node which operates in linear time. Thus, O(N) + O(N) = O(2N) = O(N).

Space Complexity: O(1) The space complexity is O(1) as without any additional space requirements.
*/

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = kReverse(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);


    return 0;
}