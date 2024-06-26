#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;  // Adjust the table size as needed

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        // Initialize all elements to -1 (indicating an empty slot)
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = -1;
        }
    }

    // Hash function using modulo operator
    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Quadratic probing function
    int quadraticProbe(int index, int attempt) {
        return (index + attempt * attempt) % TABLE_SIZE;
    }

    // Insert a key into the hash table using quadratic probing
    void insert(int key) {
        int index = hash(key);
        int attempt = 0;

        while (table[index] != -1) {
            // Quadratic probing: move to the next slot using a quadratic function
            index = quadraticProbe(index, ++attempt);
        }

        // Insert the key into the found empty slot
        table[index] = key;
    }

    // Display the contents of the hash table
    void display() {
        cout << "Hash Table: ";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != -1) {
                cout << "[" << i << "]=" << table[i] << " ";
            }
            else {
                cout << "[" << i << "]=EMPTY ";
            }
        }
        cout << endl;
    }
};

int main() {
    HashTable hashTable;

    // Given dataset
    int dataset[] = { 79, 69, 98, 72, 14, 50 };
    int datasetSize = sizeof(dataset) / sizeof(dataset[0]);

    // Insert each element into the hash table
    for (int i = 0; i < datasetSize; ++i) {
        hashTable.insert(dataset[i]);
    }

    // Display the resulting hash table
    hashTable.display();

    return 0;
}