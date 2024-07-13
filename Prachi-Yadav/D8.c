#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longest_subarray(int arr[], int n, int k) {
    int *map = (int *)malloc(k * sizeof(int));
    int sum = 0, max_len = 0;

    for (int i = 0; i < k; i++) map[i] = -2;
    map[0] = -1; 

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        int r = (sum % k + k) % k;

        if (map[r] != -2) {
            max_len = max(max_len, i - map[r]);
        } else {
            map[r] = i;
        }
    }

    free(map);
    return max_len;
}

int main() {
    int arr[] = {2, 7, 1, 4, 5};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longest_subarray(arr, n, k);
    printf("The length of the longest subarray is: %d\n", result);

    return 0;
}
