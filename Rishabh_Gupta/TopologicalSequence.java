import java.util.*;

public class TopologicalSequence {
    public static List<Integer> sequence(int[][] dependencies, int numNodes) {
        List<Integer> result = new ArrayList<>();
        if (numNodes < 0) return result;
        
        Map<Integer, List<Integer>> adjacencyList = new HashMap<>();
        int[] inDegree = new int[numNodes];

        for (int i = 0; i < numNodes; i++) {
            adjacencyList.put(i, new ArrayList<>());
        }
        for (int[] dependency : dependencies) {
            adjacencyList.get(dependency[0]).add(dependency[1]);
            inDegree[dependency[1]]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numNodes; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            int currentNode = queue.poll();
            result.add(currentNode);
            for (int neighbor : adjacencyList.get(currentNode)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.offer(neighbor);
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int numNodes = 6;
        int[][] dependencies = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

        System.out.println(sequence(dependencies, numNodes));
    }
}
