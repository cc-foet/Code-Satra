import java.util.*;

public class CyclicGraph {
    private Map<String, List<String>> adjacencyList = new HashMap<>();

    public void addEdge(String startNode, String endNode) {
        this.adjacencyList.computeIfAbsent(startNode, k -> new ArrayList<>()).add(endNode);
    }

    public List<String> findCycle() {
        Set<String> visitedNodes = new HashSet<>();
        List<String> currentPath = new ArrayList<>();

        for (String node : this.adjacencyList.keySet()) {
            List<String> cycle = depthFirstSearch(node, visitedNodes, currentPath);
            if (cycle != null) {
                return cycle;
            }
        }
        return null;
    }

    private List<String> depthFirstSearch(String currentNode, Set<String> visitedNodes, List<String> currentPath) {
        if (visitedNodes.contains(currentNode)) {
            int startIndex = currentPath.indexOf(currentNode);
            List<String> cycle = new ArrayList<>(currentPath.subList(startIndex, currentPath.size()));
            cycle.add(currentNode);
            return cycle;
        }
        visitedNodes.add(currentNode);
        currentPath.add(currentNode);

        for (String neighbor : this.adjacencyList.getOrDefault(currentNode, new ArrayList<>())) {
            List<String> cycle = depthFirstSearch(neighbor, visitedNodes, new ArrayList<>(currentPath));
            if (cycle != null) {
                return cycle;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        CyclicGraph graph = new CyclicGraph();
        graph.addEdge("A", "B");
        graph.addEdge("B", "C");
        graph.addEdge("C", "A");
        graph.addEdge("C", "D");

        List<String> cycle = graph.findCycle();
        if (cycle != null) {
            System.out.println(String.join(" ", cycle));
        } else {
            System.out.println("False");
        }
    }
}
