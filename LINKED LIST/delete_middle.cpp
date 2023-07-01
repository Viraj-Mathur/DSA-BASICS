#include <iostream>
using namespace std;
// to find middle element of a linked list


/*LOGIC:
LOGIC same as finding the middle element
*/
struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // delete the middle node(slow)
    prev->next = slow->next;
    delete slow;
}


int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();
    Node* sixth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;
 // sixth->next = sixth;

    // sixth->data = 6;
    // sixth->next = NULL;

    printList(head);
    deleteMiddle(head);
    printList(head);

    return 0;
}
