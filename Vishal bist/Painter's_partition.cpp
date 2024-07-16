/* Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.  */

#include<iostream>
using namespace std;

int minTime(int A[], int n, int m)
    {
         int start = 0, end = 0, mid, ans;
         for(int i = 0; i<n; ++i){
             if(start < A[i])
                start = A[i];
             end+=A[i];
         }
         
         while(start<=end){
             mid = start+(end - start)/2;
             int boards = 0,count =1;
             for(int i = 0; i<n; ++i){
                 boards+=A[i];
                 if(boards>mid){
                     count++;
                     boards=A[i];
                 }
             }
             if(count<=m){
                 ans = mid;
                 end = mid-1;
             }
             else
                start = mid+1;
         }
         return ans;
};

int main(){
  int A[] = {5,10,30,20,15};
  int n = sizeof(A)/sizeof(A[0]);
  cout<<"Minimum time to get the job done: "<<minTime(A,n,3)<<endl;
}