/* Given a Linked list, List1 = {A1, A2, . . . An–1; An) with data, write a program to re-order it to 
{A1, An, A2, An–1 …} without using any extra space.
*/
#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

 Node* push(Node** head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

 Node* Reverse(Node* head)
{
Node* curr = head;
Node* prev = NULL;
Node* ptr = NULL;

    while(curr != NULL)
    {
        ptr = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = ptr;
    }
    return prev;
}

void reorderList(Node* head) 
{
    // Return Ans If Linked List is Empty OR Have only One Node
    if(head -> next == NULL || head -> next -> next == NULL)
    {     return;     }    

    Node* slow = head;
    Node* fast = head;
    Node* last = head;
    while(fast != NULL)
    {
        last = slow;
        slow = slow -> next;
        fast = fast -> next;
        if(fast != NULL)
        {   fast = fast -> next;  }
    }
    //Seperating First and Second Half
    last -> next = NULL;
    //Reversing Second Half
    Node* second = Reverse(slow);
    Node* first = head;

    //Merging First And Second Half of Linked List
    while(second)
    {
        Node* temp1 = first -> next;
        Node* temp2 = second -> next;

        first -> next = second;
        second -> next = temp1;

        second = temp2;
        first = temp1;
    }
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Original Linked List: ";
    printList(head);

    reorderList(head);

    cout << "Reordered Linked List: ";
    printList(head);

    return 0;
}