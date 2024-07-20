package Array;
import java.util.*; 

public class BellmanFord
{
    public static Map<Integer, Integer> bellmanFord(int[][] graph, int V, int src)
    {
        Map<Integer, Integer> distance = new HashMap<>();
        for (int i = 0; i < V; i++) {
            distance.put(i, Integer.MAX_VALUE);
        }
        distance.put(src, 0);

        for (int i = 0; i < V - 1; i++)
         {
            for (int j = 0; j < V; j++) 
            {
                for (int k = 0; k < V; k++) {
                    if (graph[j][k] != 0) {
                        if (distance.get(j) + graph[j][k] < distance.get(k)) {
                            distance.put(k, distance.get(j) + graph[j][k]);
                        }
                    }
                }
            }
        }

        for (int j = 0; j < V; j++) 
        {
            for (int k = 0; k < V; k++) 
            {
                if (graph[j][k] != 0) {
                    if (distance.get(j) + graph[j][k] < distance.get(k))
                     {
                        System.out.println("Graph contains negative wieght cycle");
                        return null;
                    }
                }
            }
        }

        return distance;
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
        System.out.println("Enter the source vertex");
        int src=sc.nextInt();
        Map<Integer, Integer> distance = bellmanFord(graph, V, src);
        if (distance != null) {
            System.out.println("Vertex\t Distance");
            for (Map.Entry<Integer, Integer> entry : distance.entrySet()) {
                System.out.println(entry.getKey() + "\t\t" + entry.getValue());
            }
        }
    }
}
