/*
Problem Statement: Given an array that represents Inorder Traversal, find the number of possible Binary Trees.

Input: arr=[4, 5, 7]

Output: 5
*/

#include <stdio.h>

int factorial(int n){
    int prod = 1;
    for(int i = 1; i <= n; i++){
        prod *= i;
    }
    return prod;
}

int catalan(int n){
    return factorial(2 * n) / (factorial(n + 1) * factorial(n));
}

int main(){
    int arr[] = {4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", catalan(n));
    return 0;
}

/*
Output : 5

The overall time complexity of this code, including the factorial and catalan functions, is 𝑂(n) where n is the number of elements in the array arr.
*/
