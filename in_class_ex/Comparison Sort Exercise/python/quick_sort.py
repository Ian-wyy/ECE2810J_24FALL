def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    # Put your code here

    return 

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        # Put your code here

# Example usage:
arr = [10, 7, 8, 9, 1, 5]
print("Original Array:", arr)
quick_sort(arr, 0, len(arr) - 1)
print("Sorted Array:", arr)
