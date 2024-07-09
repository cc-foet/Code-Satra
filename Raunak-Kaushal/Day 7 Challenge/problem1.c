/*
Problem : if a given string is a palindrome reads the same forwards and backwards. Use both a stack and a queue to check for palindromes.

Input: CodeSatra

Output: False
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10

void push(char);
char pop();
void enqueue(char);
char dequeue();
bool isPalindrome(char[]);

char stack[SIZE];
int top = -1;

char queue[SIZE];
int front = -1, rear = -1;

int main(){
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    if(isPalindrome(str)) printf("True\n");
    else printf("False\n");
    
    return 0;
}

void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top += 1;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

void enqueue(char c) {
    if (rear == SIZE - 1){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) {
        front = 0;
    }
    rear += 1;
    queue[rear] = c;
}

char dequeue(){
    if (front == -1) {
        printf("Queue Underflow\n");
        return '\0';
    }
    char c = queue[front++];
    if(front > rear){
        front = rear = -1;
    }
    return c;
}

bool isPalindrome(char str[]){
    int len = strlen(str);
    
    for(int i = 0; i < len; i++){
        char c = str[i];
        push(c);
        enqueue(c);
    }
    
    while(top != -1 && front != -1){
        char stackChar = pop();
        char queueChar = dequeue();
        if(stackChar != queueChar){
            return false;
        }
    }
    return true;
}

/*
Output : 
Enter a string: CodeSatra
False
*/

