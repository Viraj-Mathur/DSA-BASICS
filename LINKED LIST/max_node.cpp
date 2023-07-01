#include<iostream>

using namespace std;
// Find the largest node in Doubly linked list
/*LOGIC:
 traverse the linked list with a loop, where in each iteration, we compare the data value of the current node with the data value of the maximum node.
 If the data value of the current node is greater than the data value of the maximum node seen so far, we update maxNode to point to the current node
*/
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    Node* findLargestNode() {
        if (head == NULL) {
            return NULL;
        }

        Node* maxNode = head;
        Node* current = head->next;

        while (current != NULL) {
            if (current->data > maxNode->data) {
                maxNode = current;
            }
            current = current->next;
        }

        return maxNode;
    }
};


int main(){
    
    return 0;
}