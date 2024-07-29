def build_tree(arr, start, end, node):
    if start == end:
        segment_tree[node] = arr[start]
    else:
        mid = (start + end) // 2
        segment_tree[node] = max(build_tree(arr, start, mid, 2 * node + 1), build_tree(arr, mid + 1, end, 2 * node + 2))
    
    return segment_tree[node]

def query(start, end, l, r, node):
    if start > r or end < l:
        return -1
    
    if start >= l and end <= r:
        return segment_tree[node]
    
    mid = (start + end) // 2

    return max(query(start, mid, l, r, 2 * node + 1), query(mid + 1, end, l, r, 2 * node + 2))

def longest_subarray(arr, len, k):
    res = 1
    prefix = [0] * (len + 1)

    prefix[0] = arr[0]
    for i in range(1, len):
        prefix[i] = prefix[i - 1] + arr[i]
    build_tree(arr, 0, len - 1, 0)

    for i in range(len):
        start = i
        end = len - 1
        max_index = i

        while start <= end:
            mid = (start + end) // 2
            max_num = query(0, len - 1, i, mid, 0)

            sum_expected = (mid - i + 1) * max_num
            sum_actual = prefix[mid] - prefix[i] + arr[i]

            if sum_actual + k >= sum_expected:
                max_index = mid
                start = mid + 1
            else:
                end = mid - 1
        res = max(res, max_index - i + 1)
    return res

arr = [2, 0, 4, 6, 7]
k = 6

segment_tree = [0] * (2 * len(arr) - 1)

print(longest_subarray(arr, len(arr), k))