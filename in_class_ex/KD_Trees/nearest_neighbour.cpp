#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

struct Point2D {
    int x;
    int y;
};

struct node {
    Point2D key; // The key is the point in 2D space
    std::vector<std::pair<int, int>> domain; // The domain of the current node
    node* left_subtree;
    node* right_subtree;

    node(const Point2D& k) : key(k), left_subtree(nullptr), right_subtree(nullptr) {
        domain.push_back({std::numeric_limits<int>::min(), std::numeric_limits<int>::max()}); // X domain
        domain.push_back({std::numeric_limits<int>::min(), std::numeric_limits<int>::max()}); // Y domain
    }
};

class KdTree {
public:
    KdTree() : root(nullptr) {}
    
    ~KdTree() {
        destroyTree(root);
    }
    
    void build(std::vector<Point2D> points) {
        root = buildTree(points.begin(), points.end(), 0);
    }
    
    Point2D nearestNeighbor(const Point2D& queryPoint) {
        Point2D nearest = {0, 0};
        double nearestDist = std::numeric_limits<double>::max();
        nearestNeighborSearch(root, queryPoint, 0, nearest, nearestDist);
        return nearest;
    }

private:
    node* root;

    static node* buildTree(typename std::vector<Point2D>::iterator start, typename std::vector<Point2D>::iterator end, int depth) {
        if (start >= end) return nullptr;

        int axis = depth % 2;
        auto median = start + (end - start) / 2;
        std::nth_element(start, median, end, [axis](const Point2D& a, const Point2D& b) {
            return (axis == 0) ? (a.x < b.x) : (a.y < b.y);
        });

        node* n = new node(*median);
        n->left_subtree = buildTree(start, median, depth + 1);
        // implement your own line
        return n;
    }

    static void nearestNeighborSearch(node* currentNode, const Point2D& queryPoint, int depth, Point2D& bestPoint, double& bestDist) {
        if (!currentNode) return;

        double d = distance(queryPoint, currentNode->key);
        if (d < bestDist) {
            bestDist = d;
            bestPoint = currentNode->key;
        }

        int axis = depth % 2;
        
        // implement your own function
    }

    static double distance(const Point2D& a, const Point2D& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    static void destroyTree(node* currentNode) {
        if (currentNode) {
            destroyTree(currentNode->left_subtree);
            destroyTree(currentNode->right_subtree);
            delete currentNode;
        }
    }
};

int main() {
    KdTree tree;

    // Insert points into the tree
    std::vector<Point2D> points = {
        {2, 3}, {5, 4}, {9, 6}, {4, 7}, {8, 1}, {7, 2}
    };

    tree.build(points);

    // Perform nearest neighbor search
    Point2D queryPoint = {5, 5};
    Point2D nearest = tree.nearestNeighbor(queryPoint);

    std::cout << "The nearest neighbor is at: (" << nearest.x << ", " << nearest.y << ")" << std::endl;

    return 0;
}
