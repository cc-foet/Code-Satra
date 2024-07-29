#include <stdio.h>
#include <stdlib.h>

int longestSubarray(int* arr, int n, int K) {
    int maxLength = 1;
    int totalIncrements = 0;
    int left = 0;
    int right = 0;

    for (right = 1; right < n; right++) {
        totalIncrements += (arr[right] - arr[right - 1]) * (right - left);
        while (totalIncrements > K) {
            totalIncrements -= arr[right] - arr[left];
            left++;
        }
        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
        }
    }

    return maxLength;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {2, 0, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 6;

    qsort(arr, n, sizeof(int), compare);

    int result = longestSubarray(arr, n, K);
    printf("The length of the longest subarray is: %d\n", result);

    return 0;
}
