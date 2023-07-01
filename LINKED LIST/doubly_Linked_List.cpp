#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    // constructor
    Node(int d){
        this -> data = d;
        this ->prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed for node with data : "<<val<<endl;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp!= NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<< endl;
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

void insertAtHead(Node* &head, int d){
    // empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);  //creating a node
        temp ->next = head;  // temp ka next points to head of first node
        head -> prev = temp; // temp ka head points to previous
        head = temp; //temp becomes first node
    }
}

void insertAtTail(Node* &tail, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
        Node* temp = new Node(d); //Node created
        tail -> next = temp; //tail of last node points to tail of temp node
        temp -> prev = tail; // prev of node points to original last node
        tail = temp; //tail goes to temp

    }
}

void deleteNode(int position, Node* &head){
    // delete first node
    if(position==1){
        Node* temp = head;
        temp -> next ->prev =NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count<position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr; 
    }
}

void insertAtPosition(Node* &tail,Node* &head, int position, int d){
    // insert at start
    if(position ==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp ->next;
        cnt++;
    }
    // insert at last
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    
    // creating node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next; //node to insert ka next = temp ka next
    temp ->next -> next -> prev  = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}
int main(){
    Node* node1 = new Node(11);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    insertAtHead(head,22);
    print(head);
     insertAtHead(head,33);
    print(head);

    insertAtTail(tail,44);
    print(head);

    insertAtPosition(tail,head,2,10);
    print(head);
    insertAtPosition(tail,head,3,70);
    print(head);
    insertAtPosition(tail,head,5,40);
    print(head);

    cout<<"Length is: "<<getLength(head)<<endl;

    deleteNode(1,head);
    print(head);
    cout<<"Length is: "<<getLength(head)<<endl;
    
    deleteNode(3,head);
    print(head);
    cout<<"Length is: "<<getLength(head)<<endl;


    return 0;
}