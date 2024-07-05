#include<stdio.h>

void swap(int *a,int *b){
    int c = *a;
    *a=*b;
    *b=c;
}
int BubbleSort(int nums[],int numsSize){
    int i,j,flag,swaps=0;
 for(i=0;i<numsSize;i++){

    for(j=0;j<numsSize-1;j++){
        flag=0;
        if(nums[j]>nums[j+1]){
        swap(&nums[j],&nums[j+1]);
        flag=1;
        swaps++;
        }
    }
    if(flag==0){
        break;
    }
 }
 return swaps; 
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
int main(){
    int arr[]={64,34,25,12,22,11,90};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int arrSwaps = BubbleSort(arr,arrSize);
    printf("Sorted Array :");
    printArray(arr,arrSize);
    printf("\nNumber of swaps: %d",arrSwaps);

    return 0;
}