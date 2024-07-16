import java.util.*;

public class Day_15{
    public static void main(String args[]){
        List<String> vertices=Arrays.asList("A", "B", "C", "D");
        List<String> edges=Arrays.asList("A->B", "B->C", "C->A", "C->D");
        Map<String, List<String>> graph=new HashMap<>();
        for(String vertex : vertices){
            graph.put(vertex, new ArrayList<>());
        }
        for(String edge : edges){
            String parts[]=edge.split("->");
            graph.get(parts[0]).add(parts[1]);
        }
        List<String> cycle=detectCycle(graph);
        if(cycle!=null) 
            System.out.println("Cycle : "+cycle);
        else
            System.out.println("No cycle");
    }

    public static List<String> detectCycle(Map<String, List<String>> graph) {
        Set<String> visited=new HashSet<>();
        Set<String> recStack=new HashSet<>();
        List<String> path=new ArrayList<>();
        for(String node : graph.keySet()){
            if(dfs(node, graph, visited, recStack, path)){
                Collections.reverse(path);
                return path;
            }
        }
        return null;
    }

    private static boolean dfs(String node, Map<String, List<String>> graph, Set<String> visited, Set<String> recStack, List<String> path){
        if(recStack.contains(node)){
            path.add(node);
            return true;
        }
        if(visited.contains(node)){
            return false;
        }
        visited.add(node);
        recStack.add(node);
        if(graph.containsKey(node)){
            for(String neighbor : graph.get(node)){
                if(dfs(neighbor, graph, visited, recStack, path)){
                    path.add(node);
                    return true;
                }
            }
        }
        recStack.remove(node);
        return false;
    }
}
