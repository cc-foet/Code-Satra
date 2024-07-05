/*Problem : To reverse a circular linked list 
create operations like insert, delete, reverse,print
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head = NULL;

void insertbeg(int);
void deletebeg();
void reverse();
void print();

int main() {
    int ch, key;
    do {
        printf("1. Insert beg\n2. Delete beg\n3. Print\n4. Reverse\n5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter Key: ");
                scanf("%d", &key);
                insertbeg(key);
                break;
            case 2:
                deletebeg();
                break;
            case 3:
                print(); 
                break;
            case 4:
                reverse();
                break;
            case 5:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 5);
    return 0;
}

void insertbeg(int key) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = key;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        struct node *ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        temp->next = head;
        head = temp;
        ptr->next = head;
    }
}

void deletebeg() {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    if (head->next == head) {
        printf("Delete node with data: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    printf("Delete node with data: %d\n", head->data);
    struct node *delNode = head;
    head = head->next;
    free(delNode);
}

void reverse() {
    if (head == NULL || head->next == head) {
        printf("Linked List Not Reversed\n");
        return;
    }
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;
    head = prev;
    printf("Linked List reversed\n");
}

void print() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("NULL\n");
}
/* output :
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 1
Enter Key: 10
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 1
Enter Key: 20
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 1
Enter Key: 30
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 3
30 -> 20 -> 10 -> NULL
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 4
Linked List reversed
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 3
10 -> 20 -> 30 -> NULL
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 2
Delete node with data: 10
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 3
20 -> 30 -> NULL
1. Insert beg
2. Delete beg
3. Print
4. Reverse
5. Exit
Enter Choice: 5
Exiting
*/