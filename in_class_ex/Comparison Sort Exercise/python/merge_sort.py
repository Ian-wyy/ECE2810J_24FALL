def merge(arr, left, right):
    i = j = k = 0

    # Put your code here


def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        # Put your code here

        merge(arr, left_half, right_half)

# Example usage:
arr = [12, 11, 13, 5, 6, 7]
print("Original Array:", arr)
merge_sort(arr)
print("Sorted Array:", arr)
