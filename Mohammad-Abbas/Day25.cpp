#include <iostream>
#include<vector>
#include<unordered_map>
#include <list>
#include <stack>
using namespace std;
void topoSort(int node,unordered_map<int,bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour])
        topoSort(neighbour,visited,s,adj);
    }

    s.push(node);
}
vector<int>topologicalSort(vector<vector<int>>&edges,int v,int e){
unordered_map<int,list<int>>adj;
for(int i=0;i<e;i++){
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
}
stack<int>s;
unordered_map<int,bool>visited(v);
for(int i=0;i<v;i++){
    if(!visited[i]){
        topoSort(i,visited,s,adj);

    }

    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
}


int main() {
    int N = 6; // Number of vertices
    int E = 6; // Number of edges
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> result = topologicalSort(edges, N, E);

    cout << "Topological Sort: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}