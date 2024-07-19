package Array;

public class Dijkstra_algo 
{

    private static final int V = 8;

    int minDistance(int dist[], Boolean sptSet[]) 
    {
        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[v] <= min)
             {
                min = dist[v];
                min_index = v;
            }

        return min_index;
    }

    void printPath(int parent[], int j) 
    {
        if (parent[j] == -1)
            return;

        printPath(parent, parent[j]);

        System.out.print(j + " ");
    }


    void printSolution(int dist[], int n, int parent[])
     {
        int src = 0;
        System.out.println("Vertex\t Distance\tPath");
        for (int i = 1; i < V; i++) {
            System.out.print("\n" + src + " -> " + i + " \t\t " + dist[i] + "\t\t" + src + " ");
            printPath(parent, i);
        }
    }

    void dijkstra(int graph[][], int src)
     {
        int dist[] = new int[V];

        Boolean sptSet[] = new Boolean[V];

        int parent[] = new int[V];

        for (int i = 0; i < V; i++) 
        {
            parent[src] = -1;
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++)
         {
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
        }

        printSolution(dist, V, parent);
    }


    public static void main(String[] args) 
    {
        
        int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 } };
        Dijkstra_algo t = new Dijkstra_algo();
        t.dijkstra(graph, 0);
    }
    
}
