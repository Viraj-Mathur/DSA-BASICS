#include<iostream>

using namespace std;


class Node_Stack{
    public:
    int data;
    Node_Stack* link;  //for creating linked list

    // calling constructor
    Node_Stack(int n){
        this->data = n;
        this ->link = NULL;
    }
};

class Stack{
    Node_Stack* top;
    
    public:
    
        Stack(){
            top = NULL;
        }

        void push(int data){
            Node_Stack* temp = new Node_Stack(data);  //creating a new node temp and allocating memory in heap
            
            // checking if stack (heap) is full
            // then inserting an element would lead tp stack overflow
            if(!temp){
                cout<<"STACK OVERFLOW"<<endl;
                exit(1);
            } 

            temp->data = data; // initialising data in temp
            temp->link = top;
            top = temp;

        }

        bool isEmpty(){
            return top == NULL;
        }

        int peek(){
            if(!isEmpty()){
                return top->data;
            }
            else{
                exit(1);
            }
        }

        void pop(){
            Node_Stack* temp;
            // checking if stack is underflow
            if(top == NULL){
                cout<<"STACK UNDERLFOW!!!!"<<endl;
                exit(1);
            }
            else{
                temp = top; //assigning top node to temp
                top = top-> link; //assigning second node to top
                // now as the link between first and second node released delete the node
                delete(temp);
            }
        }

        void display(){
        Node_Stack* temp;
  
        // Check for stack underflow
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
  
                // Print node data
                cout << temp->data;
  
                // Assign temp link to temp
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

int main(){
    Stack s;
  
    // Push the elements of stack
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
  
    // Display stack elements
    s.display();
    return 0;
}