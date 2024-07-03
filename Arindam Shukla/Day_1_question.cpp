#include <iostream>
using namespace std;

int count_bubble_sort(int arr[],int size)
{
    int i, j,count=0; 
    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]); 
                count++;
            }
        }
    }
    return count;
}

void printArray(int arr[], int size) 
{ 
    int i; 
    cout<<"[";
    for (i = 0; i < size; i++) 
    {
        
        cout << arr[i] ;
        if (i==size-1)
        {
            break;
        } 
        cout<<", ";
    }
    
    cout <<"]"<< endl; 
} 
  
int main()
{
    int arr [7]={64,34,25,12,22,11,90};
    cout<<"Sorted array: " ;
    int swaps=count_bubble_sort(arr,7);
    printArray(arr,7);
    cout<<"Number of Swaps: "<< swaps;
}