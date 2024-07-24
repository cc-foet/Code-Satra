#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&coins,int target){int n=coins.size();
if(target==0) return 0;
if(target<0) return -1;
int mini=INT_MAX;
for(int i=0;i<n;i++){
int coin=coins[i];
if(coin<=target){
    int recans=solve(coins,target-coin);
    if(recans!=INT_MAX){
        int ans=1+recans;
        mini=min(ans,mini);
    }
}
}
return mini;
}
int main(){int n=4;
   vector<int>coins={9,6,5,1};
    int target=11;

    int ans=solve(coins,target);
    cout<<ans;


}