#include <stdio.h>
#include <stdlib.h>

int longestSubarrayDivisibleByK(int arr[], int n, int k) {
    int *remainderIndex = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        remainderIndex[i] = -1;
    }

    int maxLength = 0;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        int remainder = ((prefixSum % k) + k) % k;

        if (remainder == 0) {
            maxLength = i + 1;
        } else if (remainderIndex[remainder] != -1) {
            maxLength = (i - remainderIndex[remainder] > maxLength) ? i - remainderIndex[remainder] : maxLength;
        } else {
            remainderIndex[remainder] = i;
        }
    }

    free(remainderIndex);

    return maxLength;
}

int main() {
    int arr[] = {2, 7, 6, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = longestSubarrayDivisibleByK(arr, n, k);
    printf("Length of the longest subarray with sum divisible by %d is %d\n", k, result);

    return 0;
}
