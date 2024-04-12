// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

/*
1 Step - detect the loop using tortoise and hare algo
2 Step - if loop detected take the slow pointer to the the head again and from there make fast and slow  pointers move together by single step only until they meet, the recolliding point would be the starting point of the loop
*/

#include <bits/stdc++.h>

using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};

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

void createCycle(node* &head,int pos) {
    node* ptr = head;
    node* temp = head;
    int cnt = 0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}

node* detectCycle(node* head){
    if(head == NULL || head->next == NULL) return NULL;

    // slow and fast node
    node* slow = head;
    node* fast = head;
    node* entry = head;

    while(fast -> next !=NULL && fast->next->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;

        // the recolliding logic
        if(slow == fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return slow; // the starting point
        }
    }
    return NULL; // no loop found
}



int main(){
    node* head = NULL;
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,6);
    insertNode(head,10);
    
    createCycle(head,2);
    
    node* nodeRecieve = detectCycle(head);
    if(nodeRecieve == NULL) cout<<"No cycle";
    else {
        node* temp = head;
        int pos = 0;
        while(temp!=nodeRecieve) {
            ++pos;
            temp = temp->next;
        }
        cout<<"Tail connects at pos "<<pos<<endl;
    }
    

    
    return 0;
}