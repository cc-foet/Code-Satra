/*Problem: Given two sorted integer arrays, and an integer k. Find the integer at kth position
in final sorted array. */

//TC-O(N+M) SC- O(1)
public class Day5 {
    public static int search(int a[],int b[],int k){
        int p1=0,p2=0,p3=1;
        while (p1 < a.length && p2 < b.length) {
            if (a[p1] < b[p2]) { // if the element of left array is smaller then it is filled in original array
                if (p3==k) return a[p1];
                p3++;
                p1++;
            } else {
                if (p3==k) return b[p2];
                p3++;
                p2++;
            }
        }
while (p1<a.length){
    if (p3==k) return a[p1];
        p3++;
        p1++;
    }
    while (p2<b.length){
        if (p3==k) return b[p2];
            p3++;
            p2++;
        } 
return -999999;//Garbage-value
    }
    public static void main(String[] args) {
        int a[]={2,3,6,7,9};
        int b[]={1,4,8,10};
        int k=5;
        System.out.printf("%d is at %dth position of final sorted array",search(a,b,k),k);
    }   
}
