/*
Write a class (or struct) for implementing a priority queue (PQ) using linked list data (5) 
structure. The following functions can be called from the main function : 
i. Inserting into the PQ 
ii. Deleting from the PQ 
iii. Print PQ

Here is a possible implementation of a priority queue using a linked list:
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
public:
    PriorityQueue() : head(nullptr) {}

    void insert(int data, int priority) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->priority = priority;
        newNode->next = nullptr;

        if (head == nullptr || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->priority <= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    int deleteMin() {
        if (head == nullptr) {
            throw "Priority queue is empty!";
        }

        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return data;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << "Priority: " << current->priority << ", Data: " << current->data << endl;
            current = current->next;
        }
    }

private:
    Node* head;
};
