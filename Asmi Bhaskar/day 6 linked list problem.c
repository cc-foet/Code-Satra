#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* removeDuplicates(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->val == cur->next->val) {
            struct Node* temp = cur->next->next;
            free(cur->next);
            cur->next = temp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);

    head = removeDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}
