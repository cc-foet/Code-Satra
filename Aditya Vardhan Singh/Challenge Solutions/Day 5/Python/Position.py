def find_position(arr1, arr2, k):
    arr3 = []
    n = len(arr1)
    m = len(arr2)
    i = j = 0

    while i < n and j < m:
        if arr1[i] < arr2[j]:
            arr3.append(arr1[i])
            i += 1
        else:
            arr3.append(arr2[j])
            j += 1
    
    while i < n:
        arr3.append(arr1[i])
        i += 1
    
    while j < m:
        arr3.append(arr2[j])
        j += 1
    
    return arr3[k-1]


arr1 = [2, 3, 6, 7, 9]
arr2 = [1, 4, 8, 10]
k = 5

print( find_position(arr1, arr2, k) )