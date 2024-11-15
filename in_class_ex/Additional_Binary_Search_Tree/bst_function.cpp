#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Helper function to insert a value into the BST
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // Recursive function to insert a value into the BST
    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    // Function to find the predecessor of a given value in the BST
    TreeNode* findPredecessor(int val) {
        return findPredecessorRecursive(root, val, nullptr);
    }

    TreeNode* findPredecessorRecursive(TreeNode* node, int val, TreeNode* predecessor) {
        // Exercise 1
    }

    // Function to find the successor of a given value in the BST
    TreeNode* findSuccessor(int val) {
        return findSuccessorRecursive(root, val, nullptr);
    }

    TreeNode* findSuccessorRecursive(TreeNode* node, int val, TreeNode* successor) {
        // Exercise 2
    }

    // Function to find the minimum value node in the BST
    TreeNode* findMin(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    // Function to find the maximum value node in the BST
    TreeNode* findMax(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        while (node->right != nullptr) {
            node = node->right;
        }

        return node;
    }

    // Function to perform rank search (finding the kth smallest element) in the BST
    int rankSearch(int k) {
        int count = 0;
        return rankSearchRecursive(root, k, count);
    }

    int rankSearchRecursive(TreeNode* node, int k, int& count) {
        // Exercise 3
    }

    // Function to perform range search (finding elements in a given range) in the BST
    void rangeSearch(int low, int high) {
        rangeSearchRecursive(root, low, high);
    }

    void rangeSearchRecursive(TreeNode* node, int low, int high) {
        // Exercise 4
    }
};

int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);
    bst.insert(45);
    bst.insert(55);
    bst.insert(65);

    // Test the implemented functions
    std::cout << "Predecessor of 40: " << bst.findPredecessor(40)->data << std::endl;
    std::cout << "Predecessor of 60: " << bst.findPredecessor(60)->data << std::endl;
    std::cout << "Predecessor of 80: " << bst.findPredecessor(80)->data << std::endl;
    

    return 0; // remove aftern  Exercise 1

    std::cout << "Successor of 40: " << bst.findSuccessor(40)->data << std::endl;
    std::cout << "Successor of 60: " << bst.findSuccessor(60)->data << std::endl;
    std::cout << "Successor of 80: " << bst.findSuccessor(70)->data << std::endl;
    
    return 0; // remove aftern  Exercise 2

    std::cout << "Rank 4: " << bst.rankSearch(4) << std::endl;
    std::cout << "Rank 6: " << bst.rankSearch(6) << std::endl;
    std::cout << "Rank 12: " << bst.rankSearch(12) << std::endl;
    
    return 0; // remove aftern  Exercise 3
    
    std::cout << "Range search (30 to 70): ";
    bst.rangeSearch(30, 70);
    std::cout << std::endl;

    

    return 0;
}
