#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

// A simple hash function that takes an integer key and returns an index
int customHash(int key, int tableSize) {
    return key % tableSize;
}

class HashTable {
public:
    HashTable(int size) : tableSize(size) {
        table.resize(size);
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = customHash(key, tableSize);
        table[index].push_back(std::make_pair(key, value));
    }

    // Find the value associated with a key
    int find(int key) {
        int index = customHash(key, tableSize);
        
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }

        return -1; // Key not found
    }

    // Delete a key-value pair by key
    void deleteKey(int key) {
        int index = customHash(key, tableSize);
        
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }

private:
    int tableSize;
    std::vector<std::list<std::pair<int, int>>> table;
};

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    HashTable hashTable(nums.size()); // Create a hash table for storing complement values

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // Check if the complement exists in the hash table
        int complementIndex = hashTable.find(complement);
        if (complementIndex != -1) {
            return {complementIndex, i};
        }

        // Add the current number and its index to the hash table
        hashTable.insert(nums[i], i);
    }

    return {}; // No solution found
}

int main() {
    std::vector<int> nums = {3, 1, 5, 7, 4, 9, 2};
    int target = 10;

    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices of the two numbers: " << result[0] << " and " << result[1] << std::endl;
        std::cout << "Numbers: " << nums[result[0]] << " and " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
