import java.util.*;

public class ShortestPath {

    public static List<String> shortestPath(Map<String, Set<String>> graph, String start, String end) {
        Queue<List<String>> queue = new ArrayDeque<>();
        queue.add(Arrays.asList(start));
        List<String> shortest = null;

        while (!queue.isEmpty()) {
            List<String> path = queue.poll();
            String vertex = path.get(path.size() - 1);

            for (String next : graph.get(vertex)) {
                if (!path.contains(next)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(next);

                    if (next.equals(end)) {
                        if (shortest == null || newPath.size() < shortest.size()) {
                            shortest = newPath;
                        }
                    } else {
                        queue.add(newPath);
                    }
                }
            }
        }
        return shortest;
    }

    public static void main(String[] args) {
        String[] nodes = {"A", "B", "C", "D", "E"};
        String[][] edges = {{"A", "B"}, {"A", "C"}, {"B", "D"}, {"C", "E"}, {"D", "E"}};
        String startNode = "A";
        String endNode = "E";

        Map<String, Set<String>> graph = new HashMap<>();
        for (String node : nodes) {
            graph.put(node, new HashSet<>());
        }
        for (String[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
        }

        List<String> path = shortestPath(graph, startNode, endNode);
        System.out.println(path);
    }
}
