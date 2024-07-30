#include<bits/stdc++.h>
using namespace std;

    int numTeams(vector<int>& rating) {int n=rating.size();
        int team=0;
        for(int j=1;j<n-1;j++){
            int countsmallleft=0,countsmallright=0;
            int countlargeleft=0,countlargeright=0;
for(int i=0;i<j;i++){
    if(rating[i]<rating[j])
countsmallleft++;
else if(rating[i]>rating[j])countlargeleft++;
}
for(int k=j+1;k<n;k++){
   if(rating[j] < rating[k]) countlargeright++;
else    if(rating[j] >rating[k])countsmallright++;
}
        
        team+=countsmallleft*countlargeright;
        team+=countlargeleft*countsmallright;
    }return team;
    }


int main(){
    vector<int> rating={2,5,3,4,1};
    cout<<"Total Teams made are "<<numTeams(rating);
}