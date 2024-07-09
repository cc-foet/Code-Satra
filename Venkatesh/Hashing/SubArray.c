#include <stdio.h>
#include <stdlib.h>

struct Hash {
    int key;
    int value;
};

struct HashTable {
    struct Hash **arr;
    int capacity;
};

struct HashTable* createHashTable(int capacity) {
    struct HashTable *hashTable = (struct HashTable*) malloc(sizeof(struct HashTable));
    hashTable->capacity = capacity;
    hashTable->arr = (struct Hash**) malloc(capacity * sizeof(struct Hash*));
    for (int i = 0; i < capacity; i++) {
        hashTable->arr[i] = NULL;
    }
    return hashTable;
}

int hash(struct HashTable *hashTable, int key) {
    if (key < 0) key = -key;
    return key % hashTable->capacity;
}

void insert(struct HashTable *hashTable, int key, int value) {
    int index = hash(hashTable, key);
    struct Hash *entry = (struct Hash*) malloc(sizeof(struct Hash));
    entry->key = key;
    entry->value = value;
    while (hashTable->arr[index] != NULL && hashTable->arr[index]->key != key) {
        index = hash(hashTable, index + 1);
    }
    hashTable->arr[index] = entry;
}

int search(struct HashTable *hashTable, int key, int *found) {
    int index = hash(hashTable, key);
    while (hashTable->arr[index] != NULL) {
        if (hashTable->arr[index]->key == key) {
            *found = 1;
            return hashTable->arr[index]->value;
        }
        index = hash(hashTable, index + 1);
    }
    *found = 0;
    return -1;
}

int longestSubarray(int *arr, int len, int k) {
    struct HashTable *map = createHashTable(len);
    int *modArr = (int *)malloc(len * sizeof(int));
    int maxLen = 0, currSum = 0;
    int found = 0, temp;

    for (int i = 0; i < len; i++) {
        currSum += arr[i];
        modArr[i] = currSum % k;

        if (modArr[i] == 0) {
            maxLen = i + 1;
        } else {
            temp = search(map, modArr[i], &found);
            if (!found) {
                insert(map, modArr[i], i);
            } else {
                if (maxLen < i - temp) {
                    maxLen = i - temp;
                }
            }
        }
    }
    free(modArr);
    return maxLen;
}

void main() {
    int arr[] = {2, 7, 6, 1, 4, 5};
    int k = 3;

    int len = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", longestSubarray(arr, len, k));
}