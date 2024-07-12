//You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
//Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.
// return -1 if a valid allocation is not possible.

#include<iostream>
#include<vector>
using namespace std;

int findPages(int n, vector <int>& arr, int m) {
         if(m>n)    return -1;
         int start = 0, end = 0, mid, ans;
         for(int i = 0; i<n; ++i){
             start = max(start,arr[i]);
             end+=arr[i];
         }
         
         while(start<=end){
             mid = start+(end - start)/2;
             int pages = 0,count =1;
             for(int i = 0; i<n; ++i){
                 pages+=arr[i];
                 if(pages>mid){
                     count++;
                     pages=arr[i];
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
  vector <int> arr = {12,34,67,90};
  int students = 2;
  int no_of_books = arr.size();
  cout<<"Minimum no. of pages that can be distributed: "<<findPages(no_of_books,arr,students)<<endl;
}