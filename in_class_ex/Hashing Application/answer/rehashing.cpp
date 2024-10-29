#include <iostream>
#include <vector>
#include <list>

class HashTable {
public:
    HashTable(int initialSize) : tableSize(initialSize) {
        table.resize(initialSize);
    }

    // Custom hash function that returns an index
    int customHash(const std::string& key) {
        int hashValue = 0;

        for (char c : key) {
            hashValue += static_cast<int>(c);
        }

        return hashValue % tableSize;
    }

    // Rehash function to resize the table and redistribute elements
    void rehash(int newSize) {
        if (newSize <= tableSize) {
            std::cout << "New size should be greater than the current size.\n";
            return;
        }

        std::vector<std::list<std::pair<std::string, std::string>>> newTable(newSize);

        for (int i = 0; i < tableSize; ++i) {
            for (auto& pair : table[i]) {
                int newIndex = customHash(pair.first) % newSize;
                newTable[newIndex].push_back(pair);
            }
        }

        tableSize = newSize;
        table = std::move(newTable);
    }

    void insert(const std::string& key, const std::string& value) {
        int index = customHash(key);
        table[index].push_back(std::make_pair(key, value));
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }

private:
    int tableSize;
    std::vector<std::list<std::pair<std::string, std::string>>> table;
};

int main() {
    // Create a hash table with an initial size
    HashTable hashTable(5);

    // Insert key-value pairs
    hashTable.insert("apple", "red");
    hashTable.insert("banana", "yellow");
    hashTable.insert("cherry", "red");
    hashTable.insert("date", "brown");
    hashTable.insert("fig", "purple");

    // Display the initial contents of the hash table
    std::cout << "Initial Hash Table:\n";
    hashTable.display();

    // Perform rehashing to resize the table to a larger size (newSize)
    hashTable.rehash(10);

    // Display the updated contents of the hash table after rehashing
    std::cout << "\nAfter Rehashing:\n";
    hashTable.display();

    return 0;
}
