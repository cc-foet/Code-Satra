import java.util.Arrays;
import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Comparator;

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

    public static int[][] prim(int[][] graph, int n) {
        boolean[] inMST = new boolean[n];
        int[][] result = new int[n - 1][2];
        int resultIndex = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
        pq.add(new int[]{0, 0, 0});

        while (!pq.isEmpty() && resultIndex < n - 1) {
            int[] edge = pq.poll();
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (inMST[v]) continue;

            inMST[v] = true;
            if (u != v) {
                result[resultIndex++] = new int[]{u, v, weight};
            }

            for (int[] nextEdge : graph) {
                if (nextEdge[0] == v && !inMST[nextEdge[1]]) {
                    pq.add(new int[]{v, nextEdge[1], nextEdge[2]});
                } else if (nextEdge[1] == v && !inMST[nextEdge[0]]) {
                    pq.add(new int[]{v, nextEdge[0], nextEdge[2]});
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] graph = {{0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};
        int n = 5;

        System.out.println("Choose algorithm: 1 for Kruskal, 2 for Prim");
        int choice = scanner.nextInt();

        int[][] mst;
        if (choice == 1) {
            mst = kruskal(graph, n);
        } else {
            mst = prim(graph, n);
        }

        System.out.println("Minimum Spanning Tree:");
        for (int[] edge : mst) {
            System.out.println(Arrays.toString(edge));
            scanner.close();
        }
    }
}
