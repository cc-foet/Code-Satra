//TODAY POTD 
#include <bits/stdc++.h>
using namespace std;

void FloydWarshall(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
for(int i=0;i<original.size();i++){
    int s=original[i]-'a';
    int t=changed[i]-'a';
    adjMatrix[s][t]=min(   adjMatrix[s][t],(long long) cost[i]);
}
    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
          adjMatrix[i][j]=min(  adjMatrix[i][j],  adjMatrix[i][k]+  adjMatrix[k][j]);

            }
        }
    }
}

 long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
    vector<vector<long,long>>adjMatrix(26,vector<long,long>(26,INT_MAX));
    FloydWarshall(adjMatrix,original,changed,cost);


long long ans=0;
for(int i=0;i<source.length();i++){
    if(source[i]==target[i]){
        continue;
    }
    if(adjMatrix[source[i]-'a'][target[i]-'a']==INT_MAX){
        return -1;
    }

ans+=adjMatrix[source[i]-'a'][target[i]-'a'];
}
return ans;
 }