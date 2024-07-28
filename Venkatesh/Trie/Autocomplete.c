#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

typedef struct {
    TrieNode* root;
} Trie;

Trie* createTrie() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void insert(Trie* trie, const char* word) {
    TrieNode* node = trie->root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
        word++;
    }
    node->isEndOfWord = true;
}

TrieNode* searchPrefix(Trie* trie, const char* prefix) {
    TrieNode* node = trie->root;
    while (*prefix) {
        int index = *prefix - 'a';
        if (!node->children[index]) {
            return NULL;
        }
        node = node->children[index];
        prefix++;
    }
    return node;
}

void autocomplete(TrieNode* node, char* prefix, char** results, int* resultSize) {
    if (node->isEndOfWord) {
        results[*resultSize] = strdup(prefix);
        (*resultSize)++;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            char nextPrefix[strlen(prefix) + 2];
            snprintf(nextPrefix, sizeof(nextPrefix), "%s%c", prefix, 'a' + i);
            autocomplete(node->children[i], nextPrefix, results, resultSize);
        }
    }
}

char** search(Trie* trie, const char* prefix, int* returnSize) {
    TrieNode* node = searchPrefix(trie, prefix);
    char** results = NULL;
    *returnSize = 0;
    if (node) {
        results = (char**)malloc(100 * sizeof(char*));
        autocomplete(node, (char*)prefix, results, returnSize);
    }
    return results;
}

void freeTrie(TrieNode* node) {
    if (node) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            freeTrie(node->children[i]);
        }
        free(node);
    }
}

void main() {
    char* words[] = {"cat", "car", "cart", "dog", "dove", "door"};
    char* prefix = "car";
    int numWords = sizeof(words) / sizeof(words[0]);

    Trie* trie = createTrie();
    for (int i = 0; i < numWords; i++) {
        insert(trie, words[i]);
    }

    int returnSize;
    char** matches = search(trie, prefix, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s ", matches[i]);
        free(matches[i]);
    }
    free(matches);
    freeTrie(trie->root);
    free(trie);
}
