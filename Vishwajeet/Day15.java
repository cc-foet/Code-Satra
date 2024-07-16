// Problem: Given a directed graph, write a function that detects if there is a cycle in the graph. If the graph is cyclic, return the cycle, else return false.


// TIME COMPLEXITY: O(V + E) where V is the number of vertices and E is the number of edges in the graph. Because we are visiting each vertex and edge once.
// SPACE COMPLEXITY: O(V) where V is the number of vertices in the graph. Beacuse we are using a boolean array of size V to keep track of visited vertices.

import java.util.*;

public class Day15 {
    private int V;   // No. of vertices
    private LinkedList<Integer>[] adj; // Adjacency List
    private Map<Character, Integer> charToIndex; // Map to store character to index mapping
    private Map<Integer, Character> indexToChar; // Map to store index to character mapping

    // Constructor
    @SuppressWarnings("unchecked") // Suppress unchecked warning

    // Constructor
    public Day15(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i) {
            adj[i] = new LinkedList<>();
        }
        charToIndex = new HashMap<>();
        indexToChar = new HashMap<>();
    }

    // Function to add an edge into the graph
    void addEdge(char v, char w) {
        int vIndex = getIndex(v);
        int wIndex = getIndex(w);
        adj[vIndex].add(wIndex);
    }

    // Function to get the index of a character
    private int getIndex(char c) {
        if (!charToIndex.containsKey(c)) {
            int index = charToIndex.size();
            charToIndex.put(c, index);
            indexToChar.put(index, c);
        }
        return charToIndex.get(c);
    }

    // Function that detects cycle in a directed graph
    private boolean isCyclicUtil(int v, boolean[] visited, boolean[] recStack, List<Integer> path) {
        if (recStack[v]) {
            path.add(v);
            return true;
        }
        if (visited[v]) {
            return false;
        }

        // Mark the current node as visited and add to recursion stack
        visited[v] = true;
        recStack[v] = true;
        path.add(v);

        // Recur for all the vertices adjacent to this vertex
        for (Integer neighbour : adj[v]) {
            if (isCyclicUtil(neighbour, visited, recStack, path)) {
                return true;
            }
        }

        // Remove the vertex from recursion stack and path
        recStack[v] = false;
        path.remove(path.size() - 1);

        return false;
    }

    // Function that returns a cycle if it exists
    public List<Character> detectCycle() {
        boolean[] visited = new boolean[V];
        boolean[] recStack = new boolean[V];
        List<Integer> path = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            if (isCyclicUtil(i, visited, recStack, path)) {
                List<Character> cycle = new ArrayList<>();
                int start = path.get(path.size() - 1);
                cycle.add(indexToChar.get(start));
                for (int j = path.size() - 2; j >= 0; j--) {
                    cycle.add(indexToChar.get(path.get(j)));
                    if (path.get(j) == start) {
                        break;
                    }
                }
                Collections.reverse(cycle);
                return cycle;
            }
        }

        return Collections.emptyList(); // No cycle
    }

    public static void main(String[] args) {
        Day15 graph = new Day15(4);

        // Add edges as per the example
        graph.addEdge('A', 'B'); // A -> B
        graph.addEdge('B', 'C'); // B -> C
        graph.addEdge('C', 'A'); // C -> A
        graph.addEdge('C', 'D'); // C -> D

        List<Character> cycle = graph.detectCycle();
        if (cycle.isEmpty()) {
            System.out.println("No cycle detected");
        } else {
            System.out.println("Cycle detected: " + cycle);
        }
    }
}


