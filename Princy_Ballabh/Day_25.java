import java.util.*;
import java.util.LinkedList;

public class Day_25{
    public static void main(String args[]){
        int n=6;
        int[][] prerequisites={
            {5,2},
            {5,0},
            {4,0},
            {4,1},
            {2,3},
            {3,1}
        };
        List<Integer> order=findOrder(n, prerequisites);
        if(!order.isEmpty()){
            System.out.println(order);
        }
    }

    public static List<Integer> findOrder(int n, int prerequisites[][]){
        List<Integer> order=new ArrayList<>();
        if(n==0) 
        return order;
        List<List<Integer>> adjList=new ArrayList<>(n);
        for(int i=0;i<n;i++){
            adjList.add(new ArrayList<>());
        }
        int inDegree[]=new int[n];
        for(int[] prerequisite : prerequisites){
            adjList.get(prerequisite[0]).add(prerequisite[1]);
            inDegree[prerequisite[1]]++;
        }
        Queue<Integer> queue=new LinkedList<Integer>();
        for (int i=0;i<n;i++) {
            if(inDegree[i]==0){
                queue.add(i);
            }
        }
        while(!queue.isEmpty()){
            int current=queue.poll();
            order.add(current);
            for(int neighbor : adjList.get(current)){
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0){
                    queue.add(neighbor);
                }
            }
        }
        if(order.size()!=n){
            System.out.println("There exists a cycle in the graph");
            return new ArrayList<>();
        }
        return order;
    }   
}
