// Given the head of a linked list, remove the nth node from the end of the list and return its head.

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with 
    //only data (next set to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Main function: 

// Approach 1: delete the (L-N+1)th node from the start of the linked list, where L is the total length of the linked list
Node* DeleteNthNodefromEnd(Node* head, int N){
    if(head ==NULL){
        return NULL;
    }
    // to find the length of the list
    int cnt = 0;
    Node* temp = head;

    // count number of nodes in LL
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }

    // if N = L delete head
    if(cnt == N){
        Node* newhead = head->next;
        delete(head);
        return newhead;
    }

    // calculate position of node to delete(res)
    /* Initialize variable res to L-N, and start iterating the linked list while decrementing res 
    at each node. Once res equals 0,temp will be pointing to the (L-N)th node, therefore, stop the traversal.
    
    Create a new link, point the (L-N)th node to the (L-N+2)th node of the linked list, 
    effectively skipping the (L-N+1)th node.

    */

   int res = cnt-N;
   temp = head;

   while(temp!=NULL){
    res--;
    if(res ==0){
        break;
    }
    temp = temp->next;
   }

//    deleting the node
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;

} 
// Time Complexity: O(L)+O(L-N), 
// Space Complexity:  O(1)

/* Optimised Approach: 
Take Two pointers- slow and fast and initially put fast pointer exactly N step ahead
of the slow pointer 
After which, both of them will move one step at a time. When the fast pointer reaches the last node, 
i.e., the L-th node, the slow is guaranteed to be at the (L-N)-th node,
*/

Node* DeleteNthNodefromEnd2(Node* head, int N){
    Node* fast = head;
    Node* slow = head;
    // putting fast ahead
    for(int i=0;i<N;i++){
        fast = fast->next;
    }

    if(fast ==NULL){
        return head->next;
    }

    while(fast->next !=NULL){
        fast = fast->next;
        slow = slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd2(head, N);
    printLL(head);
    
    return 0;
}