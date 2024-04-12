// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

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

void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}

//utility function to insert node at the end of the linked list
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

// Approach 1: Using HashMaps
// Store first LL in a MAp and  then compare it with the second LinkedList  using HashMap  to check if there is any common node or not 

node* intersectionPresent(node* head1, node* head2){
    unordered_map<node*, bool> mpp;
    while(head1!=NULL){
        mpp.emplace(head1,true);
        head1 = head1->next; //placing LL in a map
    }
    while(head2!=NULL){
        if(mpp.find(head2)!= mpp.end()) return head2;
        head2 = head2->next;
    }
    return NULL; //else no intersection point found so return null
}

// Approach 2: Difference in length
// Make larger Linked List cover D steps(differnce between the length of the LLs) and once aligned with the shorter LL start comparing uniti common element is found

// function to get difference
int getDifference(node* head1, node* head2){
    int len1 = 0, len2 = 0;

    while (head1 != NULL) {
        ++len1;
        head1 = head1->next;
    }

    // Calculate length of head2
    while (head2 != NULL) {
        ++len2;
        head2 = head2->next;
    }

    return len1 - len2; //if difference is neg-> length of list2 > length of list1 else vice-versa
}

node* intersectionPresent2(node* head1, node* head2){
    int diff = getDifference(head1, head2);
    // Adjust head1 or head2 based on the difference in lengths
    if (diff < 0) {
        // head2 is longer, move head2 by |diff| nodes
        diff = -diff;
        while (diff-- > 0) {
            head2 = head2->next;
        }
    } else {
        // head1 is longer or they are equal, move head1 by diff nodes
        while (diff-- > 0) {
            head1 = head1->next;
        }
    }

    // Traverse both lists to find the intersection point
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1; // Found intersection point
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection found


}

int main(){
    
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    node* answerNode = intersectionPresent2(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}