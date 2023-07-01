#include <iostream>
using namespace std;
// to find middle element of a linked list


/*LOGIC:
The function then enters a loop, where in each iteration, the slow pointer moves one step forward (i.e., it points to the next node in the list), while the fast pointer moves two steps forward (i.e., it points to the second next node in the list).
By moving two steps at a time, the fast pointer will reach the end of the list twice as fast as the slow pointer. Thus, when the fast pointer reaches the end of the list (i.e., it becomes NULL), the slow pointer will be pointing to the middle element of the list.
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

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // the middle node is slow
    cout << "The middle element is: " << slow->data << endl;
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
    findMiddle(head);

    return 0;
}
