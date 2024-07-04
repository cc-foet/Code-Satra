public class Day_2
{
    public static void main(String[] args)
    {
        int n=3;
        int m=3;
        int arr[] = {1,3,6,19,11,16};
        printarray(arr,n,m);
    }
    static void merge(int a[], int l, int m, int r)
    {
        int n1=m-l+1;
        int n2=r-m;
        int i=0,j=0;
        int left[]=new int[n1];
        int right[]=new int[n2];
        for (i=0;i<n1;i++)
            left[i]=a[l+i];
        for (j=0;j<n2;j++)
            right[j] = a[j+m+1];
       i=0;
       j=0; 
       int k=l;
        while(i<n1 && j<n2) 
        {
            if(left[i]<=right[j])
            {
                a[k]=left[i];
                i++;
            }
            else{
                a[k]=right[j];
                j++;
            }
            k++;
        }
        while(i<n1) {
            a[k]=left[i];
            i++;
            k++;
        }
        while(j<n2) {
            a[k]=right[j];
            j++;
            k++;
        }
    }
    static void mergesort(int arr[], int l, int r)
    {
        if(l<r){
            int m=l+(r-l)/2;
            mergesort(arr,l,m);
            mergesort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    static void printarray(int arr[], int n,int m)
    {
        int s=m+n-1;
        mergesort(arr,n,s);
        merge(arr,0,n-1,n+m-1);
        System.out.print("Sorted Array: ");
        for (int i=0;i<n+m;i++)
             System.out.print(arr[i]+" ");
    }
}
