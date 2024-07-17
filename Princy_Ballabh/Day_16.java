import java.util.*;
import java.util.LinkedList;

public class Day_16{
    static void bfs(List<List<Integer>> graph, int S, List<Integer> par, List<Integer> d){
        Queue<Integer> que = new LinkedList<>();
        d.set(S, 0);
        que.add(S);
        while(!que.isEmpty()){
            int node=que.poll();
            for(int neighbor:graph.get(node)){
                if(d.get(neighbor)==Integer.MAX_VALUE){
                    par.set(neighbor, node);
                    d.set(neighbor, d.get(node) + 1);
                    que.add(neighbor);
                }
            }
        }
    }

    static List<Integer> pathfind(List<List<Integer>> graph, int S, int D, int V){
        List<Integer> par=new ArrayList<>(Collections.nCopies(V, -1));
        List<Integer> d=new ArrayList<>(Collections.nCopies(V, Integer.MAX_VALUE));
        bfs(graph, S, par, d);
        if (d.get(D)==Integer.MAX_VALUE)
            return null;
        List<Integer> path=new ArrayList<>();
        int currentNode=D;
        path.add(D);
        while(par.get(currentNode)!=-1){
            path.add(par.get(currentNode));
            currentNode=par.get(currentNode);
        }
        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args){
        List<String> vertices=Arrays.asList("A", "B", "C", "D", "E");
        List<int[]> edges=Arrays.asList(
            new int[]{0,1}, 
            new int[]{0,2}, 
            new int[]{1,3}, 
            new int[]{2,4}, 
            new int[]{3,4}  
        );
        int startIdx=0; 
        int targetIdx=4;
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<vertices.size();i++){
            graph.add(new ArrayList<>());
        }
        for(int[] edge : edges){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]); 
        }
        List<Integer> path=pathfind(graph, startIdx, targetIdx, vertices.size());
        if(path!=null){
            System.out.println("Shortest path is : ");
            for(int i=0;i<path.size();i++)
                System.out.print(vertices.get(path.get(i))+" ");
        } 
        else 
            System.out.println("No path found");
    }
}
