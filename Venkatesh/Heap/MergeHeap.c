#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int i;
    int j;
};

struct MinHeap {
    struct Node* heapArr;
    int heapSize;
};

void minHeapify(struct MinHeap* minHeap, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < minHeap->heapSize && minHeap->heapArr[l].data < minHeap->heapArr[i].data) {
        smallest = l;
    }
    if (r < minHeap->heapSize && minHeap->heapArr[r].data < minHeap->heapArr[smallest].data) {
        smallest = r;
    }
    if (smallest != i) {
        struct Node temp = minHeap->heapArr[i];
        minHeap->heapArr[i] = minHeap->heapArr[smallest];
        minHeap->heapArr[smallest] = temp;
        minHeapify(minHeap, smallest);
    }
}

void buildMinHeap(struct MinHeap *minHeap) {
    int i = (minHeap->heapSize - 1) / 2;
    while (i >= 0) {
        minHeapify(minHeap, i);
        i--;
    }
}

struct Node getRoot(struct MinHeap* minHeap) {
    struct Node root = minHeap->heapArr[0];
    return root;
}

void replaceRoot(struct MinHeap* minHeap, struct Node root) {
    minHeap->heapArr[0] = root;
    minHeapify(minHeap, 0);
}

void swap(struct Node* arr, int i, int j) {
    struct Node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void mergeSorted(int arr[][4], int k, int n) {
    struct Node heapArr[k];
    int totalSize = 0;
    for (int i = 0; i < k; i++) {
        struct Node node = {arr[i][0], i, 1};
        heapArr[i] = node;
        totalSize += n;
    }

    struct MinHeap minHeap = {heapArr, k};
    minHeap.heapSize = k;
    minHeap.heapArr = heapArr;
    buildMinHeap(&minHeap);

    int result[totalSize];
    for (int i = 0; i < totalSize; i++) {
        struct Node root = getRoot(&minHeap);
        result[i] = root.data;
        if (root.j < n) {
            root.data = arr[root.i][root.j];
            root.j += 1;
        } else {
            root.data = INT_MAX;
        }
        replaceRoot(&minHeap, root);
    }
    for (int i = 0; i < totalSize; i++) {
        printf("%d ", result[i]);
    }
}

void main () {
    int k = 3, n = 4;
    int arr[3][4] = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
    mergeSorted(arr, k, n);
}