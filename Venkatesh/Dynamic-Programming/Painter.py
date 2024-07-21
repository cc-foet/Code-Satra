def partition(arr, n, k):
    if k == 1:
        return sum(arr[:n])
    if n == 1:
        return arr[0]
    best = float('inf')

    for i in range(1, n+1):
        best = min(best, max(partition(arr, i, k-1), sum(arr[i:n])))
    return best

n = 4
arr = [10, 20, 30, 40]
k = 2

print(partition(arr, n, k))