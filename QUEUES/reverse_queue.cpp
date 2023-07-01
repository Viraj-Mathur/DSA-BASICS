#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Queue {
private:
    queue<int> q;

public:
    void reverse() {
        stack<int> s;
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }

    void enqueue(int x) {
        q.push(x);
    }

    int dequeue() {
        int data = q.front();
        q.pop();
        return data;
    }

    void printQueue() {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Original Queue: ";
    q.printQueue();

    q.reverse();

    cout << "Reversed Queue: ";
    q.printQueue();

    return 0;
}
