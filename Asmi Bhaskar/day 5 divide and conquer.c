#include <stdio.h>
#include <limits.h>

int findKthElement(int* arr1, int n, int* arr2, int m, int k) {
    if (n > m) {
        return findKthElement(arr2, m, arr1, n, k);
    }

    if (n == 0) {
        return arr2[k - 1];
    }

    if (k == 1) {
        return arr1[0] < arr2[0] ? arr1[0] : arr2[0];
    }

    int i = (n < k / 2) ? n : k / 2;
    int j = k - i;

    if (arr1[i - 1] < arr2[j - 1]) {
        return findKthElement(arr1 + i, n - i, arr2, m, k - i);
    } else {
        return findKthElement(arr1, n, arr2 + j, m - j, k - j);
    }
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;

    int result = findKthElement(arr1, n, arr2, m, k);
    printf("The element at the %d-th position in the merged sorted array is: %d\n", k, result);

    return 0;
}
