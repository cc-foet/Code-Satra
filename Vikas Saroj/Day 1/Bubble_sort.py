# This code short the array using bubble sorting.
# and prints the sorted array with the number of swaps performed.

def bubble_sort_with_swaps(arr):
    n = len(arr)
    total_swaps = 0
    
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                total_swaps += 1
    
    return arr, total_swaps


arr = [64, 34, 25, 12, 22, 11, 90]

sorted_arr, num_swaps = bubble_sort_with_swaps(arr)

print(f"Sorted array: {sorted_arr}")
print(f"Number of swaps: {num_swaps}")


#code by Vikas Saroj.