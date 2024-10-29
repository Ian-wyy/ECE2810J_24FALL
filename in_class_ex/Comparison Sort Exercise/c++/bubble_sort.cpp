#include <iostream>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    std::cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
