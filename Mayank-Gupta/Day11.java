/*Given an array where all its elements are sorted in increasing order
except two swapped elements, sort it in a linear time. Assume there are
 no duplicates in the array.
 Input: a=[3,8,6,7,5,9,10]   Output: a=[3,5,6,7,8,9,10]*/
 public class Day11 {
    public static void sort(int a[]){
        if (a.length<=1) return ;// corner case
        int x=-1,y=-1;
        for(int i=1;i<a.length;i++){
            if (a[i-1]>a[i] && x==-1 ) {
                x=i-1;
                y=i;
            }
            //If Second Conflict exist
            if (a[i-1]>a[i] && x!=-1) {
                y = i;
            }
        }
        int temp=a[x];
        a[x]=a[y];
        a[y]=temp;
    }
    public static void main(String args[]){
        int a[]={3,8,6,7,5,9,10};
        sort(a);
        for (int val:a){
            System.out.print(val+" ");
        }
    }
}
