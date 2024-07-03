#include <bits/stdc++.h>
using namespace std;
void bubblesort(int arr[],int n){int cnt=0;
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
       if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
        cnt++;
       }
} 
}cout<<"Total Swaps after which sorted array is form :"<< cnt <<endl;
}
int main(){
   int arr[7]={64,34,25,12,22,11,90};
    int n=7;
   
    cout<<"Before Sorting the Array : ";
    for(int i=0;i<n;i++){
cout<<arr[i] <<" ";
}
cout<<endl;
    bubblesort(arr,n);
cout<<"After Sorting the Array : ";
for(int i=0;i<n;i++){
cout<<arr[i] <<" ";
}
}