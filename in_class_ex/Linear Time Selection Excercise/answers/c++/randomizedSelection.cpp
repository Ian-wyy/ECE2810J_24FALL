#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
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

int randomizedSelection(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    // int pivotIndex = rand() % (high - low + 1) + low;
    // swap(arr[low], arr[pivotIndex]);

    int pivotPosition = partition(arr, low, high);

    if (k == pivotPosition) {
        return arr[pivotPosition];
    } else if (k < pivotPosition) {
        return randomizedSelection(arr, low, pivotPosition - 1, k);
    } else {
        return randomizedSelection(arr, pivotPosition + 1, high, k);
    }
}

int main() {
    srand(time(0));

    vector<int> arr = {34, 12, 78, 45, 9, 23, 67, 1, 56, 87, 22, 3, 98, 54, 32, 11, 76, 4, 88, 29, 65};
    int k = 10;

    int result = randomizedSelection(arr, 0, arr.size() - 1, k - 1);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}