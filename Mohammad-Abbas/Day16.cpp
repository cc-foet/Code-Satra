#include <bits/stdc++.h>
using namespace std;
vector<int>shortestpath(vector<vector<int>>&edges,int N,int M,int src){
vector<int>adj[N];
for(auto i:edges){
    adj[i[0]].push_back(i[1]);
    adj[i[1]].push_back(i[0]);

}

int dis[N];
for(int i=0;i<N;i++){ dis[i] = 1e9;
    dis[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dis[node]+1<dis[it]){
                dis[it]=1+dis[node];
                q.push(it);
            }
        }
    }
     vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dis[i] != 1e9) {
                ans[i] = dis[i]; 
            }
        }
        return ans; 
    }
}

int main(){int N=9,M=10;
    vector<vector<int>>edges={{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
   
    vector<int>ans=shortestpath(edges,N,M,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}