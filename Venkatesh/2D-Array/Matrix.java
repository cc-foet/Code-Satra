public class Matrix {

    public static int[] spiral(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        
        int result[] = new int[m * n];
        int rowStart = 0;
        int rowEnd = m - 1;
        int colStart = 0;
        int colEnd = n - 1;
        int index = 0;
        
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i++) {
                result[index++] = matrix[rowStart][i];
            }
            rowStart++;
            
            for (int i = rowStart; i <= rowEnd; i++) {
                result[index++] = matrix[i][colEnd];
            }
            colEnd--;
            
            if (rowStart <= rowEnd) {
                for (int i = colEnd; i >= colStart; i--) {
                    result[index++] = matrix[rowEnd][i];
                }
            }
            rowEnd--;
            
            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    result[index++] = matrix[i][colStart];
                }
            }
            colStart++;
        }

        return result;        
    }
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3, 4}, 
            {5, 6, 7, 8}, 
            {9, 10, 11, 12}, 
            {13, 14, 15, 16}
        };
        int k = 7;

        System.out.println(spiral(matrix)[k-1]);
    }
}