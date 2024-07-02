#include <stdio.h>

int bubbleSort(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

void main() {
    int arr[10] = {17, 38, 47, 21, 66, 98, 5, 82, 79, 20};
    int count = bubbleSort(arr, 10);
    
    printf("Sorted array: [");
    for (int i = 0; i < 10 - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[9]);
    printf("Number of swaps: %d\n", count);
}