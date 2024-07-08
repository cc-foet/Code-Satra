#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack {
    char *arr;
    int top;
    int size;
} Stack;

typedef struct Queue {
    char *arr;
    int front;
    int rear;
    int size;
} Queue;

Stack *createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (char *)malloc(size * sizeof(char));
    return stack;
}

bool isEmptys(Stack *stack) {
    return stack->size == 0;
}

void push(Stack *stack, char data) {
    stack->arr[++stack->top] = data;
}

char pop(Stack *stack) {
    if (isEmptys(stack)) {
        return '\0';
    }
    return stack->arr[stack->top--];
}

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (char *)malloc(size * sizeof(char));
    return queue;
}

bool isEmptyq(Queue *queue) {
    return queue->size == -0;
}

void enqueue(Queue *queue, char data) {
    queue->arr[++queue->rear] = data;
}

char dequeue(Queue *queue) {
    if (isEmptyq(queue)) {
        return '\0';
    }
    return queue->arr[++queue->front];
}

bool isPalindrome(char *str) {
    int n = strlen(str);
    Stack *stack = createStack(n);
    Queue *queue = createQueue(n);

    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
        enqueue(queue, str[i]);
    }

    for (int i = 0; i < n; i++) {
        if (pop(stack) != dequeue(queue)) {
            return false;
        }
    }

    return true;
}

void main() {
    char str[] = "CodeSatra";
    printf("%s", isPalindrome(str) ? "true" : "false");
}