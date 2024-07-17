#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HuffmanNode {
    char char_data;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct MinHeap {
    int size;
    int capacity;
    HuffmanNode **array;
} MinHeap;

HuffmanNode *newNode(char char_data, int freq) {
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->char_data = char_data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap *createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HuffmanNode **)malloc(minHeap->capacity * sizeof(HuffmanNode *));
    return minHeap;
}

void swapMinHeapNode(HuffmanNode **a, HuffmanNode **b) {
    HuffmanNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}

HuffmanNode *extractMin(MinHeap *minHeap) {
    HuffmanNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap *minHeap, HuffmanNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(HuffmanNode *root) {
    return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

HuffmanNode *buildHuffmanTree(char data[], int freq[], int size) {
    HuffmanNode *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(HuffmanNode *root, int arr[], int top, char **codebook) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, codebook);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, codebook);
    }
    if (isLeaf(root)) {
        codebook[(unsigned char)root->char_data] = (char *)malloc(top + 1);
        for (int i = 0; i < top; ++i) {
            codebook[(unsigned char)root->char_data][i] = '0' + arr[i];
        }
        codebook[(unsigned char)root->char_data][top] = '\0';
    }
}

char *huffmanEncode(char *str, char **codebook) {
    char *encoded = (char *)malloc(strlen(str) * 256);
    encoded[0] = '\0';
    for (int i = 0; str[i] != '\0'; ++i) {
        strcat(encoded, codebook[(unsigned char)str[i]]);
    }
    return encoded;
}

char *huffmanDecode(char *str, HuffmanNode *root) {
    HuffmanNode *node = root;
    char *decoded = (char *)malloc(strlen(str));
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        node = str[i] == '0' ? node->left : node->right;
        if (isLeaf(node)) {
            decoded[j++] = node->char_data;
            node = root;
        }
    }
    decoded[j] = '\0';
    return decoded;
}

int main() {
    char str[] = "hello world";
    int freq[256] = {0};
    int size = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (freq[(unsigned char)str[i]] == 0)
            ++size;
        ++freq[(unsigned char)str[i]];
    }
    char data[size];
    int frequencies[size];
    int index = 0;
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            data[index] = i;
            frequencies[index] = freq[i];
            ++index;
        }
    }

    HuffmanNode *root = buildHuffmanTree(data, frequencies, size);

    char *codebook[256] = {0};
    int arr[100], top = 0;
    printCodes(root, arr, top, codebook);

    char *encoded_data = huffmanEncode(str, codebook);
    printf("Encoded: %s\n", encoded_data);

    char *decoded_data = huffmanDecode(encoded_data, root);
    printf("Decoded: %s\n", decoded_data);

    for (int i = 0; i < 256; ++i) {
        if (codebook[i])
            free(codebook[i]);
    }
    free(encoded_data);
    free(decoded_data);

    return 0;
}