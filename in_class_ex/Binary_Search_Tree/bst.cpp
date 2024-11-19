#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        insertRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    void remove(int value) {
        root = removeRecursive(root, value);
    }

    void inorderTraversal() {
        inorderRecursive(root);
    }

private:
    void insertRecursive(Node*& node, int value) {
        // Exercise 1
    }

    bool searchRecursive(Node* node, int value) {
        // Exercise 2
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* removeRecursive(Node* node, int value) {
        // Exercise 3

        return node;
    }

    void inorderRecursive(Node* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            std::cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(45);
    bst.insert(65);
    bst.insert(85);

    std::cout << "Inorder Traversal before deleting: ";
    bst.inorderTraversal();
    std::cout << std::endl;


    return 0; // remove after Exercise 1.

    // Search for a value (60)
    int searchValue = 60;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the BST." << std::endl;
    } else {
        std::cout << searchValue << " not found in the BST." << std::endl;
    }

    return 0; // remove after Exercise 2.
    // Delete a leaf node (10)
    int deleteValue1 = 10;
    bst.remove(deleteValue1);

    std::cout << "Inorder Traversal after deleting " << deleteValue1 << ": ";
    bst.inorderTraversal();
    std::cout << std::endl;

    // Delete a node with one child (85)
    int deleteValue2 = 85;
    bst.remove(deleteValue2);

    std::cout << "Inorder Traversal after deleting " << deleteValue2 << ": ";
    bst.inorderTraversal();
    std::cout << std::endl;

    // Delete a node with two children (70)
    int deleteValue3 = 70;
    bst.remove(deleteValue3);

    std::cout << "Inorder Traversal after deleting " << deleteValue3 << ": ";
    bst.inorderTraversal();
    std::cout << std::endl;

    return 0;
}



