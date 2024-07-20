import java.util.*;

public class BellmanFord {
    public static Map<String, Integer> bellmanFord(Map<String, Map<String, Integer>> network, String source) {
        Map<String, Integer> minDistances = new HashMap<>();
        Map<String, String> previousNodes = new HashMap<>();

        for (String vertex : network.keySet()) {
            minDistances.put(vertex, Integer.MAX_VALUE);
            previousNodes.put(vertex, null);
        }

        minDistances.put(source, 0);

        for (int i = 0; i < network.size() - 1; i++) {
            for (String vertex : network.keySet()) {
                for (Map.Entry<String, Integer> edge : network.get(vertex).entrySet()) {
                    String adjacent = edge.getKey();
                    int cost = edge.getValue();

                    if (minDistances.get(vertex) != Integer.MAX_VALUE && minDistances.get(vertex) + cost < minDistances.get(adjacent)) {
                        minDistances.put(adjacent, minDistances.get(vertex) + cost);
                        previousNodes.put(adjacent, vertex);
                    }
                }
            }
        }

        return minDistances;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> network = new HashMap<>();
        network.put("A", new HashMap<>());
        network.get("A").put("B", 4);
        network.get("A").put("C", 1);
        network.put("B", new HashMap<>());
        network.get("B").put("C", -2);
        network.get("B").put("D", 5);
        network.put("C", new HashMap<>());
        network.get("C").put("E", 4);
        network.get("C").put("D", 2);
        network.put("D", new HashMap<>());
        network.get("D").put("E", -3);
        network.put("E", new HashMap<>());

        String source = "A";

        Map<String, Integer> shortestPaths = bellmanFord(network, source);
        for (Map.Entry<String, Integer> entry : shortestPaths.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
