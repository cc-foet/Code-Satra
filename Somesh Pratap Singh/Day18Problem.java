package Array;
import java.util.*;
public class Flyod_Warshall

 {
    private static final int INF = 99999;

    public static void floydWarshall(int[][] graph) 
    {
        int V = graph.length;

        int[][] dist = new int[V][V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) 
            {
                dist[i][j] = graph[i][j];
            }
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                     {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

       
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                if (dist[i][j] == INF) {
                    System.out.print("INF ");
                } else {
                    System.out.print(dist[i][j] + " ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of vertices");
        int V=sc.nextInt();
        System.out.println("Enter the adjacency matrix");
        int graph[][]=new int[V][V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                graph[i][j]=sc.nextInt();
            }
        }
        floydWarshall(graph);


        
    }
}
