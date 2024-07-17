// Problem: Given an unweighted graph , find the shortest path from a starting node to a target node.

import java.util.*;

class Graph {
    private Map<Character, List<Character>> adjList;

    // Constructor
    public Graph() {
        adjList = new HashMap<>();
    }

    // Function to add an edge into the graph
    public void addEdge(char v, char w) {
        adjList.putIfAbsent(v, new ArrayList<>());
        adjList.putIfAbsent(w, new ArrayList<>());
        adjList.get(v).add(w);
        adjList.get(w).add(v); // Because the graph is undirected
    }

    // Function to find the shortest path from start to target using BFS
    public List<Character> findShortestPath(char start, char target) {
        Map<Character, Boolean> visited = new HashMap<>();
        Map<Character, Character> parent = new HashMap<>();
        Queue<Character> queue = new LinkedList<>();

        // Initialize
        queue.add(start);
        visited.put(start, true);
        parent.put(start, null);

        // BFS
        while (!queue.isEmpty()) {
            char current = queue.poll();

            if (current == target) {
                // Reconstruct the path
                List<Character> path = new ArrayList<>();
                for (Character at = target; at != null; at = parent.get(at)) {
                    path.add(at);
                }
                Collections.reverse(path); // Reverse the path to get the correct order
                return path;
            }

            // Visit all neighbors of current node
            for (char neighbor : adjList.get(current)) {
                if (!visited.getOrDefault(neighbor, false)) {
                    queue.add(neighbor);
                    visited.put(neighbor, true);
                    parent.put(neighbor, current);
                }
            }
        }

        return Collections.emptyList(); // No path found
    }

    public static void main(String[] args) {
        Graph graph = new Graph();

        // Add edges
        graph.addEdge('A', 'B');
        graph.addEdge('A', 'C');
        graph.addEdge('B', 'D');
        graph.addEdge('C', 'D');
        graph.addEdge('C', 'E');
        graph.addEdge('D', 'E');

        char start = 'A';
        char target = 'E';
        List<Character> path = graph.findShortestPath(start, target); // Find the shortest path

        if (path.isEmpty()) {
            System.out.println("No path found from " + start + " to " + target);
        } else {
            System.out.println("Shortest path from " + start + " to " + target + ": " + path);
        }
    }
}


