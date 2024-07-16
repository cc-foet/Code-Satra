import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Cyclic {
    private Map<String, List<String>> graph = new HashMap<>();

    public void addEdge(String start, String end) {
        this.graph.computeIfAbsent(start, k -> new ArrayList<>()).add(end);
    }

    public List<String> cyclic() {
        Set<String> visited = new HashSet<>();
        List<String> path = new ArrayList<>();

        for (String node : this.graph.keySet()) {
            List<String> cycle = dfs(node, visited, path);
            if (cycle != null) {
                return cycle;
            }
        }
        return null;
    }

    private List<String> dfs(String node, Set<String> visited, List<String> path) {
        if (visited.contains(node)) {
            int start_index = path.indexOf(node);
            List<String> cycle = new ArrayList<>(path.subList(start_index, path.size()));
            cycle.add(node);
            return cycle;
        }
        visited.add(node);
        path.add(node);

        for (String neighbour : this.graph.getOrDefault(node, new ArrayList<>())) {
            List<String> cycle = dfs(neighbour, visited, new ArrayList<>(path));
            if (cycle != null) {
                return cycle;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Cyclic graph = new Cyclic();
        graph.addEdge("A", "B");
        graph.addEdge("B", "C");
        graph.addEdge("C", "A");
        graph.addEdge("C", "D");

        List<String> cycle = graph.cyclic();
        if (cycle != null) {
            System.out.println(String.join(" ", cycle));
        } else {
            System.out.println("False");
        }
    }
}