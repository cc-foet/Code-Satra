public class PairPath {
    public static int[][] calculateShortestPath(int[][] matrix) {
        int size = matrix.length;
        int[][] result = new int[size][size];
        
        for (int row = 0; row < size; row++) {
            System.arraycopy(matrix[row], 0, result[row], 0, size);
        }

        for (int mid = 0; mid < size; mid++) {
            for (int start = 0; start < size; start++) {
                for (int end = 0; end < size; end++) {
                    if (result[start][mid] != Integer.MAX_VALUE && 
                        result[mid][end] != Integer.MAX_VALUE && 
                        result[start][end] > result[start][mid] + result[mid][end]) {
                        result[start][end] = result[start][mid] + result[mid][end];
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int INF = Integer.MAX_VALUE;
        int[][] graph = {
            {0, 4, INF, 5, INF},
            {INF, 0, 1, INF, 6},
            {2, INF, 0, 3, INF},
            {INF, INF, 1, 0, 2},
            {1, INF, INF, 4, 0}
        };
        
        int[][] shortestPaths = calculateShortestPath(graph);
        
        for (int row = 0; row < shortestPaths.length; row++) {
            for (int col = 0; col < shortestPaths[row].length; col++) {
                System.out.print(shortestPaths[row][col] + " ");
            }
            System.out.println();
        }
    }
}
