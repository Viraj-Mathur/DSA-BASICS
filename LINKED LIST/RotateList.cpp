// Given the head of a linked list, rotate the list to the right by k places.

#include <bits/stdc++.h>

using namespace std;

/*
APPROCH:
every k which is multiple of the length of the list, we get back the original list. 
operate brute force on any linked list for k as a multiple of the length of the list.

for k greater than the length of the list, we have to rotate the list for k%length of the list. 
This reduces our time complexity.
    Calculate the length of the list.
    Connect the last node to the first node, converting it to a circular linked list.
    Iterate to cut the link of the last node and start a node of k%length of the list rotated list.

*/

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};
//utility function to insert node at the end of the list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}


// Main function to rotatate the LL k times

node* rotateRight(node* head, int k){
    if(head == NULL || head->next == NULL || k==0) return head;

    // finding the length
    node* temp = head;
    int len = 1;
    while(temp->next !=NULL){
        ++len;
        temp = temp->next;
    }
    //now temp is the last node

    // link the last node to the first node
    temp->next = head;
    k = k%len; //when k is more than length of list
    int end = len-k; // to get the end of the list
    while(end--) temp = temp->next;
    // breaking the last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}

int main(){

    node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    int k = 2;
    node* newHead = rotateRight(head,k);//calling function for rotating right of the nodes by k times
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);//list after rotating nodes

    return 0;
}