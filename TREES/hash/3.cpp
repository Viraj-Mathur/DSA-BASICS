#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    string table[TABLE_SIZE];
    int numItems;

public:
    HashTable() {
        numItems = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = "";
        }
    }

    // hash function using division method
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // quadratic probing to avoid collisions
    int quadraticProbing(int key, int i) {
        return (hashFunction(key) + i*i) % TABLE_SIZE;
    }

    // insert item into hash table
    void insert(int key, string value) {
        int index = hashFunction(key);
        int i = 1;
        while (table[index] != "") {
            index = quadraticProbing(key, i);
            i++;
        }
        table[index] = value;
        numItems++;
    }

    // search for item in hash table
    string search(int key) {
        int index = hashFunction(key);
        int i = 1;
        while (table[index] != "") {
            if (table[index] == to_string(key)) {
                return table[index];
            }
            index = quadraticProbing(key, i);
            i++;
        }
        return "";
    }

    // delete item from hash table
    void remove(int key) {
        int index = hashFunction(key);
        int i = 1;
        while (table[index] != "") {
            if (table[index] == to_string(key)) {
                table[index] = "";
                numItems--;
                return;
            }
            index = quadraticProbing(key, i);
            i++;
        }
    }

    // display hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }

    // return number of items in hash table
    int size() {
        return numItems;
    }
};

int main() {
    HashTable ht;
    ht.insert(4, "this");
    ht.insert(14, "is");
    ht.insert(24, "quadratic");
    ht.insert(34, "probing");
    ht.insert(44, "demonstartion");

    cout << "Hash Table: " << endl;
    ht.display();

    cout << "Searching for key 24: " << ht.search(24) << endl;
    cout << "Searching for key 100: " << ht.search(100) << endl;

    ht.remove(14);
    cout << "Hash Table after deleting key 14: " << endl;
    ht.display();

    cout << "Size of hash table: " << ht.size() << endl;

    return 0;
}
