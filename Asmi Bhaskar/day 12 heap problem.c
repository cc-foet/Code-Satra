#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} MinHeapNode;

void swap(MinHeapNode* x, MinHeapNode* y) {
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(MinHeapNode heapArray[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heapArray[left].value < heapArray[smallest].value) {
        smallest = left;
    }

    if (right < size && heapArray[right].value < heapArray[smallest].value) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heapArray[smallest], &heapArray[i]);
        minHeapify(heapArray, size, smallest);
    }
}

MinHeapNode extractMin(MinHeapNode heapArray[], int* size) {
    if (*size <= 0) {
        MinHeapNode emptyNode = {INT_MAX, -1, -1};
        return emptyNode;
    }

    MinHeapNode root = heapArray[0];

    if (*size > 1) {
        heapArray[0] = heapArray[*size - 1];
        minHeapify(heapArray, *size, 0);
    }

    (*size)--;
    return root;
}

void insertMinHeap(MinHeapNode heapArray[], int* size, MinHeapNode node) {
    (*size)++;
    int i = *size - 1;
    heapArray[i] = node;

    while (i != 0 && heapArray[(i - 1) / 2].value > heapArray[i].value) {
        swap(&heapArray[i], &heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void mergeKSortedArrays(int arr[][4], int k, int n) {
    int* output = (int*)malloc(sizeof(int) * k * n);
    MinHeapNode* heapArray = (MinHeapNode*)malloc(sizeof(MinHeapNode) * k);

    int heapSize = k;
    for (int i = 0; i < k; i++) {
        heapArray[i].value = arr[i][0];
        heapArray[i].arrayIndex = i;
        heapArray[i].elementIndex = 0;
    }

    for (int i = (heapSize - 1) / 2; i >= 0; i--) {
        minHeapify(heapArray, heapSize, i);
    }

    int count = 0;
    while (count < k * n) {
        MinHeapNode root = extractMin(heapArray, &heapSize);

        output[count++] = root.value;

        if (root.elementIndex + 1 < n) {
            root.value = arr[root.arrayIndex][root.elementIndex + 1];
            root.elementIndex += 1;
        } else {
            root.value = INT_MAX;
        }

        insertMinHeap(heapArray, &heapSize, root);
    }

    for (int i = 0; i < k * n; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(output);
    free(heapArray);
}

int main() {
    int k = 3, n = 4;
    int arr[3][4] = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    mergeKSortedArrays(arr, k, n);

    return 0;
}
