// In this program I have implemented a sorting array called QUICK SORT.
// This is an in-place sorting algorithm, i.e. its space complexity is O(1).
// The space complexity of this algorithm is O(nlog(n)).
// This utilises a recursive function to sort the array.
// I have used C++ to implement this program.

#include<iostream>
using namespace std;

// This function helps to put the pivot element at its right place in the sorted array.
int partition(int* arr, int low, int high){
    int i=low; 
    int j=high;
    int pivot = arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

// This function divides the array into sub-arrays which are further sorted using the partition function.
void qs(int* arr, int low, int high){
    if(low<high){
        int partitionElement = partition(arr, low, high);
        qs(arr, low, partitionElement-1);
        qs(arr, partitionElement+1, high);
    }
}

void printArr(int* arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[10] = {3,5,2,7,1,8,1,9,10,11};
    qs(arr, 0, 9);
    printArr(arr, 10);
}

//The output is " 1 1 2 3 5 7 8 9 10 11 "