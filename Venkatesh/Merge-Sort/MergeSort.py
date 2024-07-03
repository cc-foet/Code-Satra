def merge_sort(array, n, m):
    sorted = array[:n]
    unsorted = array[n: n+m]

    def merge_sort_recursion(array):
        if len(array) > 1:
            mid = len(array) // 2
            left = array[:mid]
            right = array[mid:]

            merge_sort_recursion(left)
            merge_sort_recursion(right)

            i = j = k = 0
            while i < len(left) and j < len(right):
                if left[i] < right [j]:
                    array[k] = left[i]
                    i += 1
                else:
                    array[k] = right[j]
                    j += 1
                k += 1
            
            while i < len(left):
                array[k] = left[i]
                i += 1
                k += 1

            while j < len(right):
                array[k] = right[j]
                j += 1
                k += 1
    
    merge_sort_recursion(unsorted)

    def merge(sorted, unsorted):
        result = []
        while sorted and unsorted:
            if sorted[0] < unsorted[0]:
                result.append(sorted.pop(0))
            else:
                result.append(unsorted.pop(0))
        result.extend(sorted or unsorted)
        return result

    sorted_array = merge(sorted, unsorted)
    return sorted_array


arr = [1, 3, 5, 9, 84, 26, 62, 12, 71, 20]
n = 4
m = 6

print(merge_sort(arr, n, m))