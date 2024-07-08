def bubble_sort(array):
    count = 0
    for i in range(len(array)):
        for j in range(len(array)-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
                count += 1
    return count

arr = [15, 8, 26, 4, 62, 41, 32, 9, 21, 10]
count = bubble_sort(arr)

print("Sorted array:", arr)
print("Number of swaps:", count)