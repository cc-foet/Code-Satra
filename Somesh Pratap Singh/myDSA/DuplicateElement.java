package Array;

public class DuplicateElement {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 2, 6, 7, 8, 9, 10, 3};
        int n = arr.length;
        int c = 0;
       
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++)
             {
                if (arr[i] == arr[j])
                 {
                    System.out.println("Duplicate element: " + arr[i]);
                    c++;
                    break; 
                }
            }
        }

       
        if (c == 0) 
        {
            System.out.println("No duplicate element found");
        } else 
        {
            System.out.println(-1);
        }
    }
}
