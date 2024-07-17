package Array;
import java.util.*;

public class MinHeap 
{
    public static void main(String[] args) 
    {
        int[][] arr = 
        {
            {1, 3, 5,7},
            {2, 4, 6,8},
            {0, 9, 10,11}
            
        };

        int k = arr.length;
        int n = arr[0].length;

        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        for (int i = 0; i < k; i++) 
        {
            minHeap.offer(new int[]{arr[i][0], i, 0});
        }

        List<Integer> sort = new ArrayList<>();

        while (!minHeap.isEmpty()) {
            int[] curr = minHeap.poll();
            int val = curr[0];
            int array = curr[1];
            int element = curr[2];

            sort.add(val);

            
            if (element + 1 < n)
             {
                minHeap.offer(new int[]{arr[array][element + 1], array, element + 1});
            }
        }

        
        System.out.println("Sorted Output:");
        for (int num : sort) 
        {
            System.out.print(num + " ");
        }
    }
}
