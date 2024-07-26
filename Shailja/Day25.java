import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Day25 {
     public static List<Integer> findTaskOrder(int N, int[][] dependencies) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }
        
        int[] inDegree = new int[N];
        
        for (int[] dependency : dependencies) {
            int from = dependency[0];
            int to = dependency[1];
            graph.get(from).add(to);
            inDegree[to]++;
        }
        
        Queue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }
        
        List<Integer> topologicalOrder = new ArrayList<>();
        
        // Process nodes
        while (!queue.isEmpty()) {
            int current = queue.poll();
            topologicalOrder.add(current);
            
            for (int neighbor : graph.get(current)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        if (topologicalOrder.size() != N) {
            throw new RuntimeException("The graph has a cycle. Tasks cannot be completed.");
        }
        
        return topologicalOrder;
    }

    public static void main(String[] args) {
        int N = 6;
        int[][] dependencies = {
            {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
        };
        
        try {
            List<Integer> taskOrder = findTaskOrder(N, dependencies);
            System.out.println("Task order: " + taskOrder);
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }
}
