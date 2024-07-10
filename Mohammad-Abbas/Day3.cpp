#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>&arr,int day,int m,int k){
    int n=arr.size();
    int cnt=0;
    int noofB=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day){
            cnt++;
        }
        else {
            noofB=(cnt/k);
            cnt=0;
        }
    }
      noofB+=(cnt/k);
      return noofB>=m;

}
int bouquets(vector<int>arr,int k,int m){
    int val=m*k;
    int n=arr.size();
    if(val>n){return -1;}
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }

    int low=mini,high=maxi;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(arr,mid,m,k)){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}
int main(){
    vector<int>arr={5, 5, 5, 5, 10, 5, 5};
    int k=3,m=2;
    int ans=bouquets(arr,k,m);
    if(ans==-1){
        cout<<"We cannot make m bouquets."<<endl;
    }
     else
        cout << "We can make bouquets on day " << ans << endl;
    return 0;
}