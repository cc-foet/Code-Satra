#include <stdio.h>
#include <stdlib.h>

void update(int BIT[], int index, int value, int len) {
    while (index <= len) {
        BIT[index] += value;
        index += index & -index;
    }
}

int query(int BIT[], int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}

int getCount(int arr[], int len) {
    int count = 0;
    int maxVal = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int *BIT = (int *)calloc(maxVal + 1, sizeof(int));
    for (int i = len - 1; i >= 0; i--) {
        count += query(BIT, arr[i] - 1);
        update(BIT, arr[i], 1, maxVal);
    }

    free(BIT);
    return count;
}

void main() {
    int arr[] = {8, 4, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", getCount(arr, len));
}
