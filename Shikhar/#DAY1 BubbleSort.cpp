#include<iostream>
using namespace std;

int bubbleSort(int* arr, int n){
    int swapCount = 0;
    for(int i=0; i < n-1; i++){
        bool swapped = false;
        for(int j=0; j< n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swapped = true;
                swapCount++;
                swap(arr[j], arr[j+1]);
            }
        }
        if(swapped == false){
            break;
        }
    }
    return swapCount;
}

void printArray(int* arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    cout<<"Array before sorting ";
    printArray(arr, 7);
    int swaps = bubbleSort(arr, 7);
    cout<<"Array after sorting";
    printArray(arr, 7);
    cout<<"Number of swaps "<<swaps<<endl;
}