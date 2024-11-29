#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Item {
    int key;
    // Additional item properties can be added here
};

struct Node {
    Item item;
    Node *left;
    Node *right;
    int height;

    Node(Item i) : item(i), left(nullptr), right(nullptr), height(1) {}
};

int height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

void AdjustHeight(Node *&root) {
    root->height = 1 + max(height(root->left), height(root->right));
}

void Balance(Node *&root) {
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        root = rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        root = leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
}

void insert(Node *&root, Item item) {
    if (root == nullptr) {
        root = new Node(item);
        return;
    }
    if (item.key < root->item.key)
        insert(root->left, item);
    else if (item.key > root->item.key)
        insert(root->right, item);

    AdjustHeight(root);
    Balance(root);
}

int treeHeight(Node* node) {
    if (node == nullptr)
        return 0;
    else {
        int lHeight = treeHeight(node->left);
        int rHeight = treeHeight(node->right);

        if (lHeight > rHeight)
            return (lHeight + 1);
        else return (rHeight + 1);
    }
}

void printGivenLevel(Node* root, int level, int indentSpace) {
    if (root == nullptr) {
        for (int i = 0; i < indentSpace; i++)
            cout << " ";
        cout << "   ";
        return;
    }
    if (level == 1) {
        for (int i = 0; i < indentSpace; i++)
            cout << " ";
        cout << root->item.key;
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1, indentSpace - 3);
        printGivenLevel(root->right, level - 1, indentSpace - 3);
    }
}

void printTree(Node *root) {
    if (!root) {
        cout << "<empty tree>" << endl;
        return;
    }

    queue<Node*> nodesQueue;
    int level = 0;
    int currentLevelNodes = 1;
    int nextLevelNodes = 0;
    nodesQueue.push(root);

    int treeHeight = height(root);
    int spacing = pow(2, treeHeight); // Adjust this value as needed

    while (!nodesQueue.empty()) {
        Node *currentNode = nodesQueue.front();
        nodesQueue.pop();
        currentLevelNodes--;

        if (currentNode) {
            cout << string((spacing / pow(2, level)) - 1, ' ') << currentNode->item.key;
            nodesQueue.push(currentNode->left);
            nodesQueue.push(currentNode->right);
            nextLevelNodes += 2;
        } else {
            cout << string((spacing / pow(2, level)) - 1, ' ') << " ";
            nodesQueue.push(nullptr);
            nodesQueue.push(nullptr);
        }

        if (currentLevelNodes == 0) {
            cout << endl;
            currentLevelNodes = nextLevelNodes;
            nextLevelNodes = 0;
            level++;
        }
    }
}

int main() {
    Node *root = nullptr;
    Item items[] = {{10}, {20}, {30}, {40}, {50}, {25}, {15}, {5}, {35}, {45}, {55}, {60}, {65}, {70}, {75}};

    for (auto &item : items) {
        insert(root, item);
    }

    cout << "Visual representation of the constructed AVL tree:\n";
    printTree(root);

    return 0;
}
