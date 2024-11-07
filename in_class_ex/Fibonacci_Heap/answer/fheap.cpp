#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct FibonacciNode {
    int key;
    FibonacciNode* parent;
    FibonacciNode* child;
    FibonacciNode* left;
    FibonacciNode* right;
    bool marked;
    int degree;

    FibonacciNode(int k) : key(k), parent(nullptr), child(nullptr),
                            left(this), right(this), marked(false), degree(0) {}
};

class FibonacciHeap {
public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}

    void insert(int key) {
        FibonacciNode* newNode = new FibonacciNode(key);
        if (!minNode) {
            minNode = newNode;
        } else {
            // Insert newNode into the root list
            newNode->left = minNode;
            newNode->right = minNode->right;
            minNode->right = newNode;
            newNode->right->left = newNode;
            // Update minNode if necessary
            if (key < minNode->key) {
                minNode = newNode;
            }
        }
        numNodes++;
    }

    int findMin() {
        if (!minNode) {
            std::cerr << "Fibonacci Heap is empty." << std::endl;
            return std::numeric_limits<int>::max();
        }
        return minNode->key;
    }

    FibonacciNode* getMinNode() {
        return minNode;
    }

    void extractMin() {
        if (!minNode) {
            std::cerr << "Fibonacci Heap is empty." << std::endl;
            return;
        }

        FibonacciNode* min = minNode;
        if (min->child) {
            // Attach children of min to the root list
            FibonacciNode* child = min->child;
            do {
                FibonacciNode* nextChild = child->right;
                min->left->right = child;
                child->left = min->left;
                min->left = child;
                child->right = min;
                child->parent = nullptr;
                child->marked = false;
                child = nextChild;
            } while (child != min->child);
        }

        min->left->right = min->right;
        min->right->left = min->left;

        if (min == min->right) {
            minNode = nullptr;
        } else {
            minNode = min->right;
            consolidate();
        }

        delete min;
        numNodes--;
    }

    void decreaseKey(FibonacciNode* node, int newKey) {
        if (newKey > node->key) {
            std::cerr << "New key is greater than the current key." << std::endl;
            return;
        }

        node->key = newKey;
        FibonacciNode* parent = node->parent;

        if (parent && node->key < parent->key) {
            cut(node, parent);
            cascadingCut(parent);
        }

        if (node->key < minNode->key) {
            minNode = node;
        }
    }

private:
    FibonacciNode* minNode;
    int numNodes;

    void consolidate() {
        int maxDegree = static_cast<int>(log2(numNodes)) + 1;
        std::vector<FibonacciNode*> degreeTable(maxDegree, nullptr);

        FibonacciNode* current = minNode;
        std::vector<FibonacciNode*> toVisit;

        do {
            toVisit.push_back(current);
            current = current->right;
        } while (current != minNode);

        for (FibonacciNode* node : toVisit) {
            int degree = node->degree;
            while (degreeTable[degree] != nullptr) {
                FibonacciNode* sameDegreeNode = degreeTable[degree];
                if (node->key > sameDegreeNode->key) {
                    std::swap(node, sameDegreeNode);
                }
                unionNodes(sameDegreeNode, node);
                degreeTable[degree] = nullptr;
                degree++;
            }
            degreeTable[degree] = node;
        }

        minNode = nullptr;

        for (FibonacciNode* node : degreeTable) {
            if (node) {
                if (!minNode) {
                    minNode = node;
                } else {
                    if (node->key < minNode->key) {
                        minNode = node;
                    }
                }
            }
        }
    }

    void unionNodes(FibonacciNode* smaller, FibonacciNode* larger) {
        smaller->right->left = smaller->left;
        smaller->left->right = smaller->right;
        smaller->right = smaller->left = smaller;
        smaller->parent = larger;
        if (!larger->child) {
            larger->child = smaller;
        } else {
            smaller->right = larger->child;
            smaller->left = larger->child->left;
            larger->child->left = smaller;
            smaller->right->left = smaller;
        }
        larger->degree++;
        smaller->marked = false;
    }

    void cut(FibonacciNode* child, FibonacciNode* parent) {
        // Remove child from the child list of parent
        if (child->right == child) {
            parent->child = nullptr;
        } else {
            child->right->left = child->left;
            child->left->right = child->right;
            if (parent->child == child) {
                parent->child = child->right;
            }
        }

        parent->degree--;
        child->marked = false;

        // Add child to the root list
        child->left = minNode;
        child->right = minNode->right;
        minNode->right = child;
        child->right->left = child;

        child->parent = nullptr;
    }

    void cascadingCut(FibonacciNode* node) {
        FibonacciNode* parent = node->parent;
        if (parent) {
            if (!node->marked) {
                node->marked = true;
            } else {
                cut(node, parent);
                cascadingCut(parent);
            }
        }
    }
};

int main() {
    FibonacciHeap fibHeap;

    // Insert nodes
    fibHeap.insert(4);
    fibHeap.insert(2);
    fibHeap.insert(8);
    fibHeap.insert(6);

    std::cout << "Minimum: " << fibHeap.findMin() << std::endl;
    fibHeap.extractMin();
    std::cout << "Minimum after extraction: " << fibHeap.findMin() << std::endl;

    // Decrease the key of a node
    FibonacciNode* nodeToDecrease = fibHeap.getMinNode()->right; // Decrease the second smallest node
    fibHeap.decreaseKey(nodeToDecrease, 1);
    std::cout << "Minimum after decreaseKey: " << fibHeap.findMin() << std::endl;

    // Add more nodes and test decreaseKey
    fibHeap.insert(10);
    fibHeap.insert(3);
    FibonacciNode* nodeToDecrease2 = fibHeap.getMinNode()->right; // Decrease the second smallest node again
    fibHeap.decreaseKey(nodeToDecrease2, 2);
    std::cout << "Minimum after another decreaseKey: " << fibHeap.findMin() << std::endl;

    // Add nodes with equal keys and test decreaseKey
    fibHeap.insert(2); // Insert a node with the same key as an existing node
    std::cout << "Minimum before decreaseKey with equal keys: " << fibHeap.findMin() << std::endl;
    FibonacciNode* nodeToDecrease3 = fibHeap.getMinNode()->right; // Decrease the second smallest node with equal keys
    fibHeap.decreaseKey(nodeToDecrease3, 1);
    std::cout << "Minimum after decreaseKey with equal keys: " << fibHeap.findMin() << std::endl;

    return 0;
}
