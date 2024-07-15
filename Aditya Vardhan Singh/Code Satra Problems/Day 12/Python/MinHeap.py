import heapq

def merge_array(arr):
    K = len(arr)
    N = len(arr[0])
    
    min_heap = []
    
    # Insert the first element of each array into the heap
    for i in range(K):
        heapq.heappush(min_heap, (arr[i][0], i, 0))
    
    result = []
    
    while min_heap:
        value, row, col = heapq.heappop(min_heap)
        result.append(value)
        
        if col + 1 < N:
            heapq.heappush(min_heap, (arr[row][col + 1], row, col + 1))
    
    return result

arr = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]

output = merge_array(arr)
print(output)

