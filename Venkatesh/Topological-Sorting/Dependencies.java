import java.util.*;
import java.util.LinkedList;

public class Dependencies {
    public static List<Integer> sequence(int[][] dependencies, int n) {
        List<Integer> result = new ArrayList<>();
        if (n < 0) return result;
        
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int[] inDegree = new int[n];

        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }
        for (int[] dependency : dependencies) {
            graph.get(dependency[0]).add(dependency[1]);
            inDegree[dependency[1]]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            int node = queue.poll();
            result.add(node);
            for (int neighbor : graph.get(node)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.offer(neighbor);
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int n = 6;
        int[][] dependencies = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

        System.out.println(sequence(dependencies, n));
    }
}