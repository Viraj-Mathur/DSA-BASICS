// Given head, the head of a linked list, determine if the linked list has a cycle in it.

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    // Data stored in the node
    int data;        
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data 
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// function to detect the cycle
bool detectLoop(Node* head){
    Node* temp = head; // initialising temp at head
    unordered_map<Node* , int> nodeMap; // creating a map to store the nodes to keep track of them

    while(temp !=nullptr){
        if(nodeMap.find(temp) != nodeMap.end()){ // if node is already in the loop therefore there is a cycle
            return true;
        }

        // storing current node in the map
        nodeMap[temp] = 1;

        temp = temp->next; // moving to the next node
    }

    return false; // if list is traversed therefore there is no loop so no cycle is present
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    // Check if there is a loop 
    // n the linked list
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    
    return 0;
}

/*
Time Complexity: O(N * 2 * log(N) )
Space complexity: O(N) because of hashmap
*/