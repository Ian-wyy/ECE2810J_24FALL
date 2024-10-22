#include <iostream>
#include <vector>
#include <list>

const int TABLE_SIZE = 151;

class HashMap {
private:
    struct HashEntry {
        int key;
        std::string value;
    };

    std::vector<std::list<HashEntry>> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashMap() : table(TABLE_SIZE) {}  // Initialize the table to the defined size

    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        for (const auto& entry : table[index]) {
            if (entry.key == key) {
                // Key already exists; with separate chaining, we can choose
                // either to update its value or just leave it.
                // For this example, let's just leave it.
                return;
            }
        }
        table[index].push_back({key, value});
    }

    bool find(int key, std::string& value) {
        int index = hashFunction(key);
        for (const auto& entry : table[index]) {
            if (entry.key == key) {
                value = entry.value;
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const HashEntry& entry) { return entry.key == key; });
    }
};

int main() {
    HashMap map;

    // Insert 50 entries with keys that will cause conflicts
    for (int i = 0; i < 25; ++i) {
        map.insert(1 + i, "Person " + std::to_string(i));
    }

    for (int i = 25; i < 50; ++i) {
        map.insert(1 + i * TABLE_SIZE, "Person " + std::to_string(i));
    }

    // Retrieve values to demonstrate separate chaining works
    for (int i = 0; i < 50; ++i) {
        std::string value;
        if (map.find(1 + i * TABLE_SIZE, value)) {
            std::cout << "Value associated with key " << (1 + i * TABLE_SIZE) << ": " << value << std::endl;
        } else {
            std::cout << "Key " << (1 + i * TABLE_SIZE) << " not found." << std::endl;
        }
    }

    return 0;
}

