#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void percolateDown(int index) {
        // write your own function
    }

public:
    MinHeap(const vector<int>& arr) : heap(arr) {
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            percolateDown(i);
        }
    }

    void enqueue(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    int dequeueMin() {
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        percolateDown(0);
        return minVal;
    }

    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> data = {3, 8, 5, 1, 6, 9, 4};

    MinHeap minHeap(data);

    cout << "Heap after heapifying: ";
    minHeap.display();

    cout << "Dequeuing all elements to verify heap property:\n";
    while (!data.empty()) {
        cout << minHeap.dequeueMin() << " ";
        data.pop_back();  // To emulate the heap getting emptied
    }
    cout << endl;

    return 0;
}
