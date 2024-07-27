
class DisjointSetUnion {
    int[] parent;
    int[] rank;

    public int find(int[] parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    public void union(int[] parent, int[] rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);
        if (xRoot == yRoot) {
            return;
        }
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    DisjointSetUnion(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
}

public class ComputerNetwork {
    public static boolean areConnected(int[][] connections, int[] query, int n) {
        DisjointSetUnion dsu = new DisjointSetUnion(n);
        for (int[] connection : connections) {
            dsu.union(dsu.parent, dsu.rank, connection[0], connection[1]);
        }
        return dsu.find(dsu.parent, query[0]) == dsu.find(dsu.parent, query[1]);
    }
    public static void main(String[] args) {
        int n = 5;
        int[][] connections = {{0, 2}, {4, 2}, {3, 1}};
        int[] query = {4, 0};

        System.out.println(areConnected(connections, query, n));
    }
}
