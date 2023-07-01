#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL; 
    }

    ~Node(){
        int value = this ->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        } 
        cout<<"Memory is free for node with data: "<< value<< endl;
    }
};

//  NO NEED FOR MAKING HEAD IN CIRCULAR NODE AS WE CAN USE TAIL ONLY TO ACCESS HEAD

void insertNode(Node* &tail, int element, int d){
    
    // for empty list
    if(tail == NULL){
        Node *newNode = new Node(d);  //creating the node
        tail = newNode; 
        newNode -> next = newNode; // new node ka tail points to itself
    }
    else{
        // FOR NON EMPTY LIST(ASSUMING LIST IS ALREADY PRESENT)

        Node* curr = tail;
        while(curr->data!= element){
            curr = curr -> next;
        }  //curr -> element represent element waala node
        
        // node in the middle
        Node* temp = new Node(d);  // creating new node temp
        temp-> next = curr-> next; // temp ka next replaced by currrent ka next(for circular)
        curr -> next = temp; // current ka next points to temp now

    }


}
    
void print(Node* tail){
        Node* temp = tail;
        // do while is used becauses with for loop logic if single list is there it will not be printed
        do{
            cout<<tail->data<<" ";
            tail = tail-> next;
        } while(tail!= temp);
          cout<<endl;
}

void deleteNode(Node* &tail, int value){
    // for empty list
    if(tail == NULL){
        cout<< " Your girlfriend list is empty and so does your list,please check again!!!"<<endl;
        return;
    }
    else{
        // non empty assuming that "Value" is present in thr Linked List

        Node* prev = tail;  // 
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next; 
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL; //delete node
        delete curr;
    }
}


int main(){
    
    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,6);
    print(tail);

    insertNode(tail,6,12);
    print(tail);

    insertNode(tail,6,9);
    print(tail);

    deleteNode(tail,12);
    print(tail);

    return 0;
}