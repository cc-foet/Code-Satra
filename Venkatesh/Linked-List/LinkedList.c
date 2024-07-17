#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void removeDuplicates(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct Node* toDelete = temp->next;
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* list = NULL;

    insertion(&list, 1);
    insertion(&list, 2);
    insertion(&list, 2);
    insertion(&list, 4);
    insertion(&list, 4);
    insertion(&list, 4);
    insertion(&list, 5);

    removeDuplicates(&list);
    printList(list);
}