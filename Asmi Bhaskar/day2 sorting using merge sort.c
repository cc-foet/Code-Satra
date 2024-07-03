#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftarr[n1], rightarr[n2];

    for (int i = 0; i < n1; i++)
        leftarr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightarr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeSortedSubarrays(int arr[], int n, int m) {
    int left = n;
    int right = n + m - 1;
    int mid = left - 1;

    merge(arr, 0, mid, right);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {1, 3, 6, 19, 11, 16};
    int n = 3;
    int m = 3;
    int arrayLength = n + m;

    mergeSort(array, n, arrayLength - 1);
    mergeSortedSubarrays(array, n, m);

    printf("Sorted array: \n");
    printArray(array, arrayLength);

    return 0;
}
