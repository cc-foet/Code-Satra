#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} ;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertion(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

struct TreeNode* newTreeRoot(int data) {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct TreeNode* sortedListToBSTHelper(struct Node** head, int n) {
    if (n <= 0) return NULL;

    struct TreeNode* left = sortedListToBSTHelper(head, n / 2);

    struct TreeNode* root = newTreeRoot((*head)->data);
    root->left = left;

    *head = (*head)->next;

    root->right = sortedListToBSTHelper(head, n - n / 2 - 1);

    return root;
}

struct TreeNode* convertToBST(struct Node* head, int n) {
    return sortedListToBSTHelper(&head, n);
}

void preorderTraversal(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[(*index)++] = root->data;
    preorderTraversal(root->left, result, index);
    preorderTraversal(root->right, result, index);
}

void main() {
    struct Node* list = NULL;

    insertion(&list, 1);
    insertion(&list, 2);
    insertion(&list, 3);
    insertion(&list, 4);
    insertion(&list, 5);
    insertion(&list, 6);
    insertion(&list, 7); 

    int size = 0;
    struct Node* temp = list;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    
    struct TreeNode* bstRoot = convertToBST(list, size);

    int preorderArray[size];
    int index = 0;
    preorderTraversal(bstRoot, preorderArray, &index);

    for (int i = 0; i < size; i++) {
        printf("%d ", preorderArray[i]);
    }
}