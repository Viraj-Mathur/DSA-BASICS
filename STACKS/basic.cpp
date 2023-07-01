#include<iostream>

using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

// for behaviour
    Stack(int size){
        this-> size = size;
        arr = new int [size];
        top = -1;
    }

    void push(int element){ 
        if(size - top > 1){ // if empty space available for insertion
            top++;
            arr[top] = element;
        }
        else{
            cout<<"STACK OVERFLOW!!!!"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"STACK UNDERFLOW!!!!"<<endl;
        }
    }

    int peek(){
        if(top>=0 ){  // for valid range
            return arr[top];
        }
        else{
            cout<<"STACK IS EMPTY!!!!"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }


};

int main(){
    
    Stack s(6);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<s.peek()<<endl;
    return 0;
}