public class Day_29 
{ 
    public static void main(String args[]) 
    { 
        int arr[]={8,4,2,1};  
        System.out.println("Number of inversions are : "+getcount(arr,arr.length)); 
    } 

    static int getcount(int arr[], int n) 
    { 
        int count=0,max=0,i;  
        for(i=0;i<n;i++) 
            if(max<arr[i]) 
                max=arr[i];
        int BIT[]=new int[max+1]; 
        for(i=1;i<=max;i++) 
            BIT[i]=0; 
        for(i=n-1;i>=0;i--) 
        { 
            count+=getsum(BIT,arr[i]-1); 
            update(BIT,max,arr[i],1); 
        } 
        return count; 
    } 

    static int getsum(int BITree[], int index) 
    { 
        int sum=0; 
        while(index>0) 
        { 
            sum+=BITree[index]; 
            index-=index&(-index); 
        } 
        return sum; 
    } 

    static void update(int[] BITree, int n, int index, int val) 
    { 
        while(index<=n) 
        { 
            BITree[index]+=val; 
            index+=index&(-index); 
        } 
    } 
}
