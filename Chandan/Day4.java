//problem: Shortest Path in weighted Graph 


import java.util.*;

public class Day4 {


    public static int[] shortestPath(int N,int M, int[][] edges) {
		//Code here
		
		int dist[]=new int[N];
		
		Arrays.fill(dist,Integer.MAX_VALUE);
		 List<List<int []>> ls=new ArrayList<>();
		 for(int i=0; i<N;i++){
           ls.add(new ArrayList<int[] >()); 
        }
        
        for(int i=0; i<M;i++){
                ls.get(edges[i][0]).add(new int []{edges[i][1],edges[i][2]});
                
                
        }
        
		Queue<int[]> q=new LinkedList<>();
		
		
		q.add(new int[]{0,0});
		
		dist[0]=0;
		
		while(!q.isEmpty()){
		    
		    int node=q.peek()[0];
		    int w=q.peek()[1];
		    q.poll();
		    
		    for(int[] i:ls.get(node)){
		        
		        if(dist[i[0]]>w+i[1]){
		            
		            dist[i[0]]=w+i[1];
		            q.add(new int[]{i[0],w+i[1]});
		            
		        }
		        
		        
		    }
		    
		}
		
		  for(int i=0;i<N;i++){
            
            if(dist[i]==Integer.MAX_VALUE) dist[i]=-1;
        }
        
		
		return dist;
	}
    public static void main(String[] args) {
        int N = 4;
        int M = 2;
        int[][] edges = {{0, 1, 2}, {0, 2, 1}};
        
        
        int[] shortestPath = shortestPath(N, M, edges);
        
        for (int i = 0; i < N; i++) {
            System.out.print(shortestPath[i] + " ");
        }
    }
}


