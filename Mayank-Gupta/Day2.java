/*Problem: First n elements of array of size n+m is already sorted.Your task
 is to sort remaining m elements in-place*/
// TC-O(mlogm) SC-O(m)
import java.util.*;
class Day2{
    public static void merge(int arr[],int st,int mid,int end){
        int s1=mid-st+1;//size of left array
        int s2=end-mid;//size of right array
        int left[]= new int [s1];
        int right []=new int [s2];
         for (int i=0;i<s1;i++) left[i]=arr[st+i];
         for (int i=0;i<s2;i++) right[i]=arr[mid+1+i];
         int p1=0,p2=0,p3=st;
         while(p1<s1 && p2<s2){
            if (left[p1]<=right[p2]) arr[p3++]=left[p1++];
            else arr[p3++]=right[p2++];
         }
         while (p1<s1) arr[p3++]=left[p1++];
         while (p2<s2) arr[p3++]=right[p2++];
    }
    public static void mergesort(int arr[],int st,int end){
        if (st>=end) return;
        int mid=st+(end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr, mid+1, end);
        merge(arr,st,mid,end);
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
      System.out.println("Enter size of array");
      int s=sc.nextInt();
      int arr[]=new int[s];
      System.out.println("Enter elements");//Provided first n ele are sorted. 
      for (int i=0;i<s;i++) arr[i]=sc.nextInt();
      for (int val:arr) System.out.print(val+" ");
      int n=0;
      while (arr[n]<=arr[n+1]) n++; //n numbers of ele are already sorted 
    int m=s-n;
      mergesort(arr,m-1,s-1);
    System.out.println("\n Array after sorting");
    for (int val:arr) System.out.print(val+" ");
    }
}