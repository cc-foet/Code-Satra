#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode* createListNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insert(struct ListNode** headRef, int val) {
    struct ListNode* newNode = createListNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct ListNode* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct ListNode* findMiddle(struct ListNode* start, struct ListNode* end) {
    struct ListNode* slow = start;
    struct ListNode* fast = start;
    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* start, struct ListNode* end) {
    if (start == end) {
        return NULL;
    }
    struct ListNode* mid = findMiddle(start, end);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = sortedListToBST(start, mid);
    root->right = sortedListToBST(mid->next, end);
    return root;
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    struct ListNode* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);

    struct TreeNode* root = sortedListToBST(head, NULL);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
