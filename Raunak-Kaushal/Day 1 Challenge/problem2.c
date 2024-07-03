/* Day 1 : Doubly linked list problem :
Write a C program to implement a doubly linked list with functions to insert at the beginning, insert at a specific position, delete at the beginning, and display the list, including a menu-driven interface for these operations
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}*head = NULL;

void insertAtBeginning(int data){
    struct Node* temp = malloc(sizeof(struct Node));
    if (temp == NULL){
        printf("Memory allocation failed :(\n");
        return;
    }
    temp->data = data;
    if(head == NULL){
        head = temp;
    } 
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void displayList(){
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtPosition(int data, int position){
    if(position < 1){
        printf("Invalid position :)\n");
        return;
    }
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed :(\n");
        return;
    }
    newNode->data = data;
    if(position == 1){
        newNode->next = head;
        if(head != NULL){
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    int currentPosition = 1;
    while(temp != NULL && currentPosition < position - 1){
        temp = temp->next;
        currentPosition++;
    }
    
    if(temp == NULL){
        printf("Invalid position :)\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

int deleteAtBeginning(){
    if(head == NULL){
        printf("List is empty!\n");
        return -1; 
    }
    
    struct Node* temp = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    int deletedData = temp->data;
    free(temp);
    return deletedData;
}

void main(){
    int choice, key, position;

    do{
        printf("Choose Operation\n");
        printf("1. Insert at Beginning\n2. Insert at Position\n3. Delete at Beginning\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insertAtBeginning(key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(key, position);
                break;
            case 3:
                printf("Deleted element: %d\n", deleteAtBeginning());
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }while(choice != 5);
}

/*

OUTPUT :
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 1
Enter key: 10
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 1
Enter key: 20
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 1
Enter key: 30
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 1
Enter key: 40
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 4
Doubly Linked List: 40 30 20 10 
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 2
Enter key: 80
Enter position: 2
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 4
Doubly Linked List: 40 80 30 20 10 
Choose Operation
1. Insert at Beginning
2. Insert at Position
3. Delete at Beginning
4. Display
5. Exit
Enter your choice: 5
Exiting

*/
