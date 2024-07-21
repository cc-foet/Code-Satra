package Array;
public class Candy 
{

    public static int minCandies(int arr[])
    {


        int n = arr.length;
        int candies[] = new int[n];
        for(int i=0;i<n;i++)
        {
            candies[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                candies[i]=Math.max(candies[i],candies[i+1]+1);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=candies[i];
        }
        System.out.println(sum);
        return sum;
    }


    public static void main(String[] args) 
    {
        int arr[] = {3,5,6};
        minCandies(arr);
    }
}


