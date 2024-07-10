package Princy_Ballabh;

public class Day_1{
    public static void main(String args[]){
        int arr[]={64,34,25,12,22,11,90};
        int n=7;
        int newarr[]=bubble_sort(arr,n);
        System.out.print("Sorted Array: ");
        for(int i=0;i<n;i++){
            System.out.print(newarr[i]+" ");
        }
    }

    public static int[] bubble_sort(int arr[],int n){
        int temp,i,j;
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        return arr;
    }
}