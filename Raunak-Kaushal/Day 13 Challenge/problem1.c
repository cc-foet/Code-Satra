/*
Problem : Tower of Honoi 
*/

#include<stdio.h>

void TOH(int n, char src, char dest, char aux){
    if(n == 1){
        printf("%c --> %c\n",src,dest);
        return;
    }
    else{
        TOH(n-1,src,aux,dest);
        printf("%c --> %c\n",src,dest);
        TOH(n-1,aux,dest,src);
    }
}

void main(){
    int n;
    printf("Enter no of disk : ");
    scanf("%d",&n);
    TOH(n,'A','C','B');
}

/*
Output : 
Enter no of disk : 3
A --> C
A --> B
C --> B
A --> C
B --> A
B --> C
A --> C
*/