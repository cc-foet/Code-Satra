def sum_factor(arr, k):
    mod_map = {}
    max_len = 0
    prefix_sum = 0

    for i in range(len(arr)):
        prefix_sum += arr[i]
        mod = prefix_sum % k
        if mod == 0:
            max_len = i + 1
        if mod not in mod_map:
            mod_map[mod] = i
        else:
            max_len = max(max_len, i - mod_map[mod])

    return max_len

arr = [2, 7, 6, 1, 4, 5]
k = 3

print(sum_factor(arr, k))
