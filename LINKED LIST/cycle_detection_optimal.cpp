// Given head, the head of a linked list, determine if the linked list has a cycle in it.

/*
When the tortoise and hare enter the loop, they may be at different positions within the loop 
due to the difference in their speeds. The hare is moving faster, so it will traverse a greater distance 
in the same amount of time.

If there is no loop in the linked list, the hare will eventually reach the end, and terminate without a meeting occurring.

If there is a loop eventually hare and the tortoise will meet thereby detecting the circle
in loop the distance will be 0 at the end between them as for every move distance will be reduced to : d , d-1, d-2 .. 0 
*/

#include <bits/stdc++.h>

using namespace std;

// To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization.




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
    // initialsing slow and fast pointers at the head
    Node* slow = head;
    Node* fast = head; 

    // step 2: traversing them
    while(fast != nullptr && fast->next != nullptr){ //taking into account the even and odd linear linked list (if fast ptr reaches end of the list therfore there is no loop)
        slow = slow->next;
        fast = fast->next->next;

        // to check if the pointers meet
        if(slow == fast){
            return true; //there is a cycle
        }
    }
    return false; // there is no cycle
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
Time Complexity: O(N)
Space Complexity : O(1) because of constantamount of additionalspace,
*/