public class Network {
    public static boolean areConnected(int[][] connections, int[] query, int n) {
        DisjointSetUnion dsu = new DisjointSetUnion(n);
        for (int[] connection : connections) {
            dsu.union(dsu.leader, dsu.level, connection[0], connection[1]);
        }
        return dsu.find(dsu.leader, query[0]) == dsu.find(dsu.leader, query[1]);
    }

    public static void main(String[] args) {
        int n = 5;
        int[][] connections = {{0, 2}, {4, 2}, {3, 1}};
        int[] query = {4, 0};

        System.out.println(areConnected(connections, query, n));
    }
}
class DisjointSetUnion {
    int[] leader;
    int[] level;

    public int find(int[] leader, int x) {
        if (leader[x] != x) {
            leader[x] = find(leader, leader[x]); // Path compression
        }
        return leader[x];
    }

    public void union(int[] leader, int[] level, int x, int y) {
        int xRoot = find(leader, x);
        int yRoot = find(leader, y);
        if (xRoot == yRoot) {
            return;
        }
        if (level[xRoot] < level[yRoot]) {
            leader[xRoot] = yRoot;
        } else if (level[xRoot] > level[yRoot]) {
            leader[yRoot] = xRoot;
        } else {
            leader[yRoot] = xRoot;
            level[xRoot]++;
        }
    }

    DisjointSetUnion(int n) {
        leader = new int[n];
        level = new int[n];
        for (int i = 0; i < n; i++) {
            leader[i] = i;
            level[i] = 0;
        }
    }
}


