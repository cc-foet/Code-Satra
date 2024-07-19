public class Day18 {
    final static int INF = 99999;  // A value to represent infinity

    // A utility function to print the solution
    void printSolution(int[][] dist, int V) {
        System.out.println("Shortest distances between every pair of vertices:");
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + "   ");
            }
            System.out.println();
        }
    }

    // The main function that finds the shortest distances using Floyd-Warshall algorithm
    void floydWarshall(int[][] graph, int V) {
        int[][] dist = new int[V][V];

        // Initialize the solution matrix same as input graph matrix
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        // Add all vertices one by one to the set of intermediate vertices.
        for (int k = 0; k < V; k++) {
            // Pick all vertices as source one by one
            for (int i = 0; i < V; i++) {
                // Pick all vertices as destination for the above picked source
                for (int j = 0; j < V; j++) {
                    // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        // Print the shortest distance matrix
        printSolution(dist, V);
    }

    public static void main(String[] args) {
        int V = 5; // Number of vertices in the graph
        int[][] graph = {
                {0, 4, INF, 5, INF},
                {INF, 0, 1, INF, 6},
                {2, INF, 0, 3, INF},
                {INF, INF, 1, 0, 2},
                {1, INF, INF, 4, 0}
        };

        Day18 a = new Day18();
        a.floydWarshall(graph, V);
    }
}
