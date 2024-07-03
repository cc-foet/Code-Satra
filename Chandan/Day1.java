import java.util.*;
import java.io.*;

class Day1 {

    List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {

     
        boolean vis[]=new boolean[V];
        
        boolean[] path=new boolean [V];
        List<Integer> ans=new ArrayList<>();
        
        for(int i=0; i<V;i++){
            
            
            if(!dfs(adj,i,vis,path)) ans.add(i);
        }
        
        
        return ans;
        
    }    
    
    public boolean dfs(List<List<Integer>> adj,int node, boolean vis[],boolean[] path){
        
        
        if(path[node]){
            
            
            return true;
        }
        
        if(vis[node]){
            
            return false;
        }
        
        
        path[node]=true;
        vis[node]=true;
        
        
        
        for(int i: adj.get(node)){
            
          
                
                if(dfs(adj,i,vis,path)) return true;
            
            
            
        }
        
        path[node]=false;
        
        
        return false;
        
        
    }



    public static void main(String[] args) {
        int V = 6;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Defining the adjacency list for the test case
        adj.get(0).add(1);
        adj.get(0).add(2);
        adj.get(1).add(2);
        adj.get(1).add(3);
        adj.get(3).add(0);
        adj.get(4).add(5);
        adj.get(2).add(5);

        Day1 obj = new Day1();
        List<Integer> result = obj.eventualSafeNodes(V, adj);

        System.out.println("Eventual Safe Nodes are:");
        for (int node : result) {
            System.out.print(node + " ");
        }
    }
}