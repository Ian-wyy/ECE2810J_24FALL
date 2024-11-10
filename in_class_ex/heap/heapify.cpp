#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
  vector<int> heap;

  int getMin(int a, int b, int c) {
    if (a <= b && a <= c) {
      return 1;
    } else if (b <= c) {
      return 2;
    } else {
      return 3;
    }
  }

  void percolateDown(int index) {
    // write your own function
    if (2 * index + 1 > heap.size() -1) {
      return;
    }
    if (2 * index + 2 > heap.size() -1) {
      if (heap[index] > heap[2 * index + 1]) {
        swap(heap[index], heap[2 * index + 1]);
        percolateDown(2*index + 1);
      }
    } else {
      switch (getMin(heap[index], heap[2 * index + 1], heap[2 * index + 2])) {
      case 1:
        break;
      case 2:
        swap(heap[index], heap[2 * index + 1 ]);
        percolateDown(2 * index + 1);
        break;
      case 3:
        swap(heap[index], heap[2 * index + 2]);
        percolateDown(2 * index + 2);
        break;
      }
    }
  }

public:
  MinHeap(const vector<int> &arr) : heap(arr) {
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
    data.pop_back(); // To emulate the heap getting emptied
  }
  cout << endl;

  return 0;
}
