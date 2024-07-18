import java.util.*;

public class Dijkstra {
    public static void dijkstra(Map<String, Map<String, Integer>> graph, String startNode, String endNode) {
        Map<String, Integer> shortestDistances = new HashMap<>();
        for (String node : graph.keySet()) {
            shortestDistances.put(node, Integer.MAX_VALUE);
        }
        shortestDistances.put(startNode, 0);
        Map<String, String> previousNodes = new HashMap<>();
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();

        priorityQueue.add(new Node(0, startNode));

        while (!priorityQueue.isEmpty()) {
            Node currentNode = priorityQueue.poll();
            int currentDistance = currentNode.distance;
            String currentNodeName = currentNode.node;

            if (currentNodeName.equals(endNode)) {
                break;
            }

            for (Map.Entry<String, Integer> entry : graph.get(currentNodeName).entrySet()) {
                String neighborNode = entry.getKey();
                int edgeWeight = entry.getValue();
                int newDistance = currentDistance + edgeWeight;

                if (newDistance < shortestDistances.get(neighborNode)) {
                    shortestDistances.put(neighborNode, newDistance);
                    previousNodes.put(neighborNode, currentNodeName);
                    priorityQueue.add(new Node(newDistance, neighborNode));
                }
            }
        }

        List<String> path = new ArrayList<>();
        String currentNodeName = endNode;
        while (!currentNodeName.equals(startNode)) {
            if (previousNodes.containsKey(currentNodeName)) {
                path.add(0, currentNodeName);
                currentNodeName = previousNodes.get(currentNodeName);
            } else {
                System.out.println("Path not reachable");
                return;
            }
        }
        path.add(0, startNode);

        if (shortestDistances.get(endNode) != Integer.MAX_VALUE) {
            System.out.println("Shortest Path: " + path);
            System.out.println("Distance: " + shortestDistances.get(endNode));
        }
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", new HashMap<>());
        graph.put("B", new HashMap<>());
        graph.put("C", new HashMap<>());
        graph.put("D", new HashMap<>());
        graph.put("E", new HashMap<>());

        graph.get("A").put("B", 4);
        graph.get("A").put("C", 1);
        graph.get("B").put("C", 2);
        graph.get("B").put("D", 5);
        graph.get("C").put("D", 8);
        graph.get("C").put("E", 10);
        graph.get("D").put("E", 2);

        String startNode = "A";
        String endNode = "E";

        dijkstra(graph, startNode, endNode);
    }

    static class Node implements Comparable<Node> {
        int distance;
        String node;

        public Node(int distance, String node) {
            this.distance = distance;
            this.node = node;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.distance, other.distance);
        }
    }
}
