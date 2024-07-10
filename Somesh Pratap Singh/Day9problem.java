package DSA;
public class SpiralMatrix 
{

    public static void printk(int matrix[][], int k) 
    {
        if (matrix == null || matrix.length == 0) {
            System.out.println("The Matrix is empty.");
            return;
        }

        int rows = matrix.length;
        int cols = matrix.length;

        if (k > rows * cols || k < 1) {
            System.out.println("k is out of limit of the matrix.");
            
        }

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        int c = 0;

        System.out.println("Spiral Order of the given Matrix : ");
        while (top <= bottom && left <= right) 
        {
            
            for (int i = left; i <= right; i++) 
            {
                c++;
                System.out.print(matrix[top][i] + " ");
                if (c == k) 
                {
                    System.out.println("\n" + k + "th element: " + matrix[top][i]);
                }
            }
            top++;

            
            for (int i = top; i <= bottom; i++) 
            {
                c++;
                System.out.print(matrix[i][right] + " ");
                if (c == k) 
                {
                    System.out.println("\n" + k + "th element: " + matrix[i][right]);
                }
            }
            right--;

           
            if (top <= bottom) 
            {
                for (int i = right; i >= left; i--) 
                {
                    c++;
                    System.out.print(matrix[bottom][i] + " ");
                    if (c == k) 
                    {
                        System.out.println("\n" + k + "th element: " + matrix[bottom][i]);
                    }
                }
                bottom--;
            }

            
            if (left <= right) 
            {
                for (int i = bottom; i >= top; i--) 
                {
                    c++;
                    System.out.print(matrix[i][left] + " ");
                    if (c == k) 
                    {
                        System.out.println("\n" + k + "th element: " + matrix[i][left]);
                    }
                }
                left++;
            }
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {
        int[][] Arr = 
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };

        int k = 16;
        printk(Arr, k);
    }
}
