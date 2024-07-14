#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    int frequency;
} HeapNode;

typedef struct {
    HeapNode* nodes;
    int size;
} MaxHeap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->nodes[left].frequency > heap->nodes[largest].frequency) {
        largest = left;
    }

    if (right < heap->size && heap->nodes[right].frequency > heap->nodes[largest].frequency) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap->nodes[largest], &heap->nodes[index]);
        maxHeapify(heap, largest);
    }
}

HeapNode extractMax(MaxHeap* heap) {
    if (heap->size == 0) {
        HeapNode empty = {'\0', 0};
        return empty;
    }

    HeapNode root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    maxHeapify(heap, 0);

    return root;
}

void insertMaxHeap(MaxHeap* heap, HeapNode node) {
    heap->size++;
    int i = heap->size - 1;

    while (i && node.frequency > heap->nodes[(i - 1) / 2].frequency) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->nodes[i] = node;
}

MaxHeap* createAndBuildMaxHeap(char* str) {
    int n = strlen(str);
    int freq[26] = {0};

    for (int i = 0; i < n; i++) {
        freq[str[i] - 'a']++;
    }

    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->nodes = (HeapNode*)malloc(sizeof(HeapNode) * 26);
    heap->size = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            heap->nodes[heap->size].character = i + 'a';
            heap->nodes[heap->size].frequency = freq[i];
            heap->size++;
        }
    }

    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        maxHeapify(heap, i);
    }

    return heap;
}

char* rearrangeString(char* str) {
    int n = strlen(str);
    MaxHeap* heap = createAndBuildMaxHeap(str);
    char* result = (char*)malloc(sizeof(char) * (n + 1));
    int index = 0;

    HeapNode prev = {'#', -1};

    while (heap->size > 0) {
        HeapNode current = extractMax(heap);
        result[index++] = current.character;

        if (prev.frequency > 0) {
            insertMaxHeap(heap, prev);
        }

        current.frequency--;
        prev = current;
    }

    result[index] = '\0';

    if (index != n) {
        free(result);
        result = "";
    }

    free(heap->nodes);
    free(heap);
    return result;
}

int main() {
    char str[] = "aaabbc";
    char* result = rearrangeString(str);

    if (strlen(result) == 0) {
        printf("Not possible to rearrange\n");
    } else {
        printf("Rearranged string: %s\n", result);
    }

    return 0;
}