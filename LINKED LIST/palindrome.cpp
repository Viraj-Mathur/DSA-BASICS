//  To check if the given LL is a palindrome or not
#include <bits/stdc++.h>

using namespace std;



class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

    bool isPalindrome(Node* head) { // USING STACKS : Time Complexity: O(2 * N)
        // Edge case: empty list or single node list
        if (head == nullptr || head->next == nullptr)
            return true;
        
        stack<int> st;
        Node* temp = head;
        
        // Push all elements of the linked list onto the stack
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }
        
        temp = head;
        
        // Compare elements of the linked list with the stack
        while (temp != nullptr) {
            int stackTop = st.top();
            st.pop();
            
            if (temp->data != stackTop) {
                return false;
            }
            
            temp = temp->next;
        }
        
        return true;
    }




    // OPTIMAL APPROACH 
    /*
    The previous approach uses O(N) additional space, which can be avoided by reversing only half 
    of the linked list and comparing the first and second halves. If they match, reverse the portion 
    that was originally reversed, and then return true else return false.

    Middle can be found using tortoise and hare algo

    */

   Node* reverseLinkedList(Node* head) {
    // Check if the list is empty or has a single node
    if (head == nullptr || head->next == nullptr) {
        return head; // No need to reverse
    }
    
    Node* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

bool isPalindrome2(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // Empty list or single node is a palindrome
    }

    // Find the middle of the linked list using slow and fast pointers
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list starting from 'slow->next'
    Node* secondHalfReversed = reverseLinkedList(slow->next);

    // Compare the first half with the reversed second half
    Node* first = head;
    Node* second = secondHalfReversed;

    while (second != nullptr) {
        if (first->data != second->data) {
            // Restore the original list by reversing back the second half
            slow->next = reverseLinkedList(secondHalfReversed);
            return false; // Not a palindrome
        }
        first = first->next;
        second = second->next;
    }

    // Restore the original list by reversing back the second half
    slow->next = reverseLinkedList(secondHalfReversed);
    return true; // The linked list is a palindrome
}


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome2(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}