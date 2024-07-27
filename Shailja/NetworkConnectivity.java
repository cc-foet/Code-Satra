public class NetworkConnectivity {

    static class UnionFind {
        private int[] parent;
        private int[] rank;

        public UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    }

    public static boolean areInSameNetwork(int N, int[][] connections, int[] query) {
        UnionFind uf = new UnionFind(N);

        for (int[] connection : connections) {
            int a = connection[0];
            int b = connection[1];
            uf.union(a, b);
        }

        int u = query[0];
        int v = query[1];
        return uf.find(u) == uf.find(v);
    }

    public static void main(String[] args) {
        int N = 5;

        int[][] connections = { { 0, 2 }, { 4, 2 }, { 3, 1 } };

        int[] query = { 4, 0 };

        boolean result = areInSameNetwork(N, connections, query);
        System.out.println(result);
    }
}
