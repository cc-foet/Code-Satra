// Problem: Given a connected, undirected graph with weighted edges, find the minimum spanning tree using Kruskal's or Prim's algorithm. The graph edges are represented as (u, v, weight) where u and v are the nodes and weight is the edge weight and also given N representing the number of edges.

// Kruskal's Algorithm

// Time Complexity: O(ElogE + ElogV) where E is the number of edges and V is the number of vertices because we are sorting the edges based on their weight and iterating through all the edges.

// Space Complexity: O(V) where V is the number of vertices to store the parent and rank arrays.


import java.util.Arrays;
import java.util.Comparator;

class Edge {
    int u, v, weight;

    public Edge(int u, int v, int weight) {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }
}

// Disjoint Set Data Structure
class DisjointSet {
    int[] parent, rank;

    public DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Path Compression
    public int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union by Rank
    public void union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
}

public class Day30 {
    public static Edge[] kruskalMST(Edge[] edges, int numVertices) {
        // Step 1: Sort all the edges in non-decreasing order of their weight
        Arrays.sort(edges, Comparator.comparingInt(e -> e.weight));

        // Step 2: Create disjoint sets
        DisjointSet ds = new DisjointSet(numVertices);

        // Step 3: Iterate through the sorted edges and construct the MST
        Edge[] mst = new Edge[numVertices - 1];
        int mstIndex = 0;

        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;

            // Check if the selected edge forms a cycle with the spanning-tree
            if (ds.find(u) != ds.find(v)) {
                mst[mstIndex++] = edge;
                ds.union(u, v);
            }

            // If we already have n-1 edges in MST, break the loop
            if (mstIndex == numVertices - 1) {
                break;
            }
        }

        return mst;
    }

    public static void main(String[] args) {
        int numVertices = 6; // Number of vertices
        int numEdges = 6; // Number of edges
        Edge[] edges = new Edge[numEdges];

        // Define edges as (u, v, weight)
        edges[0] = new Edge(0, 1, 2);
        edges[1] = new Edge(1, 2, 3);
        edges[2] = new Edge(0, 3, 6);
        edges[3] = new Edge(1, 3, 8);
        edges[4] = new Edge(1, 4, 5);
        edges[5] = new Edge(2, 4, 7);

        // Compute the MST
        Edge[] mst = kruskalMST(edges, numVertices);

        // Print the MST
        System.out.println("Edges in the Minimum Spanning Tree:");
        for (Edge edge : mst) {
            System.out.println("Edge: (" + edge.u + ", " + edge.v + ") with weight " + edge.weight);
        }
    }
}
