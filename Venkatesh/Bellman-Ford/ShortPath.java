import java.util.*;

public class ShortPath {
    public static Map<String, Integer> bellmanFord(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        Map<String, String> predecessors = new HashMap<>();

        for (String node : graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
            predecessors.put(node, null);
        }

        distances.put(start, 0);

        for (int i = 0; i < graph.size() - 1; i++) {
            for (String node : graph.keySet()) {
                for (Map.Entry<String, Integer> entry : graph.get(node).entrySet()) {
                    String neighbor = entry.getKey();
                    int weight = entry.getValue();

                    if (distances.get(node) != Integer.MAX_VALUE && distances.get(node) + weight < distances.get(neighbor)) {
                        distances.put(neighbor, distances.get(node) + weight);
                        predecessors.put(neighbor, node);
                    }
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", new HashMap<>());
        graph.get("A").put("B", 4);
        graph.get("A").put("C", 1);
        graph.put("B", new HashMap<>());
        graph.get("B").put("C", -2);
        graph.get("B").put("D", 5);
        graph.put("C", new HashMap<>());
        graph.get("C").put("E", 4);
        graph.get("C").put("D", 2);
        graph.put("D", new HashMap<>());
        graph.get("D").put("E", -3);
        graph.put("E", new HashMap<>());

        String start = "A";

        Map<String, Integer> shortestDistances = bellmanFord(graph, start);
        for (Map.Entry<String, Integer> entry : shortestDistances.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
