/*
Steps for enqueue:
Check the queue is full or not
If full, print overflow and exit
If queue is not full, increment tail and add the element

Steps for dequeue:
Check queue is empty or not
if empty, print underflow and exit
if not empty, print element at the head and increment head
*/

#include<iostream>

using namespace std;

struct Queue{
    int front,rear,capacity;
    int *queue;
    Queue(int c){
        front = rear = 0;
        capacity = c;
        queue =new  int; 
    }

    ~Queue(){
        delete[] queue;
    }

    // function to insert
    void Enqueue(int data){
        if(capacity == rear){
            // checking if queue is full or not
            cout<<"QUEUE IS FULL!!!!!"<<endl;
            return ;
        }
        else{
            queue[rear] = data;  //inserting data
            rear++;
        }
        return;
    }

    // function for delete
    void Dequeue(){
        // checking for empty queue
        if(front == rear){
            cout<<"QUEUE IS EMPTY!!!!!"<<endl;
            return;
        }
        else{
            // shifting all elements from index 2 till rear to the left of one
            for(int i=0;i<rear-1;i++){
                queue[i] = queue[i+1];
            }

            // decrement rear
            rear--;
        }

        return;
    }

    void DisplayQueue(){
        int i;
        if(front == rear){
            cout<<"QUEUE IS EMPTY!!!!!"<<endl;
            return;
        }

        for(i=front;i<rear;i++){
            cout<<queue[i]<<endl;
        }
        return;
    }

    void queueFront(){
        if (front == rear) {
            cout<<"QUEUE IS EMPTY!!!!!"<<endl;
            return;
        }
        cout<<"Front element is: "<<queue[front]<<endl;
        return;
    }
};


int main(){
    
    Queue q(5);

    q.DisplayQueue();

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.DisplayQueue();
    q.queueFront();

    q.Enqueue(60);
    q.DisplayQueue();

    q.Dequeue();
    q.Dequeue();

    cout<<"After deletion of two nodes: "<<endl;

    q.DisplayQueue();
    q.queueFront();
    return 0;
}