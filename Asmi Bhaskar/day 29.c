#include <stdio.h>
#include <stdlib.h>

void update(int* BIT, int index, int value, int n) {
    for (; index <= n; index += index & -index) {
        BIT[index] += value;
    }
}

int getSum(int* BIT, int index) {
    int sum = 0;
    for (; index > 0; index -= index & -index) {
        sum += BIT[index];
    }
    return sum;
}

int countInversions(int* arr, int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    qsort(temp, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        arr[i] = (int)(lower_bound(temp, n, arr[i]) - temp) + 1;
    }

    int* BIT = (int*)calloc(n + 1, sizeof(int));
    int invCount = 0;

    for (int i = n - 1; i >= 0; i--) {
        invCount += getSum(BIT, arr[i] - 1);
        update(BIT, arr[i], 1, n);
    }

    free(temp);
    free(BIT);

    return invCount;
}

int* lower_bound(int* arr, int size, int value) {
    int* low = arr;
    int* high = arr + size;
    while (low < high) {
        int* mid = low + (high - low) / 2;
        if (*mid < value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countInversions(arr, n);
    printf("Number of inversions: %d\n", result);

    return 0;
}
