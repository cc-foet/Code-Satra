/*Day 6 : Leetcode Problem remove dublicates from sorted linked list.
Problem Statement: Given a sorted linked list, write a function that removes all duplicates such that each element only appears once.
Input: Linked List: 1 -> 2 -> 2 -> 4 -> 4 -> 4 -> 5
Output: 1 -> 2 -> 4 -> 5
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
}*head = NULL;

struct node* createNode(int key){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void removeDuplicates() {
    struct node* temp = head;
    if (head == NULL) {
        return;
    }
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == temp->data) {
            struct node* next_next = temp->next->next;
            free(temp->next);
            temp->next = next_next;
        } else {
            temp = temp->next;
        }
    }
}

void printList() {
    struct node* ptr = head;
    if (ptr == NULL) {
        printf("Linked list empty\n");
        return;
    }
    
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList();

    removeDuplicates();

    printf("List after removing duplicates:\n");
    printList();

    return 0;
}
/*
Output : 
Original list:
1 -> 2 -> 2 -> 4 -> 4 -> 4 -> 5 -> NULL
List after removing duplicates:
1 -> 2 -> 4 -> 5 -> NULL
*/