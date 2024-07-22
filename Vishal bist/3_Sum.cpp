#include<iostream>
using namespace std;

bool findTriplet(int arr[], int n, int x) {
        int start,end,ans;
        for(int i = n-2; i>=0; --i){
            for(int j = 0; j<=i; ++j){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        for(int i = 0; i<n-2; ++i){
            ans = x-arr[i];
            start = i+1;
            end = n-1;
            while(start<end){
                if(arr[start]+arr[end] == ans)  return 1;
                else if(arr[start] + arr[end] > ans)    end--;
                else start++;
            }
        }
        return 0;
};

int main(){
  int arr[] = {40,20,10,3,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  int x = 24;
  cout<<"Is there any possible triplet: "<<findTriplet(arr,n,x)<<endl;
}