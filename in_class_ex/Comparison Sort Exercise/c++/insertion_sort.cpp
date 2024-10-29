#include <iostream>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
