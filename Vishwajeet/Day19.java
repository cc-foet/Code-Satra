// Problem: Given a weighted graph, write a function to find the shortest path from a single source node to all other nodes using Bellman-Ford algorithm.

import java.util.*;

public class Day19 {
    static class Edge {
        char source;
        char destination;
        int weight;

        Edge(char source, char destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }

    public static void bellmanFord(List<Edge> edges, char start, int verticesCount) {
        Map<Character, Integer> distances = new HashMap<>();
        Map<Character, Character> predecessors = new HashMap<>();

        // Initialize distances
        for (int i = 0; i < verticesCount; i++) {
            char vertex = (char) ('A' + i);
            distances.put(vertex, Integer.MAX_VALUE);
        }
        distances.put(start, 0);

        // Relax edges |V| - 1 times
        for (int i = 1; i < verticesCount; i++) {
            for (Edge edge : edges) {
                char u = edge.source;
                char v = edge.destination;
                int weight = edge.weight;

                if (distances.get(u) != Integer.MAX_VALUE && distances.get(u) + weight < distances.get(v)) {
                    distances.put(v, distances.get(u) + weight);
                    predecessors.put(v, u);
                }
            }
        }

        // Check for negative weight cycles
        for (Edge edge : edges) {
            char u = edge.source;
            char v = edge.destination;
            int weight = edge.weight;

            if (distances.get(u) != Integer.MAX_VALUE && distances.get(u) + weight < distances.get(v)) {
                System.out.println("Graph contains negative weight cycle");
                return;
            }
        }

        // Print the shortest distances and paths
        for (int i = 0; i < verticesCount; i++) {
            char vertex = (char) ('A' + i);
            System.out.print("Distance from " + start + " to " + vertex + " is " + distances.get(vertex) + ". Path: ");
            if (vertex == start) {
                System.out.println(start);
            } else {
                printPath(predecessors, vertex);
                System.out.println();
            }
        }
    }

    private static void printPath(Map<Character, Character> predecessors, char current) {
        if (predecessors.get(current) == null) {
            System.out.print(current);
            return;
        }
        printPath(predecessors, predecessors.get(current));
        System.out.print(" -> " + current);
    }

    public static void main(String[] args) {
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge('A', 'B', 4));
        edges.add(new Edge('A', 'C', 1));
        edges.add(new Edge('B', 'C', -2));
        edges.add(new Edge('B', 'D', 5));
        edges.add(new Edge('C', 'D', 2));
        edges.add(new Edge('C', 'E', 4));
        edges.add(new Edge('D', 'E', -3));

        char startVertex = 'A';
        int verticesCount = 5; // A, B, C, D, E

        bellmanFord(edges, startVertex, verticesCount);
    }
}
