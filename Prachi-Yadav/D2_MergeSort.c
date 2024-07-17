#include<stdio.h>
#include<stdlib.h>
 
void merge(int arr[],int a,int b,int c){
    int m=b-a+1;
    int n=c-b;
    int L1[m],L2[n];
    int i,j,k;

    for(i=0;i<m;i++){
        L1[i]=arr[a+i];
    }
    for(j=0;j<m;j++){
        L2[j]=arr[b+1+j];
    }
    i = 0;
    j = 0;
    k = a;
    while(i<m && j<n){
        if(L1[i]<=L2[j]){
            arr[k]=L1[i];
            i++;
        }else{
            arr[k]=L2[j];
            j++;
        }
        k++;
    } 
    while (i < m) {
    arr[k] = L1[i];
    i++;
    k++;
    }
    while (j < n) {
    arr[k] = L2[j];
    j++;
    k++;
    }
}

void mergeSort(int arr[], int a, int c){
    if (a < c) {
        int l = a + (c - a) / 2;

        mergeSort(arr, a, l);
        mergeSort(arr, l + 1, c);

        merge(arr, a,l,c);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 1,3,6,19,11,16};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
