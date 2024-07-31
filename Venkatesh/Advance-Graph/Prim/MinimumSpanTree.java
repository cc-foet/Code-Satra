import java.util.*;

public class MinimumSpanTree {
    private static class Edge implements Comparable<Edge> {
        int vertex;
        int weight;

        Edge(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    static int[][] prim(int[][] graph, int n) {
        List<List<Edge>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }

        for (int[] edge : graph) {
            adjList.get(edge[0]).add(new Edge(edge[1], edge[2]));
            adjList.get(edge[1]).add(new Edge(edge[0], edge[2]));
        }

        int[] parent = new int[n];
        Arrays.fill(parent, -1);

        int[] key = new int[n];
        Arrays.fill(key, Integer.MAX_VALUE);

        boolean[] inMST = new boolean[n];

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        key[0] = 0;
        pq.add(new Edge(0, 0));

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int u = edge.vertex;

            if (inMST[u]) {
                continue;
            }

            inMST[u] = true;

            for (Edge e : adjList.get(u)) {
                int v = e.vertex;
                int weight = e.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.add(new Edge(v, key[v]));
                    parent[v] = u;
                }
            }
        }

        List<int[]> mst = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            mst.add(new int[]{parent[i], i, key[i]});
        }
        return mst.toArray(new int[mst.size()][]);
    }
    public static void main(String[] args) {
        int[][] graph = {{0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};
        int n = 5;

        
        System.out.println(Arrays.deepToString(prim(graph, n)));
    }
}