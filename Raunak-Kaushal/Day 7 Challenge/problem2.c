/*
Problem :
To check the word is palindrome or not.
*/
#include <stdio.h>
#include <string.h>

void isPalindrome(char str[]){
    int n = strlen(str);
    
    char reverse[n + 1];
    int palindrome = 1;
    
    for(int i = 0; i < n; i++){
        reverse[i] = str[n - i - 1];
    }
    
    reverse[n] = '\0';

    for(int i = 0; i < n; i++){
        if(str[i] != reverse[i]){
            palindrome = 0;
            break;
        }
    }

    if(palindrome){
        printf("The word is a palindrome.\n");
    }
    else{
        printf("The word is not a palindrome.\n");
    }
}

void main() {
    char str[10];
    printf("Enter a word: ");
    scanf("%s", str);
    
    isPalindrome(str);
}

/*
Output : 
Enter a word: RAUNAK
The word is not a palindrome.
*/
