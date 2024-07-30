def update(BIT, index, value, len):
    while index <= len:
        BIT[index] += value
        index += index & -index

def query(BIT, index):
    sum = 0
    while index > 0:
        sum += BIT[index]
        index -= index & -index
    return sum

def get_count(arr, len):
    count = 0
    max_val = max(arr)

    BIT = [0] * (max_val + 1)
    for i in range(len - 1, -1, -1):
        count += query(BIT, arr[i] - 1)
        update(BIT, arr[i], 1, max_val)
    
    return count

arr = [8, 4, 2, 1]

print(get_count(arr, len(arr)))