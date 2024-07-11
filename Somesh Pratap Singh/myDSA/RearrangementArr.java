package DSA;

public class RearrangemenentArray 
{

    
public static void fixArray(int arr[], int n)
{
    int i, j, temp;
    
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            
            if (arr[j] == i) 
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                break;
            }
        }
    }
 
  
    for(i = 0; i < n; i++)
    {
        
        if (arr[i] != i)
        {
            arr[i] = -1;
        }
    }
 
    
    System.out.println("Array after Rearranging");
    for(i = 0; i < n; i++) 
    {
        System.out.print(arr[i] + " ");
    }
}


public static void main(String[] args)
{
    int n, arr[] = { -1, -1, 6, 1, 9, 
                     3, 2, -1, 4, 8 };
    n = arr.length;
 
    
    fixArray(arr, n);
}
}

