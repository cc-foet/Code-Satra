//? leetcode ques 832
public class Day17 {
    public static void main(String[] args) {
        int[][] image = {
            {1, 1, 0},
            {1, 0, 1},
            {0, 0, 0}
        };
        
        System.out.println("Original Image:");
        printImage(image);
        
        int[][] ans = flipAndInvertImage(image);
        
        System.out.println("Flipped and Inverted Image:");
        printImage(ans);
    }

    public static int[][] flipAndInvertImage(int[][] image) {
        int r = image.length;
        int c = image[0].length;
        
        for (int i = 0; i < r; i++) {
            int left = 0; 
            int right = c - 1;
            
            while (left <= right) {
                if (left == right) {
                    image[i][left] = image[i][left] == 0 ? 1 : 0;
                } else {
                    int temp = image[i][left];
                    image[i][left] = image[i][right] == 0 ? 1 : 0;
                    image[i][right] = temp == 0 ? 1 : 0;
                }
                
                left++;
                right--;
            }
        }
        
        return image;
    }
    
    public static void printImage(int[][] image) {
        for (int[] row : image) {
            for (int pixel : row) {
                System.out.print(pixel + " ");
            }
            System.out.println();
        }
    }
}
