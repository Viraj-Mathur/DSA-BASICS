#include <iostream>
using namespace std;

const int tableSize = 10;

class HashTable {
private:
    int *table;
    int count;

public:
    HashTable() {
        table = new int[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = -1;
        }
        count = 0;
    }

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hashFunction(key);
        if (table[index] == -1) {
            table[index] = key;
            count++;
        } else {
            int i = 1;
            while (table[(index + i) % tableSize] != -1) {
                i++;
            }
            table[(index + i) % tableSize] = key;
            count++;
        }
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << " -> ";
            if (table[i] != -1) {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    hashTable.insert(5);
    hashTable.insert(10);
    hashTable.insert(15);
    hashTable.insert(20);
    hashTable.insert(25);
    hashTable.insert(30);
    hashTable.insert(35);
    hashTable.insert(40);
    hashTable.insert(45);
    hashTable.insert(50);
    hashTable.display();
    return 0;
}
