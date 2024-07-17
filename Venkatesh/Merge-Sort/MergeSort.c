#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int mid, int r) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

void mergeSorted(int arr[], int n, int m){
    mergeSort(arr, n, n + m - 1);
    merge(arr, 0, n - 1, n + m - 1);
}

void main() {
    int arr[] = {5, 6, 7, 12, 11, 15, 13};
    int n = 3;
    int m = 4;

    int len = n + m;

    mergeSorted(arr, n, m);

    for (int i = 0; i < len; i++)
        printf("%d, ", arr[i]);
}