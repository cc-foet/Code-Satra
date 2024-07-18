import java.util.*;

public class Path {
    public static void dijkstra(Map<String, Map<String, Integer>> graph, String start, String end) {
        Map<String, Integer> shortest = new HashMap<>();
        for (String node : graph.keySet()) {
            shortest.put(node, Integer.MAX_VALUE);
        }
        shortest.put(start, 0);
        Map<String, String> prev = new HashMap<>();
        PriorityQueue<Node> pq = new PriorityQueue<>();

        pq.add(new Node(0, start));

        while (!pq.isEmpty()) {
            Node curr = pq.poll();
            int currDistance = curr.distance;
            String currNode = curr.node;

            if (currNode.equals(end)) {
                break;
            }

            for (Map.Entry<String, Integer> entry : graph.get(currNode).entrySet()) {
                String neighbor = entry.getKey();
                int weight = entry.getValue();
                int distance = currDistance + weight;

                if (distance < shortest.get(neighbor)) {
                    shortest.put(neighbor, distance);
                    prev.put(neighbor, currNode);
                    pq.add(new Node(distance, neighbor));
                }
            }
        }

        List<String> path = new ArrayList<>();
        String currNode = end;
        while (!currNode.equals(start)) {
            if (prev.containsKey(currNode)) {
                path.add(0, currNode);
                currNode = prev.get(currNode);
            } else {
                System.out.println("Path not reachable");
                return;
            }
        }
        path.add(0, start);

        if (shortest.get(end) != Integer.MAX_VALUE) {
            System.out.println("Shortest Path: " + path);
            System.out.println("Distance: " + shortest.get(end));
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

        String start = "A";
        String end = "E";

        dijkstra(graph, start, end);
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
