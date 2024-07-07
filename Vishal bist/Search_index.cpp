// Program to search index of the given number in a rotated array.
#include<iostream>
#include<vector>
using namespace std;


int search(vector<int>& arr, int x) {
        int ans = -1,start = 0,end = arr.size()-1,mid;

        while(start<=end){
            mid = start + (end-start)/2;
            if(arr[mid] == x) return mid;
            else if(arr[mid]>=arr[0]){
                if(arr[start]<=x && arr[mid]>=x){
                    end = mid-1;
                }
                else
                    start = mid+1;

            }
            else {
                if(arr[mid]<=x && arr[end]>=x)
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return ans;
};

int main(){
    vector <int> arr = {14,16,18,0,1,6,8,10,11,13};
    int result = search(arr,11);
    (result == -1) ? cout<<"This element is not present in the given array."<<endl : cout<<result<<endl;

  return 0;
}