#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef struct QueueNode {
    char data;
    struct QueueNode* next;
} QueueNode;

void push(StackNode** top, char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(StackNode** top) {
    if (*top == NULL) {
        return '\0';
    }
    StackNode* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

void enqueue(QueueNode** front, QueueNode** rear, char data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

char dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL) {
        return '\0';
    }
    QueueNode* temp = *front;
    char dequeued = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return dequeued;
}

bool isPalindrome(char* word) {
    StackNode* stack = NULL;
    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        push(&stack, word[i]);
        enqueue(&front, &rear, word[i]);
    }
    
    for (int i = 0; i < len; i++) {
        if (pop(&stack) != dequeue(&front, &rear)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char word[] = "codeSatra";
    if (isPalindrome(word)) {
        printf("%s is a palindrome\n", word);
    } else {
        printf("%s is not a palindrome\n", word);
    }
    return 0;
}
