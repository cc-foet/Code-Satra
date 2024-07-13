def bubble_sort_and_count(arr):
    swaps = 0
    for i in range(len(arr)):
        no_swap = True
        for j in range(len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swaps += 1
                no_swap = False
        if no_swap:
            break
    return swaps

arr = [64, 34, 25, 12, 22, 11, 90]
print(arr)

swaps = bubble_sort_and_count(arr)
print("Sorted array: ", arr)
print("Number of swaps: ", swaps)
