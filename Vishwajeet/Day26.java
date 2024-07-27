// Problem: Given a network of N computers, in the form of (a, b) pairs, where the pair (a, b) represents a connection from computer a to computer b. Perform a series of union and find operations to manage network connectivity and determine if two computers are in the same network. 

// Disjoint Set Union (DSU) is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It supports two main operations:

// Time Complexity: O(log N) for find and union operations because of path compression and union by rank optimizations.

// Space Complexity: O(N) to store the parent and rank arrays.

public class Day26 {
    private int[] parent;
    private int[] rank;

    // Initialize the Union-Find data structure with N elements.
    public Day26(int N) {
        parent = new int[N];
        rank = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the root of the element x with path compression.
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union the sets that contain elements x and y.
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
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

    // Check if elements x and y are in the same set.
    public boolean connected(int x, int y) {
        return find(x) == find(y);
    }

    public static void main(String[] args) {
        int N = 5; // Example number of computers
        Day26 uf = new Day26(N);

        // Example connections (a, b) pairs
        int[][] connections = {
            {0, 2},
            {4, 2},
            {3, 1},
        };

        // Perform union operations for each connection
        for (int[] connection : connections) {
            uf.union(connection[0], connection[1]);
        }

        // Example find operations to check if two computers are connected
        System.out.println("4 and 0 connected ? " + uf.connected(4, 0)); // Should be true
    }
}
