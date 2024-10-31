#include <iostream>
#include <iomanip>
#include <queue>

// Define a struct for a BinaryTreeNode
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

// Function to display the binary tree structure (left to right)
void display(BinaryTreeNode* root, int level = 0) {
    if (root == nullptr) {
        return;
    }

    const int spacing = 4;

    // Print the right subtree
    display(root->right, level + 1);

    // Print the current node
    std::cout << std::setw(level * spacing) << " ";
    std::cout << root->data << std::endl;

    // Print the left subtree
    display(root->left, level + 1);
}

// Function to insert a value into a binary tree
BinaryTreeNode* insert(BinaryTreeNode* root, int value) {
    // write your own function
}

// Function to find a value in a binary tree
bool find(BinaryTreeNode* root, int value) {
    // write your own function
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(1);

    root->left = new BinaryTreeNode(2);

    // play with the tree construction here add more elements to the tree

    // Display the binary tree structure (left to right)
    std::cout << "Binary Tree Structure:" << std::endl;
    display(root);

    // Insert a new value into the tree
    int insertValue = 8;
    insert(root, insertValue);
    std::cout << "After inserting value " << insertValue << ":" << std::endl;
    display(root);

    // Find and print a value in the tree
    int searchValue = 5;
    if (find(root, searchValue)) {
        std::cout << "Found value " << searchValue << " in the tree." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    // Clean up memory (you would normally free the entire tree in a real program)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
