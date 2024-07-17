public class Day_5 {
    public static void main(String args[]){
        int ar[]= {2,3,6,7,9};
        int arr[]={1,4,8,10};
        int k=5;
        System.out.println(find(ar,arr,k));
    }

    public static int find(int ar[],int arr[],int k){
        int n,m,a=0,i=0,j=0;
        n=ar.length;
        m=arr.length;
        int merge[]=new int[m+n];
        while(i<n && j<m){
            if(ar[i]<arr[j])
            merge[a++]=ar[i++];
            else
            merge[a++]=arr[j++];
        }
        while(i<n)
        merge[a++]=ar[i++];
        while(j<m)
        merge[a++]=arr[j++];
        return merge[k-1];
    }
}
