#include <stdio.h>

int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1;
    int currentLength = 0;

    for (int i = 0; i < n; ++i) {
        if (currentLength + arr[i] > mid) {
            painters++;
            currentLength = arr[i];
        } else {
            currentLength += arr[i];
        }
    }

    return (painters <= k);
}

int minTimeToPaint(int arr[], int n, int k) {
    int low = 0, high = 0;
    for (int i = 0; i < n; ++i) {
        high += arr[i];
        low = (arr[i] > low) ? arr[i] : low;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, k, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int result = minTimeToPaint(arr, n, k);
    printf("Minimum time to paint all boards: %d\n", result);

    return 0;
}
