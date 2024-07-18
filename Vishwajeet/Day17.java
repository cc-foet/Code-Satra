// Problem: Given a weighted fraph, use Djikstra's algorithm to find the shortest path and the distance between the given start and end nodes.

import java.util.*;

public class Day17 {
    private Map<Character, Map<Character, Integer>> adjList;

    // Constructor
    public Day17() {
        adjList = new HashMap<>();
    }

    public void addEdge(char from, char to, int weight) {
        adjList.putIfAbsent(from, new HashMap<>());
        adjList.get(from).put(to, weight);
        adjList.putIfAbsent(to, new HashMap<>()); // Ensure all nodes are initialized
    }

    // Djikstra's algorithm
    public Result djikstra(char start, char end) {
        Map<Character, Integer> distances = new HashMap<>();
        Map<Character, Character> previous = new HashMap<>();
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.distance));

        // Initialize distances
        for (char vertex : adjList.keySet()) {
            distances.put(vertex, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node currentNode = pq.poll();
            char current = currentNode.vertex;

            if (current == end) {
                break;
            }


            // Check if the distance to the current node is already greater than the distance to the current node
            for (Map.Entry<Character, Integer> neighborEntry : adjList.get(current).entrySet()) {
                char neighbor = neighborEntry.getKey();
                int newDist = distances.get(current) + neighborEntry.getValue();

                if (newDist < distances.get(neighbor)) {
                    distances.put(neighbor, newDist);
                    previous.put(neighbor, current);
                    pq.add(new Node(neighbor, newDist));
                }
            }
        }

        // Reconstruct path
        List<Character> path = new ArrayList<>();
        char step = end;
        if (previous.get(step) != null || step == start) {
            while (previous.get(step) != null) {
                path.add(step);
                step = previous.get(step);
            }
            path.add(start);
            Collections.reverse(path);
        }

        int distance = distances.get(end) == Integer.MAX_VALUE ? -1 : distances.get(end);
        return new Result(path, distance);
    }

    public static void main(String[] args) {
        Day17 graph = new Day17();

        // Add edges
        graph.addEdge('A', 'B', 4);
        graph.addEdge('A', 'C', 1);
        graph.addEdge('B', 'C', 2);
        graph.addEdge('B', 'D', 5);
        graph.addEdge('C', 'D', 8);
        graph.addEdge('C', 'E', 10);
        graph.addEdge('D', 'E', 2);

        char start = 'A';
        char end = 'E';
        Result result = graph.djikstra(start, end);

        if (result.distance == -1) {
            System.out.println("No path found from " + start + " to " + end);
        } else {
            System.out.println("Shortest path from " + start + " to " + end + ": " + result.path);
            System.out.println("Distance: " + result.distance);
        }
    }
}

class Node {
    char vertex;
    int distance;

    Node(char vertex, int distance) {
        this.vertex = vertex;
        this.distance = distance;
    }
}

class Result {
    List<Character> path;
    int distance;

    Result(List<Character> path, int distance) {
        this.path = path;
        this.distance = distance;
    }
}
