import java.util.*;

public class ShortestPath {
    public static List<String> findShortestPath(Map<String, List<String>> graph, String source, String destination) {
        Queue<List<String>> pathsQueue = new LinkedList<>();
        Set<String> visitedNodes = new HashSet<>();
        
        pathsQueue.add(Arrays.asList(source));
        visitedNodes.add(source);
        
        while (!pathsQueue.isEmpty()) {
            List<String> currentPath = pathsQueue.poll();
            String currentNode = currentPath.get(currentPath.size() - 1);
            
            if (currentNode.equals(destination)) {
                return currentPath;
            }
            
            for (String neighbor : graph.getOrDefault(currentNode, new ArrayList<>())) {
                if (!visitedNodes.contains(neighbor)) {
                    visitedNodes.add(neighbor);
                    List<String> newPath = new ArrayList<>(currentPath);
                    newPath.add(neighbor);
                    pathsQueue.add(newPath);
                }
            }
        }
        
        return new ArrayList<>(); 
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D"));
        graph.put("C", Arrays.asList("E"));
        graph.put("D", Arrays.asList("E"));
        graph.put("E", new ArrayList<>());
        
        String source = "A";
        String destination = "E";
        
        List<String> shortestPath = findShortestPath(graph, source, destination);
        System.out.println("Shortest Path: " + shortestPath);
    }
}
