def longest_subarray_divisible_by_k(arr, k):
    remainder_index = {}
    max_length = 0
    prefix_sum = 0

    for i in range(len(arr)):
        prefix_sum += arr[i]
        remainder = (prefix_sum % k + k) % k

        if remainder == 0:
            max_length = i + 1
        elif remainder in remainder_index:
            max_length = max(max_length, i - remainder_index[remainder])
        else:
            remainder_index[remainder] = i

    return max_length

def main():
    arr = [2, 7, 6, 1, 4, 5]
    k = 3
    result = longest_subarray_divisible_by_k(arr, k)
    print(f"Length of the longest subarray with sum divisible by {k} is {result}")

if __name__ == "__main__":
    main()
