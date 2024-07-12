package Array;

public class FirstandLast {

    public static void main(String[] args) {
        
        int[] arr = {1, 3, 5, 5,8, 5, 67, 5, 125};
        int n = arr.length;
        int x = 5, first = 0, last = n-1;

        for(int i=0;i<n;i++)
        {
            if(arr[first]!=x)
            {
                first++;
            }
            if(arr[last]!=x)
            {
                last--;
            }

            if (first ==last) {
               System.out.println("Element :"+x+" found only once at index "+first);
                break;
                
            }

            if(arr[first]==x && arr[last]==x)
            {
                System.out.println("First Occurrence of:"+x+" is at index :"+first);
                System.out.println("Last Occurrence of:"+x+" is at index :"+last);
                break;
            }

            

        }


    }
    
}
