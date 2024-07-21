import java.util.HashMap;
import java.util.Map;

public class Day_19{
    public static void main(String args[]){
        Map<String, Map<String, Integer>> graph=new HashMap<>();        
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
        String start="A";
        Map<String,Integer> dist=bellmanford(graph,start);
        System.out.println("Output: "+dist);
    }

    public static Map<String,Integer> bellmanford(Map<String, Map<String, Integer>> graph, String start){
        Map<String,Integer> dist=new HashMap<>();
        for(String vertex:graph.keySet()){
            dist.put(vertex, Integer.MAX_VALUE);
        }
        dist.put(start, 0);
        int V=graph.size();
        for(int i=1;i<V;i++){
            for(String u:graph.keySet()){
                for(Map.Entry<String, Integer> entry:graph.get(u).entrySet()){
                    String v=entry.getKey();
                    int weight=entry.getValue();
                    if(dist.get(u)!=Integer.MAX_VALUE && dist.get(u)+weight<dist.get(v)){
                        dist.put(v, dist.get(u)+weight);
                    }
                }
            }
        }
        for(String u:graph.keySet()){
            for(Map.Entry<String,Integer> entry:graph.get(u).entrySet()){
                String v=entry.getKey();
                int weight=entry.getValue();
                if(dist.get(u)!=Integer.MAX_VALUE && dist.get(u)+weight<dist.get(v)){
                    System.out.println("Graph has negative weight cycle");
                }
            }
        }
        return dist;
    }
}
