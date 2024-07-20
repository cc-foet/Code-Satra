//? leetcode ques 867
public class Day19 {
    public static void main(String[] args) {
        Day19 day19 = new Day19();

        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        int[][] transposedMatrix = day19.transpose(matrix);

        System.out.println("Original Matrix:");
        printMatrix(matrix);

        System.out.println("\nTransposed Matrix:");
        printMatrix(transposedMatrix);
    }

        public int[][] transpose(int[][] matrix) {
          int rows=matrix.length;
          int cols =matrix[0].length;
          int[][] transposematrix=new int[cols][rows];
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    transposematrix[j][i]=matrix[i][j];
                }
            }
                return transposematrix;
        }
        private static void printMatrix(int[][] matrix) {
            for (int[] row : matrix) {
                for (int element : row) {
                    System.out.print(element + " ");
                }
                System.out.println();
            }
        }
    }
    
