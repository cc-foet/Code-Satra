def merger(array1, array2):
    i = j = 0
    result = []
    while i < len(array1) and j < len(array2):
        if array1[i] < array2[j]:
            result.append(array1[i])
            i += 1
        else:
            result.append(array2[j])
            j += 1
    return result + array1[i:] + array2[j:]

arr1 = [2, 3, 6, 7, 9]
arr2 = [1, 4, 8, 10]
k = 5

print(merger(arr1, arr2)[k - 1])