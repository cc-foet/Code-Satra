import java.util.*;

public class Day_17{
    public static void main(String args[]){
        Map<String, Map<String, Integer>> graph=new HashMap<>();
        graph.put("A",Map.of("B",4,"C",1));
        graph.put("B",Map.of("C",2,"D",5));
        graph.put("C",Map.of("D",8,"E",10));
        graph.put("D",Map.of("E",2));
        graph.put("E",Map.of());
        String s="A";
        String e="E";
        Map<String, Object> result=dijkstra(graph, s, e);
        System.out.println("Shortest Path: "+result.get("path"));
        System.out.println("Distance: "+result.get("distance"));
    }

    public static Map<String, Object> dijkstra(Map<String, Map<String, Integer>> graph, String s, String e){
        Map<String, Integer> distances=new HashMap<>();
        Map<String, String> previous=new HashMap<>();
        PriorityQueue<Map.Entry<String, Integer>> priorityQueue=new PriorityQueue<>(Map.Entry.comparingByValue());
        for(String node : graph.keySet()){
            if(node.equals(s))
                distances.put(node, 0);
            else 
                distances.put(node, Integer.MAX_VALUE);
            priorityQueue.add(new AbstractMap.SimpleEntry<>(node, distances.get(node)));
        }
        while(!priorityQueue.isEmpty()){
            String current=priorityQueue.poll().getKey();
            if(current.equals(e)) 
                break;
            Map<String, Integer> neighbors=graph.get(current);
            for(Map.Entry<String, Integer> neighbor : neighbors.entrySet()){
                int newDist=distances.get(current)+neighbor.getValue();
                if(newDist<distances.get(neighbor.getKey())){
                    distances.put(neighbor.getKey(),newDist);
                    previous.put(neighbor.getKey(),current);
                    priorityQueue.add(new AbstractMap.SimpleEntry<>(neighbor.getKey(),newDist));
                }
            }
        }
        List<String> path=new ArrayList<>();
        for(String at=e;at!=null;at=previous.get(at)){
            path.add(at);
        }
        Collections.reverse(path);
        Map<String, Object> result=new HashMap<>();
        result.put("path",path);
        result.put("distance",distances.get(e));        
        return result;
    }
}
