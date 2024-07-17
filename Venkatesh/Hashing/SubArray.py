def longest_subarray(arr, k):
    map = {}

    mod_arr = [0 for i in range(len(arr))]
    max_len = 0
    curr_sum = 0

    for i in range(len(arr)):
        curr_sum += arr[i]

        mod_arr[i] = curr_sum % k

        if mod_arr[i] == 0:
            max_len = i + 1
        elif mod_arr[i] not in map:
            map[mod_arr[i]] = i
        else:
            if max_len < i - map[mod_arr[i]]:
                max_len = i - map[mod_arr[i]]

    return max_len

arr = [2, 7, 6, 1, 4, 5]
k = 3

print(longest_subarray(arr, k))