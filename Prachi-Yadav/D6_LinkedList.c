#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    int data;
    struct linked_list* next;
};

struct linked_list* head = NULL;
struct linked_list* temp = NULL;

void NoRepeatance() {
    temp = head;
    
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct linked_list* duplicate = temp->next;
            temp->next = temp->next->next;
            free(duplicate);
        } else {
            temp = temp->next;
        }
    }
}

void printList(struct linked_list* head) {
    struct linked_list* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertNode(int d) {
    struct linked_list* newNode = (struct linked_list*)malloc(sizeof(struct linked_list));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = d;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    insertNode(1);
    insertNode(2);
    insertNode(2);
    insertNode(4);
    insertNode(4);
    insertNode(4);
    insertNode(5);

    printf("Original Linked List: ");
    printList(head);

    NoRepeatance(); 
    
    printf("Linked List after removing duplicates: ");
    printList(head);
    
    struct linked_list* current = head;
    while (current != NULL) {
        struct linked_list* next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}
