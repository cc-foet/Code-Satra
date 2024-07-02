import java.util.*;

public class BubbleSort
  {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of elements in the array:");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) 
        {
            arr[i] = sc.nextInt();
        }

        int Count = bubbleSort(arr);

        System.out.println("Sorted array:");
        for (int i = 0; i < n; i++) 
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println("\nNumber of swaps: " +Count);
    }

    static int bubbleSort(int arr[])
    {
        int Count = 0;
        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
          {
            for (int j = 0; j < n - i - 1; j++)
              {
                if (arr[j] > arr[j + 1]) 
                {
                   
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                  
                    Count++;
                }
            }
        }
        return Count;
    }
              }
