public class Day_10{

    public static void main(String args[]){
        int arr[]={4,5,7};
        System.out.println("Number of possible binary trees: "+trees(arr));
    }

    public static int trees(int[] arr) {
        return bintrees(arr, 0, arr.length - 1);
    }

    public static int bintrees(int[] arr,int s,int e){
        if(s>e){
            return 1;
        }
        int count=0;
        for(int i=s;i<=e;i++){
            int lc=bintrees(arr,s,i-1);
            int rc=bintrees(arr,i+1,e);
            count+=lc*rc;
        }
        return count;
    }   
}
