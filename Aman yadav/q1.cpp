#include <iostream>
#include <algorithm>
using namespace std;


void Sort(int arr[], int n, int &count){
    bool swapped;
    for(int i= 0; i< n-1; i++){
        swapped= 0;
        for(int j= 0; j< n-i-1; j++){
            if(arr[j]> arr[j+1]){
                
                swap(arr[j],arr[j+1]);
                swapped= 1;
                count++;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    int arr[]= {64,34,25,12,22,11,90};
    int n= sizeof(arr)/sizeof(arr[0]);
    int count= 0;
    
    Sort(arr, n, count);

    cout<<"Sorted array: ";
    for (int i= 0; i< n; i++) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
    cout<< "Number of swaps: "<< count<< endl;

    return 0;
}
