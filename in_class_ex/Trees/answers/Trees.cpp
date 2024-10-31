#include <iostream>
#include <vector>

// Define a struct for the TreeNode
struct TreeNode {
    int data;
    std::vector<TreeNode*> children;

    // Constructor for TreeNode struct with an integer parameter 'value'
    TreeNode(int value)
        // Member initializer list: Initialize 'data' member with the value passed as 'value'
        : data(value)
    {
        // Constructor body (empty in this case)
        // Additional initialization or code can be placed here if needed
    }
};

// Define the GeneralTree class
class GeneralTree {
public:
    GeneralTree() : root(new TreeNode(1)) {}

    // Function to insert a value as a child of a parent node
    void insert(int parentValue, int value) {
        TreeNode* parentNode = findNode(root, parentValue);
        if (parentNode != nullptr) {
            TreeNode* newNode = new TreeNode(value);
            parentNode->children.push_back(newNode);
        } else {
            std::cout << "Parent not found. Cannot insert " << value << "." << std::endl;
        }
    }

    // Function to search for a value in the tree
    bool search(int value) {
        return findNode(root, value) != nullptr;
    }

    // Function to remove a value from the tree
    void remove(int value) {
        removeNode(root, value);
    }

    // Function to display the tree structure
    void displayTree() {
        displayNode(root, "");
    }

private:
    TreeNode* root;

    // Helper function to find a node with a specific value
    TreeNode* findNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->data == value) {
            return node;
        }

        for (TreeNode* child : node->children) {
            TreeNode* foundNode = findNode(child, value);
            if (foundNode != nullptr) {
                return foundNode;
            }
        }

        return nullptr;
    }

    // Helper function to remove a node with a specific value
    void removeNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return;
        }

        for (size_t i = 0; i < node->children.size(); ++i) {
            if (node->children[i]->data == value) {
                // Found the node to remove
                delete node->children[i];
                node->children.erase(node->children.begin() + i);
                return;
            }
        }

        for (TreeNode* child : node->children) {
            removeNode(child, value);
        }
    }

    // Helper function to display a node and its children recursively
    void displayNode(TreeNode* node, std::string prefix) {
        if (node == nullptr) {
            return;
        }

        // Print the node's data with a hierarchical structure
        std::cout << prefix << "└─ " << node->data << std::endl;

        // Add appropriate prefix for children
        std::string childPrefix = prefix + "   ";
        
        // Recursively display children
        for (size_t i = 0; i < node->children.size(); ++i) {
            if (i < node->children.size() - 1) {
                displayNode(node->children[i], childPrefix + "├─ ");
            } else {
                displayNode(node->children[i], childPrefix + "└─ ");
            }
        }
    }
};

int main() {
    GeneralTree tree;

    // Insert nodes into the general tree
    tree.insert(1, 2); // Insert 2 as a child of 1
    tree.insert(1, 3); // Insert 3 as a child of 1
    tree.insert(2, 4); // Insert 4 as a child of 2
    tree.insert(2, 5); // Insert 5 as a child of 2
    tree.insert(3, 6); // Insert 6 as a child of 3
    tree.insert(4, 7); // Insert 7 as a child of 4
    tree.insert(4, 8); // Insert 8 as a child of 4

    // Display the tree structure
    std::cout << "Tree Structure:" << std::endl;
    tree.displayTree();

    // Search for values
    int searchValue = 7;
    if (tree.search(searchValue)) {
        std::cout << searchValue << " found in the tree." << std::endl;
    } else {
        std::cout << searchValue << " not found in the tree." << std::endl;
    }

    // Remove a value from the tree
    int removeValue = 3;
    tree.remove(removeValue);
    std::cout << "After removing " << removeValue << ":" << std::endl;

    // Display the updated tree structure
    std::cout << "Updated Tree Structure:" << std::endl;
    tree.displayTree();

    return 0;
}
