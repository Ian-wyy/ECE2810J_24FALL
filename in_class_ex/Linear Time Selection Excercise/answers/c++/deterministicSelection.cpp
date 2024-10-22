#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(vector<int>& arr, int low, int high, int pivot) {
    int pivotindex = low;
    for (int i = low; i <= high; i++) {
        if (arr[i] == pivot) {
            pivotindex = i;
            break;
        }
    }
    swap(arr[low], arr[pivotindex]);
    // int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[left] < pivot) left++;
        while (left <= right && arr[right] > pivot) right--;

        if (left <= right) {
            swap(arr[left], arr[right]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[right]);
    return right;
}

// Function to find the median of a small vector
int findMedian(vector<int>& arr, int left, int right) {
    sort(arr.begin() + left, arr.begin() + right + 1);
    return arr[(left + right) / 2];
}

// Deterministic selection algorithm
int deterministicSelection(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int n = high - low + 1;
    // Divide the array into groups of size 5
    vector<int> medians;
    for (int i = 0; i <= n / 5; i++) {
        int left = low + i * 5;
        int right = left + 4;
        if (right > high) {
            right = high;
        }
        medians.push_back(findMedian(arr, left, right));
    }

    // Find the median of medians

    //int medianOfMedians = findMedian(medians, 0, medians.size() - 1);
    int medianOfMedians = deterministicSelection(medians, 0, medians.size() - 1, medians.size() / 2);

    // Partition the array based on the median of medians
    int pivotIndex = partition(arr, low, high, medianOfMedians);

    if (k == pivotIndex) {
        return arr[pivotIndex];
    } else if (k < pivotIndex) {
        return deterministicSelection(arr, low, pivotIndex - 1, k);
    } else {
        return deterministicSelection(arr, pivotIndex + 1, high, k);
    }
}

int main() {
    vector<int> arr = {34, 12, 78, 45, 9, 23, 67, 1, 56, 87, 22, 3, 98, 54, 32, 11, 76, 4, 88, 29, 65};
    int k = 10;

    int result = deterministicSelection(arr, 0, arr.size() - 1, k - 1);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
