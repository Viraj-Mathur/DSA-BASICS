#include <iostream>
using namespace std;
// to Remove duplicate element from sorted Linked List 


/*LOGIC:
in each iteration, we compare the data value of the current node with the data value of the previous node. 
If they are the same, we delete the current node and update the next pointer of the previous node to point to the node after the current node. 
If they are different, we move the previous node and current node pointers forward to the next nodes and check.
*/

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeDuplicates() {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL) {
            if (prev != NULL && prev->data == current->data) {
                prev->next = current->next;
                delete current;
                current = prev->next; //for next elements check
            } else { 
                prev = current; //incrementing prev and current nodes
                current = current->next;
            }
        }
    }

    void display() {
        Node* current = head;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    // insert some elements
    myList.insert(1);
    myList.insert(2);
    myList.insert(2);
    myList.insert(3);
    myList.insert(3);
    myList.insert(3);

    cout << "Original list: ";
    myList.display();

    // remove duplicates
    myList.removeDuplicates();

    cout << "List after removing duplicates: ";
    myList.display();

    return 0;
}