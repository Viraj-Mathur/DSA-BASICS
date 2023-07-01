#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next; // because we need pointer pointing to the next node

    Node(int data){  //constructor
        this -> data = data;
        this -> next = NULL;
    }

    // destructor for memory free
    ~Node(){
        int value = this -> data;
        if(this ->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is freed for ndoe with data "<< value<<endl;
    }

};

void InsertAtHead(Node* &head, int d){ // to insert at the starting
     //reference taken beacuse we do not want to mske another copy 
    // new node create
    Node * temp = new Node(d);  //created a temporary temp pointer
    temp -> next = head;  //that pointer points to the head of the node
    head = temp; // the original head points to node of temp

}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp; //next points to temp
    tail = tail -> next; // temp shifted to next of second node
}

void InsertAtPosition(Node* &tail,Node* &head, int position, int d){
    
    // insert at Start
    if(position ==1 ){
        InsertAtHead(head,d);
        return;
    }
    // this code cannot take values in first position unless this if statement is called

    Node* temp = head;
    int count = 1;
    while (count<position-1)  // inserting nodes at the middle of two nodes
    {
        temp = temp ->next;
        count++;
    }

    // also we need to upadate tail if we want to insert at last postion
    if(temp -> next ==NULL){
        InsertAtTail(tail,d);
        return;
    }

    // creating a node for data
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next;
    temp -> next = nodeToInsert;
    
}

void print(Node* &head){
    Node* temp = head;
    // Node* temp = tail;

    while(temp !=NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<< endl;
}

// To delete a node
void deleteNode(int position, Node* & head){
    // deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head -> next; //head of first node jumps to second and the the first node is deleted from memory
        // memory free start node
        temp -> next = NULL ; //INORDER TO PREVENT SEGMENTATION ERROR POINTER WHICH WAS POINTING TO DELETED NODE SHOULD ALSO BE REMOVED
        delete temp;
    }
    else{
        // delete any middle node or last node
        Node* curr = head;  //setting up current and previous node
        Node* prev = NULL;

        int count = 1;
        while(count <= position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr ->next;
        curr -> next = NULL;
        delete curr;
    }
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp!= NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}


int main(){
    // created a new node
    Node *node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    // head pointed to node1
    Node* head = node1;
    // tail pointed to node1
    Node* tail = node1;
    print(head);

    InsertAtHead(head,12);
    print(head);

    InsertAtHead(head,15);
    print(head);

    InsertAtTail(tail,20);
    print(head);

    // InsertAtPosition(head,3,40);
    // print(head);

    InsertAtPosition(tail,head,5,7);
    print(head);
    cout<<"Head: "<< head -> data << endl;
    cout<<"Tail: "<< tail -> data << endl;

    cout<<"Length is: "<<getLength(head)<<endl;

    deleteNode(1,head);
    print(head);

    deleteNode(2,head);
    print(head);
    
    cout<<"Length is: "<<getLength(head)<<endl;
    return 0;

    return 0;
}