#include <iostream>
using namespace std;

class Node {
public:
    int value;
    int priority;
    Node* next;
    
    Node(int v, int p) {
        value = v;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue {
public:
    Node* head;
    
    PriorityQueue() {
        head = NULL;
    }
    
    void insert(int value, int priority) {
        Node* new_node = new Node(value, priority);
        if (head == NULL || priority < head->priority) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* curr_node = head;
            while (curr_node->next != NULL && priority >= curr_node->next->priority) {
                curr_node = curr_node->next;
            }
            new_node->next = curr_node->next;
            curr_node->next = new_node;
        }
    }
    
    void remove() {
        if (head == NULL) {
            return;
        }
        Node* node_to_remove = head;
        head = head->next;
        delete node_to_remove;
    }
    
    void print() {
        Node* curr_node = head;
        while (curr_node != NULL) {
            cout << curr_node->value << "(" << curr_node->priority << ")" << " ";
            curr_node = curr_node->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    
    pq.insert(5, 2);
    pq.insert(10, 1);
    pq.insert(7, 3);
    pq.insert(3, 2);
    
    pq.print();
    
    pq.remove();
    pq.remove();
    
    pq.print();
    
    return 0;
}