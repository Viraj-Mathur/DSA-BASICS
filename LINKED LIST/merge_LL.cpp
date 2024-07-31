/*
Merge two sorted linked lists(https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/)

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the lists (in place) and return the head of the merged list.

Examples:

Input: a: 5->10->15, b: 2->3->20
Output: 2->3->5->10->15->20

Input: a: 1->1, b: 2->4
Output: 1->1->2->4
*/ 

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

// APPROACH 1 : BRUTE FORCE TC :O(O((n+m)*log(n+m))) AND SC : O(n+m)

// CONVERT BOTH LLs INTO VECTORS MERGE THEM INTO SORTED VECTOR THEM AND CONVERT THEM AGAIN

Node* mergeSortedLLVector(Node* first, Node* second){

    // temporary vector to store values
    vector<int> arr;

    // pushing values of first LL
    while(first!=NULL){
        arr.push_back(first->data);
        first = first->next;
    }

    // pushing values of second LL
    while(second!=NULL){
        arr.push_back(second->data);
        second = second->next;
    }

    // sort the vector
    sort(arr.begin(), arr.end());

    // create a new LL with the sorted array
    Node* temp = new Node(-1);
    Node* head = temp;
    for(int i=0;i<arr.size();i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    // returning the resultant linked list
    head = head->next;

    return head;
}


// Approach 2 : using dummy LLs and pointers - TC : O(N + M) AND SC : O(1)
/*
INTUITION: The idea is to use a temporary dummy node as the start of the result list. The pointer Tail always points to the last node 
in the result list, so appending new nodes is easy.

Follow the steps below to solve the problem:

First, make a dummy node for the new merged linked list
Now make two pointers, one will point to list1 and another will point to list2.
Now traverse the lists till one of them gets exhausted.
If the value of the node pointing to either list is smaller than another pointer, add that node to our merged list and increment that pointer.
*/

Node* mergeSortedLL_dummies(Node* first, Node* second){
    // create a dummy node which will contain the result initialise to -1
    Node dummy(-1);
    

    // tail points to the last index
    Node* tail = &dummy;

    // Tail's next will be the place to append the new nodes
    while(1){
        // base cases ->If either list runs out, use the other list
        if(first == NULL){
            tail->next = second;
            break;
        }
        else if(second == NULL){
            tail->next = first;
            break;
        }


        // case 1
        if(first->data <= second->data){
            // move the front node of first LL to the result and increment its pointer(a)
            Node* newNode = first;
            first = first->next;
            newNode->next = tail->next;
            tail->next = newNode;
        }
        // case 2
        else{
           // move the front node of second LL to the result and increment b
            Node* newNode = second;
            second = second->next;
            newNode->next = tail->next;
            tail->next = newNode; 
        }

        tail = tail->next;
    }

    return (dummy.next);

}


// APPROACH 3 : USING RECURSION

// INTUITION : The idea is to move ahead with node in the recursion whose node value is lesser. When any of the node reach the end then append the rest of the linked List.

Node* mergeSortedLL_REC(Node* first, Node* second){

    // create a dummy LL for result
    Node* result = NULL;

    // base cases
    if(first == NULL){
        return second;
    }
    else if(second == NULL){
        return first;
    }

// Pick either first or second, and recur
    if(first->data <= second->data){
        result = first;
        result->next = mergeSortedLL_REC(first->next, second);
    }
    else{
        result = second;
        result->next = mergeSortedLL_REC(first, second->next);
    }

    return result;   

}




int main(){
    
    // Create a hard-coded linked list:
    // 2 -> 4 -> 8 -> 9
    Node* first = new Node(2);
    first->next = new Node(4);
    first->next->next = new Node(8);
    first->next->next->next = new Node(9);

    // Create another hard-coded linked list:
    // 1 -> 3 -> 8 -> 10
    Node* second = new Node(1);
    second->next = new Node(3);
    second->next->next = new Node(8);
    second->next->next->next = new Node(10);

    // Node* mergedList = mergeSortedLLVector(first, second);
    // Node* mergedList = mergeSortedLL_dummies(first, second);
    Node* mergedList = mergeSortedLL_REC(first, second);

    Node* temp = mergedList;
    cout << "Merged Link List is:" << endl;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}