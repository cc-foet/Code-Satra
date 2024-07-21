#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int sum(int arr[], int from, int to) {
    int total = 0;
    for (int i = from; i <= to; i++) {
        total += arr[i];
    }
    return total;
}

int partition(int arr[], int n, int k) {
    if (k == 1) {
        return sum(arr, 0, n - 1);
    }
    if (n == 1) {
        return arr[0];
    }
    int best = 1000000;
    for (int i = 1; i < n; i++) {
        best = min(best, max(partition(arr, i, k - 1), sum(arr, i, n - 1)));
    }
    return best;
}

void main() {
    int n = 4;
    int arr[] = {10, 20, 30, 40};
    int k = 2;

    printf("%d", partition(arr, n, k));
}