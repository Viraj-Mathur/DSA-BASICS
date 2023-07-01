#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class HashTable {
private:
    vector<Node*> table;
    int size;
    int hashFunc(int key) {
        return key % size;
    }
public:
    HashTable(int size) {
        this->size = size;
        table.resize(size);
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunc(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = nullptr;

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool search(int key) {
        int index = hashFunc(key);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunc(key);
        Node* temp = table[index];

        if (temp == nullptr) {
            return;
        }

        if (temp->data == key) {
            table[index] = temp->next;
            delete temp;
            return;
        }

        Node* prev = temp;
        temp = temp->next;
        while (temp != nullptr) {
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable hashTable(size);

    int choice, key;
    do {
        cout << "MENU:" << endl;
        cout << "1. Insert a key" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Remove a key" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            hashTable.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (hashTable.search(key)) {
                cout << "Key found in hash table." << endl;
            }
            else {
                cout << "Key not found in hash table." << endl;
            }
            break;
        case 3:
            cout << "Enter key to remove: ";
            cin >> key;
            hashTable.remove(key);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
