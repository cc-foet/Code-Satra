// Program to check if the given number is present in a sorted array (not necessarily with distinct values).
#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& arr, int x) {
        int start = 0,end = arr.size()-1,mid;
        bool ans = false;

        while(start<=end){
            mid = start + (end - start)/2;

            if(arr[mid] == x) return true;

            else if(arr[mid]==arr[start] && arr[mid]==arr[end]){
                start++;
                end--;
            }

            else if(arr[mid] >= arr[start]){
                if(arr[start]<=x && arr[mid]>=x)
                    end = mid-1;
                else
                    start = mid+1;
            }
            else{
                if(arr[mid]<=x && arr[end]>=x)
                    start = mid+1;
                else 
                    end = mid-1;
            }
        }
        return ans;
    };

int main(){
    vector <int> arr = {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1};
    cout<<search(arr,0)<<endl;
return 0;
}