#include <iostream>
#include <vector>

using namespace std;

// Function to perform counting sort
void countingSort(vector<int>& arr) {
    // Find the maximum element in the array

    // Create a count array to store the count of each element

    // Count the occurrences of each element in the input array
    
    // Reconstruct the sorted array from the count array

}

int main() {
    // Input array
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    // Display the original array
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform counting sort
    countingSort(arr);

    // Display the sorted array
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
