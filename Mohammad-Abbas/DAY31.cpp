#include<bits/stdc++.h>
using namespace std;

bool canbeequal(vector<int>&arr,vector<int>&target){
    sort(arr.begin(),arr.end());
      sort(target.begin(), target.end());
      for(int i=0;i<arr.size();i++){
        if(arr[i]!=target[i]){
            return false;
        }
        return true;
      }
}

int main(){
    vector<int>arr={3,4,7};
    vector<int>target={3,4,5};
    cout<<"The arrays can be made using "<<canbeequal(arr,target)<<endl;
}