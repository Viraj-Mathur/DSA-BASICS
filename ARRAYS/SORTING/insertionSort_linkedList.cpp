#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return head;
    }
    
    if (val < head->data) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    Node* curr = head;
    
    while (curr->next != NULL && curr->next->data < val) {
        curr = curr->next;
    }
    
    newNode->next = curr->next;
    curr->next = newNode;
    
    return head;
}

Node* insertionSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* sortedList = NULL;
    Node* curr = head;
    
    while (curr != NULL) {
        sortedList = insert(sortedList, curr->data);
        curr = curr->next;
    }
    
    return sortedList;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 9);
    head = insert(head, 10);
    head = insert(head, 6);
    head = insert(head, 5);
    head = insert(head, 12);
    head = insert(head, 4);
    head = insert(head, 11);
    head = insert(head, 2);

    head = insertionSort(head);
    cout << "AFTER INSERTION SORT: ";
    printList(head);
    return 0;
}
