// Problem: Given number of tasks N and an array of dependencies as pairs(a, b) where task a must be completed before task b. Find a sequence to complete all tasks.

// Topological Sorting: A topological ordering is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges. Because we are visiting each vertex and edge once.

// Space Complexity: O(V) because we are using a queue to store vertices with in-degree 0.

import java.util.*;

public class Day25 {
    public static List<Integer> findTaskOrder(int N, int[][] dependencies) {
        // Create a graph
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }
        
        // Array to keep track of in-degrees
        int[] inDegree = new int[N];
        
        // Build the graph and populate in-degrees
        for (int[] dep : dependencies) {
            int a = dep[0];
            int b = dep[1];
            graph.get(a).add(b);
            inDegree[b]++;
        }
        
        // Queue for nodes with in-degree 0
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            int current = queue.poll();
            result.add(current);
            
            // Decrease the in-degree of neighbors
            for (int neighbor : graph.get(current)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        // If result contains all tasks, we found a valid order
        if (result.size() == N) {
            return result;
        } else {
            // If there is a cycle, it is impossible to complete all tasks
            return new ArrayList<>(); // Returning an empty list to indicate failure
        }
    }
    
    public static void main(String[] args) {
        int N = 6;
        int[][] dependencies = {
            {5, 2},
            {5, 0},
            {4, 0},
            {4, 1},
            {2, 3},
            {3, 1}
        };  // Expected output: [4, 5, 2, 0, 3, 1]
        
        List<Integer> order = findTaskOrder(N, dependencies);
        if (order.isEmpty()) {
            System.out.println("It is impossible to complete all tasks due to a cycle.");
        } else {
            System.out.println("A valid task order is: " + order);
        }
    }
}
