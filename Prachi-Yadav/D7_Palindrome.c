#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX];
char queue[MAX];
int top = -1;
int front = 0, rear = -1;


int isPalindrome(char *str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            char ch = tolower(str[i]);
            stack[++top] = ch;
            queue[++rear] = ch;
        }
    }

    while (top >= 0) {
        if (stack[top--] != queue[front++]) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    char str[] = "CodeSatra";

    printf("%s\n", isPalindrome(str) ? "true" : "false");

    return 0;
}
