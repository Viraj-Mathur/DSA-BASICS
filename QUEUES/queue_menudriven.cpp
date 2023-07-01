#include <iostream>
using namespace std;

class Queue {
    int max_size;
    int* queue;
    int front;
    int rear;
    int size;

public:
    Queue(int max_size) {
        this->max_size = max_size;
        queue = new int[max_size];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int data) {
        if (isfull()) {
            cout << "Queue is full." << endl;
        } else {
            rear = (rear + 1) % max_size;
            queue[rear] = data;
            size++;
        }
    }

    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
            return -1;
        } else {
            int data = queue[front];
            front = (front + 1) % max_size;
            size--;
            return data;
        }
    }

    bool isfull() {
        return size == max_size;
    }

    bool isempty() {
        return size == 0;
    }
};

int main() {
    int choice, data;
    Queue queue(5);

    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isFULL" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                cout << "Dequeued data: " << queue.dequeue() << endl;
                break;
            case 3:
                cout << "Check if Empty: " << queue.isempty()<< endl;
                break;
            case 4:
                cout << "Check if Full" << queue.isfull()<<endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
