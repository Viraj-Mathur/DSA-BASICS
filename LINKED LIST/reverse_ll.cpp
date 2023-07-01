#include<iostream>

using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

//LOGIC 1: ITERATIVE SOLUTION
//  reversing the linked list
Node* reverseLinkedList(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;  //case of empty list or single node
    }
// initialisation
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

//iteratively changing the nodes pointer
    while(curr !=NULL){
        // null <- PREVnode -> CURRnode -> FORWARDnode ->X
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;

    }
    return prev;
}

/* FOR N NODES
SPACE COMPLAXITY = O(1) constant
TIME COMPLAXITY = O(n)
*/

// LOGIC2: RECURSIVE SOLUTION
void reverseLinkList1(Node* &head,Node *curr, Node* prev){

//base case
if(curr == NULL){
    head = prev;
    return;
}
Node* forward = curr -> next;
reverseLinkList1(head , forward, curr);
curr -> next = prev;
}

int main(){
    
    return 0;
}