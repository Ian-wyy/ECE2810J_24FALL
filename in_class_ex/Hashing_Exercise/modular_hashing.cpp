#include <iostream>
#include <list>
#include <string>
#include <vector>

const int TABLE_SIZE = 101; // Use a prime number to reduce collisions
const int PRIME = 31;       // Commonly used prime for polynomial hashing

class HashMap {
private:
  struct HashEntry {
    std::string key;
    std::string value;
    bool isOccupy;
    //TODO: pay attention I add an construct function here
    HashEntry(std::string key, std::string value): key(key), value(value), isOccupy(false){}
  };

  std::vector<HashEntry> table; 

  int hashFunction(const std::string &key) {
    // write your own hash function
    int num = 0;
    for (int i = 0; i < key.size(); i++) {
        num+=key[i];
    }
    return num % 101;
  }

public:
  void insert(const std::string &key, const std::string &value) {
    // write your own insert function
    int hash = hashFunction(key);
    if(table[hash].isOccupy == false)
    {table[hash].key = key;
    table[hash].value = value;
    table[hash].isOccupy =true;}
    return;
  }

  bool find(const std::string &key, std::string &value) {
    // write your own find function
    int index = hashFunction(key);
    if (table[index].isOccupy == true) {
    value = table[index].value;
    return true;
    }
    return false;
  }

  void remove(const std::string &key) {
    int index = hashFunction(key);
    table[index].isOccupy = false;
    return;
  }
};

int main() {
  HashMap map;

  // Using initializer list
  std::initializer_list<std::pair<std::string, std::string>> entries = {
      {"John", "Doe"},    {"Jane", "Smith"},     {"James", "Brown"},
      {"Anna", "White"},  {"Robert", "Red"},     {"Maria", "Green"},
      {"Chris", "Black"}, {"Eva", "Gold"},       {"Sam", "Silver"},
      {"Grace", "Blue"},  {"Max", "Gray"},       {"Nina", "Pink"},
      {"Ron", "Yellow"},  {"Sophie", "Crimson"}, {"Will", "Magenta"}};

  for (const auto &entry : entries) { // using auto for type inference
    map.insert(entry.first, entry.second);
  }

  std::string value;
  if (map.find("Jane", value)) {
    std::cout << "Value associated with 'Jane': " << value << std::endl;
  } else {
    std::cout << "'Jane' not found." << std::endl;
  }

  if (map.find("Max", value)) {
    std::cout << "Value associated with 'Max': " << value << std::endl;
  } else {
    std::cout << "'Max' not found." << std::endl;
  }

  map.remove("Max");
  if (map.find("Max", value)) {
    std::cout << "Value associated with 'Max' after removal: " << value
              << std::endl;
  } else {
    std::cout << "'Max' not found after removal." << std::endl;
  }

  return 0;
}
