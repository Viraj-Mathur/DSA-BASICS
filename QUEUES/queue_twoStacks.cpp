#include <iostream>
#include <stack>
using namespace std;
// MAKE A QUEUE USING TWO STACKS
class Queue {
    stack<int> forward;
    stack<int> reverse;

public:
    void enqueue(int data) {
        forward.push(data);
    }

    int dequeue() {
        if (reverse.empty()) {
            while (!forward.empty()) {
                reverse.push(forward.top());
                forward.pop();
            }
        }
        if (reverse.empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        } else {
            int data = reverse.top();
            reverse.pop();
            return data;
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << queue.dequeue() << endl;
    queue.enqueue(40);
    cout << queue.dequeue() << endl; 
    cout << queue.dequeue() << endl; 
    cout << queue.dequeue() << endl; 
    cout << queue.dequeue() << endl; 
    return 0;
}
