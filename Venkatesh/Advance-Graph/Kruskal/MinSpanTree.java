import java.util.Arrays;

public class MinSpanTree {
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

        int[][] result = new int[n - 1][2];
        int resultIndex = 0;

        Arrays.sort(graph, (a, b) -> a[2] - b[2]);

        int i = 0;
        while (resultIndex < n - 1) {
            int[] edge = graph[i++];
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);

            if (x != y) {
                result[resultIndex++] = edge;
                union(parent, rank, x, y);
            }
        }
        return result;
    }
    public static void main(String[] args) {
        int[][] graph = {{0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};
        int n = 5;

        System.out.println(Arrays.deepToString(kruskal(graph, n)));
    }    
}
