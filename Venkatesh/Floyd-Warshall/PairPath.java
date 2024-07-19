public class PairPath {
    public static int[][] shortestpath(int[][] graph) {
        int n = graph.length;
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(graph[i], 0, dist[i], 0, n);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        int INF = Integer.MAX_VALUE;
        int[][] graph = {{0, 4, INF, 5, INF},
                        {INF, 0, 1, INF, 6},
                        {2, INF, 0, 3, INF},
                        {INF, INF, 1, 0, 2},
                        {1, INF, INF, 4, 0}};
        int[][] dist = shortestpath(graph);
        for (int i = 0; i < dist.length; i++) {
            for (int j = 0; j < dist[i].length; j++) {
                 System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }
}