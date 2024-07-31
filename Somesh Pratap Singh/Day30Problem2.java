import java.util.Arrays;

public class krushkal {

  
    public static int find(int[] parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);  
        }
        return parent[i];
    }

  
    public static void union(int[] parent, int[] rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

    
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

   
    public static int[][] kruskal(int[][] graph, int n) {
        int[] parent = new int[n];
        int[] rank = new int[n];

      
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

      
        Arrays.sort(graph, (a, b) -> Integer.compare(a[2], b[2]));

        int[][] mst = new int[n - 1][3];  
        int mstIndex = 0;  

        int i = 0;  
        while (mstIndex < n - 1 && i < graph.length) {
            int[] edge = graph[i++];
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            int x = find(parent, u);
            int y = find(parent, v);

          
            if (x != y) {
                mst[mstIndex++] = edge;  
                union(parent, rank, x, y);
            }
        }

       
        if (mstIndex != n - 1) {
            throw new IllegalArgumentException("Input graph is not connected.");
        }

        return mst;
    }

    public static void main(String[] args) {
        int[][] graph = {
            {0, 1, 2}, {1, 2, 3}, {0, 3, 6},
            {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
        };
        int n = 5;

        try {
            int[][] mst = kruskal(graph, n);
            System.out.println("Minimum Spanning Tree:");
            for (int[] edge : mst) {
                System.out.printf("Edge: %d - %d, Weight: %d%n", edge[0], edge[1], edge[2]);
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
